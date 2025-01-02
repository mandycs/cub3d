/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:47:04 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 11:19:58 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

char	*bfl_strdup(const char *str)
{
	char	*new_str;
	int		counter;

	if (!str)
		return (NULL);
	counter = bfl_strlen(str);
	new_str = (char *)malloc((counter + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[counter] = '\0';
	while (counter-- > 0)
		new_str[counter] = str[counter];
	return (new_str);
}
