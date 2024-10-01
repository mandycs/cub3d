/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_strndup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 01:06:37 by mancorte          #+#    #+#             */
/*   Updated: 2024/09/05 01:07:17 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

char	*bfl_strndup(const char *str, size_t n)
{
	char	*new_str;
	size_t	len;
	size_t	i;

	if (!str)
		return (NULL);
	len = bfl_strlen(str);
	if (len > n)
		len = n;
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}
