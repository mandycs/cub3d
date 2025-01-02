/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_strtrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:47:21 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 11:20:48 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

char	*bfl_strtrim(const char *str, const char *str2)
{
	size_t	start;
	size_t	end;

	if (!str || !str2)
		return (NULL);
	if (!(*str))
		return (bfl_calloc(1, 1));
	start = 0;
	while (bfl_strchr(str2, str[start]))
		start++;
	end = bfl_strlen(str);
	while (bfl_strchr(str2, str[end]))
		end--;
	return (bfl_substr(str, start, end - start + 1));
}
