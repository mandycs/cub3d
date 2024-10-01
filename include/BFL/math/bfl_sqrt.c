/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_sqrt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:38:37 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 11:07:03 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

double	bfl_sqrt(double number)
{
	const int	max_iterations = 10;
	int			iterations;
	double		sqr_root;

	if (number < 0)
		return (-1);
	iterations = -1;
	sqr_root = number;
	while (++iterations < max_iterations)
		sqr_root = sqr_root - (sqr_root * sqr_root - number) / (2 * sqr_root);
	return (sqr_root);
}
