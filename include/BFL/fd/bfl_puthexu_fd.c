/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_puthexu_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:05:11 by ribana-b          #+#    #+#             */
/*   Updated: 2024/06/02 09:42:36 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

static int	bfl_puthex(unsigned long number, int fd, int *bytes, int *success)
{
	static char	*base = "0123456789ABCDEF";

	if (number > 0)
	{
		*bytes = bfl_puthex(number / 16, fd, bytes, success);
		if (*bytes < 0)
			return (-1);
		*success = write(fd, &base[number % 16], 1);
		if (*success < 0)
			return (-1);
	}
	return (*bytes + *success);
}

int	bfl_puthexu_fd(unsigned long number, int fd)
{
	int	bytes_written;
	int	success;

	bytes_written = 0;
	success = 0;
	if (number == 0)
		return (write(fd, "0", 1));
	else
		return (bfl_puthex(number, fd, &bytes_written, &success));
}
