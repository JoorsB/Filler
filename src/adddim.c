/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adddim.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 15:02:11 by jboer          #+#    #+#                */
/*   Updated: 2019/12/14 16:16:28 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	checkxl(t_filler *filler)
{
	int		i;
	int		j;
	int		c;

	i = 0;
	j = 0;
	c = 0;
	while (TP[j] && TP[j][i])
	{
		while (TP[j] && TP[j][i])
		{
			if (TP[j][i] == '*')
				return (c);
			j++;
		}
		c++;
		j = 0;
		i++;
	}
	return (-1);
}

static int	checkxr(t_filler *filler)
{
	int		i;
	int		j;
	int		c;

	i = XDIM - 1;
	j = 0;
	c = 0;
	while (i >= 0)
	{
		while (TP[j] && TP[j][i])
		{
			if (TP[j] && TP[j][i] == '*')
			{
				XR = c;
				return (c);
			}
			j++;
		}
		c++;
		j = 0;
		i--;
	}
	return (-1);
}

static int	checkyu(t_filler *filler)
{
	int		i;
	int		j;
	int		c;

	i = 0;
	j = 0;
	c = 0;
	while (TP[j] && TP[j][i])
	{
		while (TP[j] && TP[j][i])
		{
			if (TP[j] && TP[j][i] == '*')
				return (c);
			i++;
		}
		c++;
		i = 0;
		j++;
	}
	return (-1);
}

static int	checkyd(t_filler *filler)
{
	int		i;
	int		j;
	int		c;

	i = 0;
	j = YDIM - 1;
	c = 0;
	while (j >= 0)
	{
		while (TP[j] && TP[j][i])
		{
			if (TP[j] && TP[j][i] == '*')
				return (c);
			i++;
		}
		c++;
		i = 0;
		j--;
	}
	return (-1);
}

void		adddim(t_filler *filler)
{
	XL = checkxl(filler);
	XR = checkxr(filler);
	YU = checkyu(filler);
	YD = checkyd(filler);
	if (XL == -1 || XR == -1 || YU == -1 || YD == -1)
	{
		exit(2);
	}
}
