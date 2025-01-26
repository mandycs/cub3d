/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:24:04 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/19 14:24:06 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "cub_log.h"

int	log_info(const char *message)
{
	return (cub_log(INFO, message));
}
