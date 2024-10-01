/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:54 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 11:19:48 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

int	bfl_atoi(const char *str)
{
	int	sign;
	int	number;

	if (!str)
		return (0);
	if (!bfl_strncmp(str, "-2147483648", 11))
		return (-2147483648);
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
