/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_atol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:56 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 11:20:54 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

long int	bfl_atol(const char *str)
{
	int			sign;
	long int	number;

	if (!str)
		return (0);
	if (!bfl_strncmp(str, "-9223372036854775808", 20))
		return (-9223372036854775807 - 1);
	sign = 1;
	while (*str == '\n' || *str == '\t' || *str == '\v' || *str == ' '
		|| *str == '\f' || *str == '\r')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + *str - '0';
		str++;
	}
	return (number * sign);
}
