/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_putaddress_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:45:20 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 09:43:42 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

int	bfl_putaddress_fd(unsigned long long ptr, int fd)
{
	int	success;
	int	bytes_written;

	bytes_written = 0;
	success = write(fd, "0x", 2);
	if (success < 0)
		return (-1);
	bytes_written += success;
	success = bfl_puthexl_fd(ptr, fd);
	if (success < 0)
		return (-1);
	bytes_written += success;
	return (bytes_written);
}
