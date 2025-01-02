/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_strmapi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:47:15 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 11:20:43 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

char	*bfl_strmapi(const char *str, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	index;

	if (!str || !f)
		return (NULL);
	new_str = (char *)malloc((bfl_strlen(str) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	index = 0;
	while (str[index])
	{
		new_str[index] = f(index, str[index]);
		index++;
	}
	new_str[index] = '\0';
	return (new_str);
}
