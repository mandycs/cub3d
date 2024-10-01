/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_lcm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:32 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 11:07:01 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

unsigned long	bfl_lcm(size_t number1, size_t number2)
{
	if (number1 == 0 && number2 == 0)
		return (0);
	return (number1 * number2 / bfl_gcd(number1, number2));
}
