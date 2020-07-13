/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 17:05:32 by jboer          #+#    #+#                */
/*   Updated: 2019/02/01 12:03:42 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		check;
	char	c2;

	c2 = (char)c;
	check = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c2)
			check = i;
		i++;
	}
	if (c2 == '\0')
		return ((char *)&s[i]);
	if (check < 0)
		return (NULL);
	else
		return ((char *)&s[check]);
}
