/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_calloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:37 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 11:10:48 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

void	*bfl_calloc(size_t bytes, size_t type_size)
{
	void	*ptr;

	ptr = malloc(bytes * type_size);
	if (!ptr)
		return (NULL);
	bfl_bzero(ptr, bytes * type_size);
	return (ptr);
}
