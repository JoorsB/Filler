/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_delimc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/28 14:59:44 by jboer          #+#    #+#                */
/*   Updated: 2019/01/28 15:01:12 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_delimc(char const *s, char c)
{
	int i;

	i = 0;
	while (*s == c)
	{
		s++;
		i++;
	}
	return (i);
}