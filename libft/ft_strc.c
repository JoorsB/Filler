/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/28 14:55:33 by jboer          #+#    #+#                */
/*   Updated: 2019/02/02 20:38:38 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strc(char const *s, char c)
{
	int check;

	check = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			s++;
			if (*s == c || *s == '\0')
				check++;
		}
	}
	return (check);
}
