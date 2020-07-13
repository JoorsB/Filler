/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 14:07:34 by jboer          #+#    #+#                */
/*   Updated: 2019/02/18 11:46:06 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t len)
{
	size_t i1;
	size_t i2;

	i1 = 0;
	i2 = 0;
	if (needle[i2] == '\0')
		return ((char *)haystack);
	while (haystack[i1] != '\0' && i1 < len)
	{
		while (haystack[i1] == needle[i2] && i1 < len)
		{
			i2++;
			if (needle[i2] == '\0')
			{
				i1 = i1 - i2 + 1;
				return ((char *)&haystack[i1]);
			}
			i1++;
		}
		i1++;
		i1 = i1 - i2;
		i2 = 0;
	}
	return (NULL);
}
