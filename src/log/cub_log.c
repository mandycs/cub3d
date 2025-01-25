/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_log.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:23:57 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/19 14:23:58 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "cub_log.h"

int	cub_log(t_log_level level, const char *message)
{
	if (LOGGING)
	{
		if (level == DEBUG)
			bfl_fprintf(STDOUT, "[DEBUG] %s\n", message);
		else if (level == INFO)
			bfl_fprintf(STDOUT, "[INFO] %s\n", message);
		else if (level == WARNING)
			bfl_fprintf(STDERR, "[WARNING] %s\n", message);
		else if (level == ERROR)
			bfl_fprintf(STDERR, "[ERROR] %s\n", message);
	}
	return (1);
}
