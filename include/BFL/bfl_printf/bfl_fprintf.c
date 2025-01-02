/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_fprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:10 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 12:48:59 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

static void	bfl_print_format(int fd, const char *str, va_list arg,
		t_print *info)
{
	if (*str == '%')
		info->success += bfl_putchar_fd(*str, fd);
	else if (*str == 'c')
		info->success += bfl_putchar_fd(va_arg(arg, int), fd);
	else if (*str == 's')
		info->success += bfl_putstr_fd(va_arg(arg, char *), fd);
	else if (*str == 'd' || *str == 'i')
		info->success += bfl_putnbr_fd(va_arg(arg, int), fd);
	else if (*str == 'u')
		info->success += bfl_putunbr_fd(va_arg(arg, unsigned int), fd);
	else if (*str == 'x')
		info->success += bfl_puthexl_fd(va_arg(arg, unsigned int), fd);
	else if (*str == 'x')
		info->success += bfl_puthexu_fd(va_arg(arg, unsigned int), fd);
	else if (*str == 'p')
		info->success += bfl_putaddress_fd(va_arg(arg, unsigned long), fd);
	info->bytes += info->success;
}

static void	initialise_info(t_print *info)
{
	info->index = -1;
	info->bytes = 0;
	info->success = 0;
}

int	bfl_fprintf(int fd, const char *str, ...)
{
	t_print	info;
	va_list	arg;

	if (fd < 0)
		return (-1);
	va_start(arg, str);
	initialise_info(&info);
	while (str[++info.index])
	{
		if (str[info.index] == '%')
			bfl_print_format(fd, &str[++info.index], arg, &info);
		else
		{
			info.success = write(fd, &str[info.index], 1);
			info.bytes += info.success;
		}
		if (info.success < 0)
			return (-1);
	}
	va_end(arg);
	return (info.bytes);
}
