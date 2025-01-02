/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_ll_destroy_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:14:57 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/14 11:45:24 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

void	bfl_ll_destroy_content(t_ll *linked_list, void *(*del)(void *, size_t),
		size_t	asterisk_amount)
{
	if (!linked_list || !linked_list->content || !del)
		return ;
	del(&linked_list->content, asterisk_amount);
}
