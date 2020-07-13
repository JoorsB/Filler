/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/29 13:58:07 by jboer          #+#    #+#                */
/*   Updated: 2019/12/14 16:16:49 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		fillcuttoken(t_filler *filler, char **new, int j)
{
	int			i;

	i = 0;
	new[j] = (char *)malloc(sizeof(char) * (XDIM - XL - XR + 1));
	if (!new[j])
		exit(2);
	new[j][XDIM - XL - XR] = '\0';
	while (i < (XDIM - XL - XR))
	{
		new[j][i] = TP[j + YU][i + XL];
		i++;
	}
	j++;
	return (j);
}

static void		cuttoken(t_filler *filler)
{
	char		**new;
	char		**buf;
	int			j;

	j = 0;
	new = (char **)malloc(sizeof(char *) * (YDIM - YU - YD + 1));
	if (!new)
		exit(2);
	new[YDIM - YU - YD] = NULL;
	while (j < (YDIM - YU - YD))
		j = fillcuttoken(filler, new, j);
	buf = TP;
	TP = new;
	ft_memdel((void **)buf);
	filler->space = 0;
}

static void		filloop(t_filler *filler)
{
	char		*line;

	line = NULL;
	while (1)
	{
		getpiece(filler);
		cuttoken(filler);
		DIS = -1;
		placepiece(filler);
		if (filler->ybest < 1)
			filler->hittop = 1;
		filler->cheatcount++;
		if (filler->ybest > Y - 4 && filler->xbest < X / 2 - 3)
			filler->hitbot = 1;
		freetoken(filler);
		line = get_new_points(filler);
		YDIM = ft_datoi(&line[6], ' ');
		XDIM = ft_datoi(&line[ft_intlen(YDIM) + 7], ' ');
		ft_memdel((void **)&line);
	}
}

static void		getfirstlines(t_filler *filler)
{
	char		*line;

	line = NULL;
	if (get_next_line(0, &line) && !ft_strncmp(line, "$$$ exec p", 10) &&
	(line[10] == '1' || line[10] == '2'))
		filler->player = line[10];
	else
		exit(2);
	filler->player = (filler->player == '1') ? 'O' : 'X';
	filler->opponent = (filler->player == 'X') ? 'O' : 'X';
	if (line)
		ft_memdel((void **)&line);
	if (get_next_line(0, &line) && !ft_strncmp(line, "Plateau", 7))
	{
		filler->map.y = ft_datoi(&line[8], ' ');
		filler->map.x = ft_datoi(&line[ft_intlen(filler->map.y) + 9], ' ');
	}
	else
		exit(2);
	if (line)
		ft_memdel((void **)&line);
	if (Y > 30)
		filler->cheatcount = -12;
}

int				main(void)
{
	t_filler	filler;
	char		*line;

	ft_bzero(&filler, sizeof(t_filler));
	line = NULL;
	getfirstlines(&filler);
	get_map(&filler);
	getside(&filler);
	filloop(&filler);
	return (0);
}
