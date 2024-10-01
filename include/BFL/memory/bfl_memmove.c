/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_memmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:48 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 11:27:00 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

void	*bfl_memmove(void *ptr, const void *ptr2, size_t bytes)
{
	char	*temp;
	char	*temp2;

	if (!ptr || !ptr2)
		return (NULL);
	temp = (char *)ptr;
	temp2 = (char *)ptr2;
	if (temp > temp2 || temp < (temp2 + bytes))
		while (bytes--)
			temp[bytes] = temp2[bytes];
	else
		bfl_memcpy(ptr, ptr2, bytes);
	return (ptr);
}
