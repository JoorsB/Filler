/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 13:40:01 by jboer          #+#    #+#                */
/*   Updated: 2019/02/01 18:12:19 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fs;
	unsigned int	i;
	int				l;

	i = 0;
	if (s[i])
	{
		l = ft_strlen((char *)s);
		fs = (char *)malloc(l * sizeof(char) + 1);
		if (fs == NULL)
			return (NULL);
		while (s[i])
		{
			fs[i] = f(i, s[i]);
			i++;
		}
		fs[i] = '\0';
		return (fs);
	}
	return (NULL);
}
