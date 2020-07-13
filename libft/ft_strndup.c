/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/08 20:09:01 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/04/02 13:49:03 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t size)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = ft_strnew(size * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (i < size)
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}
