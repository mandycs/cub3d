/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_memcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:44 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 11:25:46 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

int	bfl_memcmp(const void *ptr, const void *ptr2, size_t bytes)
{
	unsigned char	*temp;
	unsigned char	*temp2;

	if (!ptr || !ptr2)
		return (-1);
	temp = (unsigned char *)ptr;
	temp2 = (unsigned char *)ptr2;
	while (bytes--)
	{
		if (*(unsigned char *)temp != *(unsigned char *)temp2)
			return (*temp - *temp2);
		temp++;
		temp2++;
	}
	return (0);
}
