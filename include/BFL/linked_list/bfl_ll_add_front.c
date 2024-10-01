/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_ll_add_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:23:10 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 12:34:27 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

void	bfl_ll_add_front(t_ll **linked_list, t_ll *node)
{
	if (!linked_list || !node)
		return ;
	node->next = *linked_list;
	*linked_list = node;
}
