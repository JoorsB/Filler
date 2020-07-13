/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 15:45:51 by jboer          #+#    #+#                */
/*   Updated: 2019/02/05 23:14:26 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		len;
	char	ch;

	len = ft_strlen(s);
	i = 0;
	ch = (char)c;
	while (len >= 0)
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i++;
		len--;
	}
	return (NULL);
}
