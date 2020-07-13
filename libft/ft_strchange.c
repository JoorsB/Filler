/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchange.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/14 12:37:45 by jboer          #+#    #+#                */
/*   Updated: 2019/03/14 13:25:07 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchange(char *change, char *str)
{
	int i;

	i = 0;
	while (*change)
	{
		str[i] = *change;
		i++;
		change++;
	}
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
