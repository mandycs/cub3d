/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_putendl_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:31:08 by ribana-b          #+#    #+#             */
/*   Updated: 2024/06/02 09:48:06 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

int	bfl_putendl_fd(const char *str, int fd)
{
	int	bytes_written;

	if (!str || fd < 0)
		return (-1);
	bytes_written = write(fd, str, bfl_strlen(str));
	if (bytes_written < 0)
		return (-1);
	bytes_written = write(fd, "\n", 1);
	if (bytes_written < 0)
		return (-1);
	return (bytes_written);
}
