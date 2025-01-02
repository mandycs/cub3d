/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:39 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/02 11:07:43 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

void	free_single_ptr(void *ptr)
{
	char	**temp;

	temp = (char **)ptr;
	free(*temp);
	*temp = NULL;
}

static void	free_double_ptr(void *ptr)
{
	char	***temp;
	size_t	index;

	temp = (char ***)ptr;
	if (!(*temp))
		return ;
	index = 0;
	while ((*temp)[index])
	{
		free_single_ptr(&((*temp)[index]));
		index++;
	}
	free(*temp);
	*temp = NULL;
}

static void	free_triple_ptr(void *ptr)
{
	char	****temp;
	size_t	index;

	temp = (char ****)ptr;
	if (!(*temp))
		return ;
	index = 0;
	while ((*temp)[index])
	{
		free_double_ptr(&((*temp)[index]));
		index++;
	}
	free(*temp);
	*temp = NULL;
}

void	*bfl_free(void *ptr_reference, size_t asterisk_amount)
{
	if (!ptr_reference)
		return (NULL);
	if (asterisk_amount == 1)
		free_single_ptr(ptr_reference);
	else if (asterisk_amount == 2)
		free_double_ptr(ptr_reference);
	else if (asterisk_amount == 3)
		free_triple_ptr(ptr_reference);
	return (NULL);
}
