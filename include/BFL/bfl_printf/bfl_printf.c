/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:14 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 12:48:45 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

static void	bfl_print_format(const char *str, va_list arg, t_print *info)
{
	if (*str == '%')
		info->success += bfl_putchar_fd(*str, 1);
	else if (*str == 'c')
		info->success += bfl_putchar_fd(va_arg(arg, int), 1);
	else if (*str == 's')
		info->success += bfl_putstr_fd(va_arg(arg, char *), 1);
	else if (*str == 'd' || *str == 'i')
		info->success += bfl_putnbr_fd(va_arg(arg, int), 1);
	else if (*str == 'u')
		info->success += bfl_putunbr_fd(va_arg(arg, unsigned int), 1);
	else if (*str == 'x')
		info->success += bfl_puthexl_fd(va_arg(arg, unsigned int), 1);
	else if (*str == 'x')
		info->success += bfl_puthexu_fd(va_arg(arg, unsigned int), 1);
	else if (*str == 'p')
		info->success += bfl_putaddress_fd(va_arg(arg, unsigned long), 1);
	info->bytes += info->success;
}

static void	initialise_info(t_print *info)
{
	info->index = -1;
	info->bytes = 0;
	info->success = 0;
}

int	bfl_printf(const char *str, ...)
{
	t_print	info;
	va_list	arg;

	va_start(arg, str);
	initialise_info(&info);
	while (str[++info.index])
	{
		info.success = 0;
		if (str[info.index] == '%')
			bfl_print_format(&str[++info.index], arg, &info);
		else
		{
			info.success = write(1, &str[info.index], 1);
			info.bytes += info.success;
		}
		if (info.success < 0)
			return (-1);
	}
	va_end(arg);
	return (info.bytes);
}
