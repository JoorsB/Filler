/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_llatoi.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/25 19:05:20 by jboer          #+#    #+#                */
/*   Updated: 2019/07/25 19:09:34 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_atoipm(const char *str, long long neg)
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

long long		ft_llatoi(const char *str)
{
	long long	neg;
	long long	nb;
	int			pm;

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
