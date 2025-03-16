/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:20:22 by mancorte          #+#    #+#             */
/*   Updated: 2025/03/16 19:10:44 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_error(t_cub *cub)
{
	if (cub->error == CUB_LKO)
		exit(CUB_LKO);
	else if (cub->error == CUB_RIP_READ)
		close(cub->fd);
	else if (cub->error == CUB_NO_TEXT)
	{
		close(cub->fd);
		bfl_free(&cub->text, 2);
		bfl_fprintf(STDERR, "Error (No text)\n");
	}
	else if (cub->error == CUB_NO_PATH)
	{
		close(cub->fd);
		ft_free_cub(cub);
	}
	else if (cub->error > CUB_NO_PATH)
		ft_check_error_2(cub);
}

void	ft_check_error_2(t_cub *cub)
{
	if (cub->error == CUB_ERROR_PATH)
	{
		close(cub->fd);
		ft_free_cub(cub);
		ft_paths_close(cub);
	}
	else if (cub->error == CUB_ERROR_COLOR)
	{
		ft_free_cub(cub);
		ft_close_fd(cub);
	}
	else if (cub->error == CUB_ERROR_MAP)
	{
		ft_free_cub(cub);
		ft_close_fd(cub);
	}
	else if (cub->error == CUB_ERROR_MAP_NOT_CLOSED)
	{
		ft_free_cub(cub);
		ft_close_fd(cub);
		bfl_free(&cub->map_dup, 2);
	}
}

void	ft_paths_close(t_cub *cub)
{
	ft_close_fd(cub);
	bfl_fprintf(STDERR, "Error in opening file");
}

void	ft_close_fd(t_cub *cub)
{
	close(cub->fd_no);
	close(cub->fd_so);
	close(cub->fd_we);
	close(cub->fd_ea);
	close(cub->fd);
}
