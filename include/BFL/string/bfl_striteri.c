/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_striteri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:47:05 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 12:51:07 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

void	bfl_striteri(char *str, void (*f)(unsigned int, char *))
{
	unsigned int	counter;

	if (!str || !f)
		return ;
	counter = 0;
	while (str[counter])
	{
		f(counter, str + counter);
		counter++;
	}
}
