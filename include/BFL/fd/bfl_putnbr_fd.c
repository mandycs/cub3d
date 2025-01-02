/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_putnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:02:36 by ribana-b          #+#    #+#             */
/*   Updated: 2024/06/02 10:53:38 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

static int	bfl_putnbr(int number, int fd, int *bytes, int *success)
{
	static char	*base = "0123456789";

	if (number > 0)
	{
		*bytes = bfl_putnbr(number / 10, fd, bytes, success);
		if (*bytes < 0)
			return (-1);
		*success = write(fd, &base[number % 10], 1);
		if (*success < 0)
			return (-1);
	}
	return (*bytes + *success);
}

int	bfl_putnbr_fd(int number, int fd)
{
	int		success;
	int		bytes_written;

	if (fd < 0)
		return (-1);
	success = 0;
	bytes_written = 0;
	if (number == 0)
		return (write(fd, "0", 1));
	else if (number == -2147483648)
		return (write(fd, "-2147483648", 11));
	else if (number < 0)
	{
		bytes_written = write(fd, "-", 1);
		if (bytes_written < 0)
			return (-1);
		number *= -1;
	}
	return (bfl_putnbr(number, fd, &bytes_written, &success));
}
