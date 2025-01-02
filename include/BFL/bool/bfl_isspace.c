/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_isspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:53:14 by mancorte          #+#    #+#             */
/*   Updated: 2024/08/27 11:20:15 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	bfl_isspace(int character)
{
	return (character == ' ' || character == '\t' || character == '\n'
		|| character == '\v' || character == '\f' || character == '\r');
}
