/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 16:20:04 by jboer          #+#    #+#                */
/*   Updated: 2019/01/31 17:39:26 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	int				*p;
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	ch;

	d = (char unsigned *)dst;
	s = (unsigned char *)src;
	p = NULL;
	i = 0;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (s[i] == ch)
		{
			d[i] = s[i];
			return (&d[i + 1]);
		}
		d[i] = s[i];
		i++;
	}
	return ((void *)p);
}
