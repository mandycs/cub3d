/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_strbuild.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:33:05 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/05 11:12:07 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

char	*bfl_strbuild(int string_amount, char *str, ...)
{
	char	*result;
	char	*temp;
	va_list	args;
	int		error_flag;

	va_start(args, str);
	error_flag = 0;
	result = bfl_strjoin(str, va_arg(args, char *));
	if (!result)
		error_flag = 1;
	while (--string_amount > 1 && !error_flag)
	{
		temp = bfl_strdup(result);
		free(result);
		if (!temp)
			error_flag = 1;
		result = bfl_strjoin(temp, va_arg(args, char *));
		free(temp);
		if (!result)
			error_flag = 1;
	}
	va_end(args);
	if (error_flag)
		return (NULL);
	return (result);
}
