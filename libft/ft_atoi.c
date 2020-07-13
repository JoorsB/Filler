/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 13:00:37 by jboer          #+#    #+#                */
/*   Updated: 2019/02/03 21:36:54 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoipm(const char *str, int neg)
{
	while (*str == '+' || *str == '-')
	{
		if (neg == -1)
			return (0);
		str++;
		if (*str == '+')
			return (0);
	}
	return (1);
}

int			ft_atoi(const char *str)
{
	int neg;
	int nb;
	int pm;

	neg = 1;
	nb = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\r' ||
	*str == '\f' || *str == '\v')
		str++;
	if (*str == '-')
		neg = -1;
	if (neg == -1)
		str++;
	pm = ft_atoipm(str, neg);
	if (pm == 0)
		return (0);
	if (*str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - 48);
		str++;
	}
	return (nb * neg);
}
