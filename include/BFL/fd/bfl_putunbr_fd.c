/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_putunbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:44:34 by ribana-b          #+#    #+#             */
/*   Updated: 2024/06/02 10:54:05 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

static int	bfl_putunbr(unsigned int number, int fd, int *bytes, int *success)
{
	static char	*base = "0123456789";

	if (number > 0)
	{
		*bytes = bfl_putunbr(number / 10, fd, bytes, success);
		if (*bytes < 0)
			return (-1);
		*success = bfl_putchar_fd(base[number % 10], fd);
		if (*success < 0)
			return (-1);
	}
	return (*bytes + *success);
}

int	bfl_putunbr_fd(unsigned int number, int fd)
{
	int	bytes_written;
	int	success;

	bytes_written = 0;
	success = 0;
	if (number == 0)
		return (write(fd, "0", 1));
	else
		return (bfl_putunbr(number, fd, &bytes_written, &success));
}
