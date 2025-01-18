#include "utils.h"

bool	cub_create(t_info *info)
{
	info->mlx = mlx_init(PIXEL_SIZE * 16 * RESIZE, PIXEL_SIZE * 9 * RESIZE,
			"Cub3D", false);
	if (!info->mlx)
		return (false);
	log_info("Window initialized");
	if (!create_player(&info->player))
		return (!log_error("Couldn't create player"));
	if (!create_map(&info->map))
		return (!log_error("Couldn't create map"));
	if (!create_textures(info))
		return (!log_error("Couldn't create textures"));
	if (!create_screen(&info->screen, info->mlx))
		return (!log_error("Couldn't create screen"));
	return (true);
}

void	cub_close_window(mlx_t *mlx)
{
	log_info("Window closed");
	mlx_close_window(mlx);
}

void	cub_destroy(t_info *info)
{
	destroy_map(&info->map);
	destroy_textures(info);
	mlx_terminate(info->mlx);
	log_info("Resources destroyed");
}
