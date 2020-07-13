/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   placepiece.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/15 15:17:25 by jboer          #+#    #+#                */
/*   Updated: 2019/12/14 16:20:27 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	checktwo(t_filler *filler, int i, int j, int c)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (TP[y])
	{
		while (TP[y][x])
		{
			if (TP[y][x] == '*' && MD[j + y][i + x] == PLAYER)
				c++;
			if (c > 1)
				return (c);
			if (TP[y][x] == '*' && MD[j + y][i + x] == OP)
				return (-1);
			x++;
		}
		x = 0;
		y++;
	}
	return (c);
}

static int	checkplace(t_filler *filler, int i, int j)
{
	int		c;

	c = 0;
	c = checktwo(filler, i, j, c);
	if (c <= 0 || c > 1)
		return (-1);
	if (j + YDIM - YU - YD > Y)
		return (-1);
	return (1);
}

static int	checkdis(t_filler *filler, int i, int j)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (MD[y])
	{
		while (MD[y][x])
		{
			if (MD[y][x] == OP)
			{
				if ((ft_powerof(y - j, 2) + ft_powerof(x - i, 2)) < DIS
				|| DIS == -1)
				{
					DIS = ft_powerof(y - j, 2) + ft_powerof(x - i, 2);
					return (1);
				}
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (-1);
}

static void	checkbest(t_filler *filler, int i, int j)
{
	if (Y > 1 && (filler->cheatcount < 50 || (filler->cheatcount
	< 100 && Y > 50)))
	{
		if (checkdisthree(filler, i, j) == 1)
		{
			filler->xbest = i;
			filler->ybest = j;
		}
	}
	else if (Y < 20 || (filler->cheatcount >= 45))
	{
		if (checkdis(filler, i - XDIM / 2, j - YDIM / 2) == 1)
		{
			filler->xbest = i;
			filler->ybest = j;
		}
	}
}

void		placepiece(t_filler *filler)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (MD[j + YDIM - YU - YD - 1])
	{
		while (MD[j][i + XDIM - XL - XR - 1])
		{
			if (checkplace(filler, i, j) == 1)
			{
				filler->space = 1;
				checkbest(filler, i, j);
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (filler->space == 0)
		exit(2);
	ft_putnbr(filler->ybest - YU);
	ft_putchar(' ');
	ft_putnbr(filler->xbest - XL);
	ft_putchar('\n');
}
