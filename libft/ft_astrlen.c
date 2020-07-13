/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_astrlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/09 22:34:12 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/03/09 22:37:13 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_astrlen(char **ptr)
{
	size_t i;

	i = 0;
	while ((void *)ptr[i] != NULL)
		i++;
	return (i);
}
