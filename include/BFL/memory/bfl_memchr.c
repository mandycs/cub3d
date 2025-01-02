/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_memchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:42 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 11:25:30 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

void	*bfl_memchr(const void *ptr, int value, size_t bytes)
{
	unsigned char	*temp;

	if (!ptr)
		return (NULL);
	temp = (unsigned char *)ptr;
	while (bytes--)
	{
		if (*temp == (unsigned char)value)
			return ((void *)temp);
		temp++;
	}
	return (NULL);
}
