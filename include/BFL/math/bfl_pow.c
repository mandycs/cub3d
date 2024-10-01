/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_pow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:33 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 11:07:02 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

double	bfl_pow(double number, int exponent)
{
	double	temp;

	temp = number;
	if (exponent == 0)
		return (1);
	else if (exponent > 0)
		while (exponent-- > 1)
			number *= temp;
	else
	{
		while (exponent++ < -1)
			number *= temp;
		number = 1 / number;
	}
	return (number);
}
