/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/26 16:13:16 by jboer          #+#    #+#                */
/*   Updated: 2019/02/01 11:20:05 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len;
	size_t i2;

	len = 0;
	i2 = 0;
	while (dst[len] && len < size)
		len++;
	i = len;
	while (src[i2] && len + 1 < size)
	{
		dst[len] = src[i2];
		len++;
		i2++;
	}
	if (i < len)
		dst[len] = '\0';
	i = ft_strlen(src) + i;
	return (i);
}
