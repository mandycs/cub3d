/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_ll_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:18:10 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 13:19:17 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

size_t	bfl_ll_size(t_ll *linked_list)
{
	size_t	counter;

	if (!linked_list)
		return (0);
	counter = 0;
	while (linked_list)
	{
		linked_list = linked_list->next;
		++counter;
	}
	return (counter);
}
