/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbrlong.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 13:32:19 by jboer          #+#    #+#                */
/*   Updated: 2019/06/26 13:55:04 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbrlong(long long int nb)
{
	long long int b;
	long long int e;

	if (nb == -9223372036854775807)
	{
		ft_putstr("-9223372036854775807");
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
	{
		e = nb % (long)10;
		b = nb / (long)10;
		if (b != 0)
		{
			ft_putnbr(b);
		}
		ft_putchar(e + '0');
	}
}
