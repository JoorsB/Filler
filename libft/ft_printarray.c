/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printarray.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 17:51:51 by jboer          #+#    #+#                */
/*   Updated: 2019/03/09 13:30:43 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printarray(char **ar)
{
	int i;

	i = 0;
	while (ar[i])
	{
		ft_putstr(ar[i]);
		ft_putchar('\n');
		i++;
	}
}
