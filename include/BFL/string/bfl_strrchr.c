/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_strrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:47:19 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 11:20:47 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

char	*bfl_strrchr(const char *str, int character)
{
	size_t	length;

	if (!str)
		return (NULL);
	if (!(*str) && character == '\0')
		return ((char *)str);
	length = bfl_strlen(str) + 1;
	while (length-- > 0)
		if ((unsigned char)str[length] == (unsigned char)character)
			return ((char *)str + length);
	return (NULL);
}
