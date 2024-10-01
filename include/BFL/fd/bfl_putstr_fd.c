/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_putstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:03:52 by ribana-b          #+#    #+#             */
/*   Updated: 2024/06/02 09:47:02 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

int	bfl_putstr_fd(const char *str, int fd)
{
	int	bytes_written;
	int	success;

	if (fd < 0)
		return (-1);
	if (!str)
	{
		success = write(fd, "(null)", 6);
		if (success < 0)
			return (-1);
		return (success);
	}
	success = write(fd, str, bfl_strlen(str));
	if (success < 0)
		return (-1);
	bytes_written = success;
	return (bytes_written);
}
