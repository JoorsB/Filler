/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/26 16:13:02 by jboer          #+#    #+#                */
/*   Updated: 2019/01/31 22:45:42 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	while (*s1)
	{
		s1++;
		i++;
	}
	while (*s2 && n > 0)
	{
		*s1 = *s2;
		s1++;
		s2++;
		n--;
		i++;
	}
	*s1 = '\0';
	s1 = s1 - i;
	return (s1);
}
