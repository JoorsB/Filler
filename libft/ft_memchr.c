/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 13:12:11 by jboer          #+#    #+#                */
/*   Updated: 2019/01/31 17:09:50 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			check;
	char unsigned	t;
	unsigned char	*str;

	check = 0;
	str = (unsigned char *)s;
	t = (unsigned char)c;
	while (check < n)
	{
		if (*str == t)
			return ((void *)str);
		str++;
		check++;
	}
	return (NULL);
}
