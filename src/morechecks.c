/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   morechecks.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 22:51:30 by jboer          #+#    #+#                */
/*   Updated: 2019/12/14 16:16:25 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		moremore(t_filler *filler, int i, int j)
{
	if (ft_powerof(0 - j, 2) + ft_powerof(filler->side - i, 2)
	< DIS || DIS == -1)
	{
		DIS = ft_powerof(0 - j, 2) + ft_powerof(filler->side - i, 2);
		return (1);
	}
	return (2);
}

int				morechecks(t_filler *filler, int i, int j)
{
	if (Y > 50 && filler->cheatcount < 60)
	{
		if (ft_powerof(Y - j, 2) + ft_powerof(filler->side - i, 2)
		< DIS || DIS == -1)
		{
			DIS = ft_powerof(Y - j, 2) +
			ft_powerof(filler->side - i, 2);
			return (1);
		}
	}
	else if (filler->cheatcount < 80)
	{
		if (ft_powerof(Y / 2 - j, 2) + ft_powerof(filler->side - i, 2)
		< DIS || DIS == -1)
		{
			DIS = ft_powerof(Y / 2 - j, 2) + ft_powerof(filler->side - i, 2);
			return (1);
		}
	}
	else
	{
		if (moremore(filler, i, j) == 1)
			return (1);
	}
	return (2);
}

void			freetoken(t_filler *filler)
{
	int			i;

	i = 0;
	while (i < (YDIM - YU - YD))
	{
		ft_memdel((void **)&TP[i]);
		i++;
	}
}
