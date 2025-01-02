/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_strlcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:47:10 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 11:19:59 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

size_t	bfl_strlcat(char *str, const char *str2, size_t bytes)
{
	size_t	index;
	size_t	index2;

	if (!str || !str2)
		return (0);
	index = bfl_strlen(str);
	if (index >= bytes)
		return (bfl_strlen(str2) + bytes);
	index2 = 0;
	while (str2[index2] && (index + index2) < (bytes - 1))
	{
		str[index + index2] = str2[index2];
		index2++;
	}
	str[index + index2] = '\0';
	return (index + index2);
}
