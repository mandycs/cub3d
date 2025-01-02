/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:47:07 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 11:19:59 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

char	*bfl_strjoin(const char *str, const char *str2)
{
	char	*new_str;
	int		index;
	int		index2;

	index = bfl_strlen(str);
	index2 = bfl_strlen(str2);
	new_str = (char *)malloc((index + index2 + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[index + index2] = '\0';
	while (index2--)
		new_str[index + index2] = str2[index2];
	while (index--)
		new_str[index] = str[index];
	return (new_str);
}
