/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_bzero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:36 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 12:51:38 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

void	bfl_bzero(void *ptr, size_t bytes)
{
	char	*temp;

	if (!ptr)
		return ;
	temp = ptr;
	while (bytes--)
		temp[bytes] = 0;
}
