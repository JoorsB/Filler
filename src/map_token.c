/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_token.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/05 14:33:44 by jboer          #+#    #+#                */
/*   Updated: 2019/12/14 16:15:38 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			createtokenpiece(t_filler *filler)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	TP = (char **)malloc(sizeof(char *) * (filler->token.ydim + 1));
	if (!TP)
		exit(2);
	TP[YDIM] = NULL;
	while (i < filler->token.ydim)
	{
		TP[i] = ft_memalloc(sizeof(char) * (filler->token.xdim + 1));
		if (!TP[i])
			exit(2);
		while (j < filler->token.xdim)
		{
			TP[i][j] = '.';
			j++;
		}
		TP[i][j] = '\0';
		j = 0;
		i++;
	}
}

void			getpiece(t_filler *filler)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	line = NULL;
	j = 0;
	createtokenpiece(filler);
	while (j < YDIM && get_next_line(0, &line))
	{
		while (line[i])
		{
			if (line[i] == '*')
				TP[j][i] = '*';
			i++;
		}
		i = 0;
		j++;
		ft_memdel((void **)&line);
	}
	if (line)
		ft_memdel((void **)&line);
	adddim(filler);
}

static void		get_start_points(t_filler *filler)
{
	char		*line;
	int			c;
	int			i;

	line = NULL;
	c = 0;
	i = 0;
	while (get_next_line(0, &line) && ft_strncmp(line, "Piece", 5))
	{
		if (!ft_strncmp(line, "000", 3))
			c = 1;
		if (ft_charindex(line, 'X') >= 0)
			MD[i][ft_charindex(line, 'X') - 4] = 'X';
		if (ft_charindex(line, 'O') >= 0)
			MD[i][ft_charindex(line, 'O') - 4] = 'O';
		ft_memdel((void **)&line);
		if (c)
			i++;
	}
	YDIM = ft_datoi(&line[6], ' ');
	XDIM = ft_datoi(&line[ft_intlen(YDIM) + 7], ' ');
	ft_memdel((void **)&line);
}

void			get_map(t_filler *filler)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	MD = (char **)malloc(sizeof(char *) * (Y + 1));
	if (!MD)
		exit(2);
	MD[Y] = NULL;
	while (i < Y)
	{
		MD[i] = ft_memalloc(sizeof(char) * (X + 1));
		if (MD[i] == NULL)
			exit(2);
		while (j < X)
		{
			MD[i][j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
	get_start_points(filler);
}
