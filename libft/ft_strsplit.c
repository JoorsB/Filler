/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 18:47:13 by jboer          #+#    #+#                */
/*   Updated: 2019/02/04 12:23:32 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_horarr(char const *s, char c, int i, char **split)
{
	int j;

	j = 0;
	while (*s != c && *s)
	{
		split[i][j] = *s;
		j++;
		s++;
	}
	split[i][j] = '\0';
	return (s);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		i;
	int		ch;

	i = 0;
	ch = ft_strc(s, c) + 1;
	split = (char**)malloc(sizeof(char*) * ch);
	if (split == NULL)
		return (NULL);
	while (ch > i + 1)
	{
		while (ft_delimc(s, c) > 0)
			s++;
		split[i] = (char*)malloc(sizeof(char) * (ft_charc(s, c) + 1));
		if (split[i] == NULL)
			return (NULL);
		s = ft_horarr(s, c, i, split);
		i++;
	}
	split[i] = NULL;
	return (split);
}
