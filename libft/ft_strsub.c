/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 16:26:23 by jboer          #+#    #+#                */
/*   Updated: 2019/02/27 12:27:20 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*sstr;

	i = 0;
	sstr = (char *)malloc(sizeof(char) * len + 1);
	if (sstr == NULL)
		return (NULL);
	while (len != 0)
	{
		sstr[i] = s[start];
		start++;
		i++;
		len--;
	}
	sstr[i] = '\0';
	return (sstr);
}
