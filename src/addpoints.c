/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   addpoints.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 16:16:06 by jboer          #+#    #+#                */
/*   Updated: 2019/12/14 16:25:35 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		get_point(t_filler *filler, char *line, int j)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] == OP)
		{
			MD[j][i - 4] = OP;
		}
		if (line[i] == PLAYER)
			MD[j][i - 4] = PLAYER;
		i++;
	}
}

char			*get_new_points(t_filler *filler)
{
	int			j;
	char		*line;

	j = 0;
	line = NULL;
	if (get_next_line(0, &line) && !ft_strncmp(line, "Plateau", 7))
	{
		ft_memdel((void **)&line);
		while (get_next_line(0, &line) && ft_strncmp(line, "000", 3))
		{
			ft_memdel((void **)&line);
		}
		while (j < Y)
		{
			get_point(filler, line, j);
			j++;
			ft_memdel((void **)&line);
			if (!get_next_line(0, &line))
				exit(2);
		}
	}
	else
		exit(2);
	return (line);
}

int				checkdisthree(t_filler *filler, int i, int j)
{
	if (filler->hittop == 0 && filler->cheatcount < 28
	&& (ft_charc(MD[1], OP) + ft_charc(MD[0], OP)) > 14)
	{
		if (ft_powerof(0 - j, 2) + ft_powerof(X / 2 + 4 - i, 2)
		< DIS || DIS == -1)
		{
			DIS = ft_powerof(0 - j, 2) + ft_powerof(X / 2 + 4 - i, 2);
			return (1);
		}
	}
	else if (Y > 20 && (filler->hitbot == 0 &&
	ft_charc(MD[Y - 7], OP) > 0))
	{
		if (ft_powerof(Y - j, 2) +
		ft_powerof(X / 2 - 3 - i, 2) < DIS || DIS == -1)
		{
			DIS = ft_powerof(Y - j, 2) + ft_powerof(X / 2 - 3 - i, 2);
			return (1);
		}
	}
	else if (morechecks(filler, i, j) == 1)
		return (1);
	return (2);
}

void			getside(t_filler *filler)
{
	int			x;
	int			y;

	y = 0;
	x = 0;
	while (MD[y])
	{
		while (MD[y][x])
		{
			if (MD[y][x] == PLAYER)
			{
				if (x > X / 2)
					filler->side = 5;
				else
					filler->side = X - 5;
			}
			x++;
		}
		x = 0;
		y++;
	}
}
