/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 14:48:53 by jboer          #+#    #+#                */
/*   Updated: 2019/02/02 20:29:04 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_endi(char const *s)
{
	size_t c;
	size_t i;

	i = 0;
	c = 0;
	while (*s)
	{
		while (*s == ' ' || *s == '\t' || *s == '\n')
		{
			c++;
			s++;
			i++;
			if (*s == '\0')
				return ((int)i - c);
		}
		c = 0;
		i++;
		s++;
	}
	return ((int)i);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		c;
	int		b;

	b = 0;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
	}
	c = ft_endi(s) - i;
	if (c < 0)
		c = 0;
	str = (char *)malloc(sizeof(char) * (c + 1));
	if (str == NULL)
		return (NULL);
	while (b < c)
	{
		str[b] = s[i];
		b++;
		i++;
	}
	str[b] = '\0';
	return (str);
}
