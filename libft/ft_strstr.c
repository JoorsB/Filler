/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 11:07:37 by jboer          #+#    #+#                */
/*   Updated: 2019/02/27 12:04:00 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *haystack, char const *needle)
{
	int i1;
	int i2;

	i1 = 0;
	i2 = 0;
	if (needle[i2] == '\0')
		return ((char *)haystack);
	while (haystack[i1])
	{
		while (haystack[i1] == needle[i2])
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
