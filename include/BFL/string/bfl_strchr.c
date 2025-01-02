/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_strchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:47:02 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 11:19:57 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

char	*bfl_strchr(const char *str, int character)
{
	size_t	counter;

	if (!str)
		return (NULL);
	counter = 0;
	while (str[counter])
	{
		if ((unsigned char)str[counter] == (unsigned char)character)
			return ((char *)str + counter);
		counter++;
	}
	if ((unsigned char)character == '\0')
		return ((char *)str + counter);
	return (NULL);
}
