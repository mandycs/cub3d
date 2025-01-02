/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_ll_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:25:58 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 12:36:42 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

void	bfl_ll_add_back(t_ll **linked_list, t_ll *node)
{
	t_ll	*temp;

	if (!linked_list || !(*linked_list) || !node)
		return ;
	temp = *linked_list;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}
