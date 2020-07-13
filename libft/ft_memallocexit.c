/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memallocexit.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 14:46:46 by jboer          #+#    #+#                */
/*   Updated: 2019/11/19 14:48:31 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memallocexit(size_t size)
{
	void *a;

	a = malloc(size);
	if (a == NULL)
		exit(2);
	ft_memset(a, 0, size);
	return (a);
}
