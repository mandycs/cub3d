/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_strcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:29:59 by mancorte          #+#    #+#             */
/*   Updated: 2024/08/27 10:54:14 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	bfl_strcmp(const char *str, const char *str2)
{
	int	index;

	if (!str || !str2)
		return (-1);
	index = 0;
	while (str[index] || str2[index])
	{
		if (str[index] != str2[index])
			return ((unsigned char)str[index] - (unsigned char)str2[index]);
		index++;
	}
	return (0);
}
