/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printarray_fd.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/09 15:30:34 by jboer          #+#    #+#                */
/*   Updated: 2019/08/09 15:31:50 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printarray_fd(char **ar, int fd)
{
	int i;

	i = 0;
	while (ar[i])
	{
		ft_putstr_fd(ar[i], fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
}
