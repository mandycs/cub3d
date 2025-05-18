/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:20:22 by mancorte          #+#    #+#             */
/*   Updated: 2025/05/18 02:03:46 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_error(t_cub *cub)
{
	if (cub->error == CUB_LKO)
		exit(CUB_LKO);
	else if (cub->error == CUB_RIP_READ)
	{
		if (cub->fd > 0)
			close(cub->fd);
	}
	else if (cub->error == CUB_NO_TEXT)
	{
		close(cub->fd);
		bfl_free(&cub->text, 2);
		bfl_fprintf(STDERR, "Error (No text)\n");
	}
	else if (cub->error == CUB_NO_PATH)
	{
		bfl_fprintf(STDERR, "Error, invalid format color/path texture\n");
		close(cub->fd);
		ft_free_cub(cub);
	}
	else if (cub->error > CUB_NO_PATH)
		ft_check_error_2(cub);
}

void	ft_check_error_2(t_cub *cub)
{
	if (cub->error >= CUB_ERROR_PERMISSION_A
		&& cub->error <= CUB_ERROR_PERMISSION_D)
		ft_close_fd(cub);
	else if (cub->error == CUB_ERROR_PATH)
		ft_paths_close(cub);
	else if (cub->error == CUB_ERROR_COLOR)
		ft_close_fd(cub);
	else if (cub->error == CUB_ERROR_MAP)
		ft_close_fd(cub);
	else if (cub->error == CUB_ERROR_MAP_NOT_CLOSED)
	{
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
	if (cub->fd_no >= 0)
		close(cub->fd_no);
	if (cub->fd_so >= 0)
		close(cub->fd_so);
	if (cub->fd_we >= 0)
		close(cub->fd_we);
	if (cub->fd_ea >= 0)
		close(cub->fd_ea);
	if (cub->fd >= 0)
		close(cub->fd);
	ft_free_cub(cub);
}
