/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 14:24:48 by jboer          #+#    #+#                */
/*   Updated: 2019/04/02 12:43:07 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sstr;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	sstr = ft_strnew(ft_strlen((char *)s2) + ft_strlen((char *)s1));
	if (sstr == NULL)
		return (NULL);
	while (*s1)
	{
		sstr[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		sstr[i] = *s2;
		s2++;
		i++;
	}
	return (sstr);
}
