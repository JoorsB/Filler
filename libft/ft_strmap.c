/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 17:31:54 by jboer          #+#    #+#                */
/*   Updated: 2019/02/01 18:09:31 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fs;
	int		i;
	int		l;

	i = 0;
	if (s[i])
	{
		l = ft_strlen((char *)s);
		fs = (char *)malloc(l * sizeof(char) + 1);
		if (fs == NULL)
			return (NULL);
		while (s[i])
		{
			fs[i] = f(s[i]);
			i++;
		}
		fs[i] = '\0';
		return (fs);
	}
	return (NULL);
}
