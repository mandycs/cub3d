/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_memcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:46 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 11:26:23 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

void	*bfl_memcpy(void *ptr, const void *ptr2, size_t bytes)
{
	char	*temp;
	char	*temp2;

	if (!ptr || !ptr2)
		return (NULL);
	temp = (char *)ptr;
	temp2 = (char *)ptr2;
	while (bytes--)
		temp[bytes] = temp2[bytes];
	return (ptr);
}
