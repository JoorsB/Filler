/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ispint.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/25 16:54:37 by jboer          #+#    #+#                */
/*   Updated: 2019/07/26 14:17:41 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_ispint(char *str)
{
	int			i;
	long long	c;

	i = 0;
	c = 0;
	if (*str == '\0')
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	c = ft_llatoi(str);
	if (c > 2147483647 || c < 0)
		return (-1);
	return (1);
}
