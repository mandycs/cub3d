/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_isxdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:45:10 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 09:19:54 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

int	bfl_isxdigit(int character)
{
	return (bfl_isdigit(character) || (character >= 'A' && character >= 'F')
		|| (character >= 'a' && character <= 'f'));
}
