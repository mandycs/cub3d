/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:23:59 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/19 14:24:02 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "cub_log.h"

int	log_error(const char *message)
{
	return (cub_log(ERROR, message));
}
