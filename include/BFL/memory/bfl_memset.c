/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_memset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:49 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 12:52:29 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

void	bfl_memset(void *ptr, int value, size_t bytes)
{
	char	*temp;

	if (!ptr)
		return ;
	temp = ptr;
	while (bytes-- > 0)
		temp[bytes] = value;
}
