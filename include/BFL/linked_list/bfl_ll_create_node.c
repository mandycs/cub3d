/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_ll_create_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:25 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 12:30:03 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

static void	bfl_ll_initialise(t_ll **linked_list)
{
	if (!linked_list || !(*linked_list))
		return ;
	(*linked_list)->content = NULL;
	(*linked_list)->next = NULL;
	return ;
}

t_ll	*bfl_ll_create_node(void)
{
	t_ll	*linked_list;

	linked_list = malloc(sizeof(t_ll));
	if (!linked_list)
		return (NULL);
	bfl_ll_initialise(&linked_list);
	return (linked_list);
}
