/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42.sg>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:03:21 by akaung            #+#    #+#             */
/*   Updated: 2026/03/11 16:03:21 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

static int	atoi_with_overflow(const char *str, int i, int sign)
{
	long long	result;
	int			digit;

	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - '0';
		if (sign == 1 && result > (INT_MAX - digit) / 10)
			return (INT_MAX);
		if (sign == -1 && result > (((long long)INT_MAX + 1) - digit) / 10)
			return (INT_MIN);
		result = (result * 10) + digit;
		i++;
	}
	return ((int)(result * sign));
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return (atoi_with_overflow(str, i, sign));
}
