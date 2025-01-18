// Single file program to facilitate the development, I'll refactor it later

/**
 * TODO:
 *
 * - Reimplement wall collision when moving
 * - Implement textures
 * - Have a limit distance rendering
 * - Make logs to accept va_args or create something like sprintf
 * to allow giving more information
 * - Reimplement the minimap to scale according to the size of the screen
 *
 * NOTE:
 * Don't activate logging while outside of the map, because it will lag due
 * to printing error
 *
 * MANDATORY:
 * - Parse the map
 *   - Check valid chars (01NSWE)
 *   - Check map closed
 *   - Allow multiple lines between parameters except for the map
 *   - Allow any order, except for the map which has to be at the end
 * - Different wall textures depending on the side
 * - Camera rotation with Left/Right Arrows (DONE)
 * - Move with WASD (DONE)
 * - Press ESC to close the window (DONE)
 * - Closing the window terminates the program (DONE)
 *
 * BONUS:
 * - Wall collisions
 * - A minimap system (DONE)
 * - Doors that can open and close
 * - Animated sprites
 * - Camera rotation with mouse
 */

#include "cub_log.h"
#include "cub3d.h"

// Hardcoded map for testing
static const char *smap[] = {
	"              1111111",
	"111111111101011000001",
	"100000000010100000001",
	"1000000000010000N0001",
	"111000000100000000001",
	"  1010101111111111111",
	"  100101             ",
	"11100001             ",
	"10000001             ",
	"11111111             ",
};

// Cub
bool		cub_create(t_info *info);
void		cub_close_window(mlx_t *mlx);
void		cub_destroy(t_info *info);

// Hooks
void		hook_control_keys(void *param);
void		hook_option_key(mlx_key_data_t keydata, void *param);
void		hook_control_mouse(mouse_key_t button, action_t action,
				modifier_key_t mods, void *param);
void		hook_loader(t_info *info);

// Controls
void		move_forward(t_info *info);
void		move_left(t_info *info);
void		move_right(t_info *info);
void		move_backward(t_info *info);
void		rotate_left(t_info *info);
void		rotate_right(t_info *info);

// Player
bool		create_player(t_player *player);
t_v2		get_player_position(void);

// Map
bool		create_map(t_map *map);
bool		create_map_data(t_map *map);
void		destroy_map(t_map *map);

// MLX Utils
void		clear_background(void *param);
void		swap_buffers(void *param);

// Utils
void		update(void *param);

int	main(int argc, char **argv)
{
	static t_info	info;

	(void)argc;
	(void)argv;
	if (!cub_create(&info))
	{
		if (info.mlx)
			cub_destroy(&info);
		return (log_error("Couldn't create cub resources"));
	}
	if (mlx_image_to_window(info.mlx, info.screen.view, 0, 0) < 0)
	{
		cub_destroy(&info);
		return (log_error("Couldn't draw the screen"));
	}
	hook_loader(&info);
	mlx_loop(info.mlx);
	cub_destroy(&info);
	return (0);
}

void	hook_loader(t_info *info)
{
	mlx_loop_hook(info->mlx, update, info);
	mlx_loop_hook(info->mlx, hook_control_keys, info);
	mlx_key_hook(info->mlx, hook_option_key, info);
	mlx_mouse_hook(info->mlx, hook_control_mouse, info);
	mlx_loop_hook(info->mlx, clear_background, info);
	mlx_loop_hook(info->mlx, render, info);
	mlx_loop_hook(info->mlx, swap_buffers, info);
}

void	hook_control_keys(void *param)
{
	t_info	*info;

	info = param;
	if (mlx_is_key_down(info->mlx, MLX_KEY_Q)
		|| mlx_is_key_down(info->mlx, MLX_KEY_ESCAPE))
		cub_close_window(info->mlx);
	if (mlx_is_key_down(info->mlx, MLX_KEY_W))
		move_forward(info);
	if (mlx_is_key_down(info->mlx, MLX_KEY_A))
		move_left(info);
	if (mlx_is_key_down(info->mlx, MLX_KEY_D))
		move_right(info);
	if (mlx_is_key_down(info->mlx, MLX_KEY_S))
		move_backward(info);
	if (mlx_is_key_down(info->mlx, MLX_KEY_LEFT))
		rotate_left(info);
	if (mlx_is_key_down(info->mlx, MLX_KEY_RIGHT))
		rotate_right(info);
}

void	hook_option_key(mlx_key_data_t keydata, void *param)
{
	t_info	*info;

	info = param;
	if (keydata.key == MLX_KEY_1)
		switch_weapon(&info->player.toolbar, HAND);
	if (keydata.key == MLX_KEY_2)
		switch_weapon(&info->player.toolbar, KNIFE);
	if (keydata.key == MLX_KEY_3)
		switch_weapon(&info->player.toolbar, GUN);
	if (keydata.key == MLX_KEY_4)
		switch_weapon(&info->player.toolbar, SHOTGUN);
}

void	hook_control_mouse(mouse_key_t button, action_t action,
						modifier_key_t mods, void *param)
{
	t_info	*info;

	info = param;
	(void)mods;
	if (action == MLX_PRESS && button == MLX_MOUSE_BUTTON_LEFT)
		attack(info->player.toolbar.current_weapon);
}

void	rotate_left(t_info *info)
{
	info->player.angle = bfl_mod(info->player.angle - 1, 360);
	log_info("Rotate left");
}

void	rotate_right(t_info *info)
{
	info->player.angle = bfl_mod(info->player.angle + 1, 360);
	log_info("Rotate right");
}

void	move_forward(t_info *info)
{
	t_player	*player;

	player = &info->player;
	player->position.x += player->speed * sin(deg_to_rads(player->angle));
	player->position.y += player->speed * cos(deg_to_rads(player->angle));
	log_info("Move forward");
}

void	move_left(t_info *info)
{
	t_player	*player;

	player = &info->player;
	player->position.x -= player->speed
		* sin(deg_to_rads(bfl_mod(player->angle + 90, 360)));
	player->position.y -= player->speed
		* cos(deg_to_rads(bfl_mod(player->angle + 90, 360)));
	log_info("Move right");
}

void	move_right(t_info *info)
{
	t_player	*player;

	player = &info->player;
	player->position.x += player->speed
		* sin(deg_to_rads(bfl_mod(player->angle + 90, 360)));
	player->position.y += player->speed
		* cos(deg_to_rads(bfl_mod(player->angle + 90, 360)));
	log_info("Move right");
}

void	move_backward(t_info *info)
{
	t_player	*player;

	player = &info->player;
	player->position.x -= player->speed * sin(deg_to_rads(player->angle));
	player->position.y -= player->speed * cos(deg_to_rads(player->angle));
	log_info("Move backward");
}

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

// This will probably accept a map later on
t_v2	get_player_position(void)
{
	t_v2	position;
	int		i;
	int		j;
	int		map_rows;

	i = -1;
	map_rows = sizeof(smap) / sizeof(smap[0]);
	while (++i < map_rows)
	{
		j = -1;
		while (++j < (int)bfl_strlen(smap[i]))
		{
			if (smap[i][j] == 'N')
			{
				position.x = (float)i * PIXEL_SIZE;
				position.y = (float)j * PIXEL_SIZE;
				return (position);
			}
		}
	}
	return (v2_create(-1, -1));
}

bool	create_player(t_player *player)
{
	player->position = get_player_position();
	if (!create_toolbar(&player->toolbar))
		return (false);
	player->speed = 1;
	player->fov = PIXEL_SIZE * 2;
	player->angle = 0;
	log_info("Created player");
	return (true);
}

void	destroy_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->data && map->data[i])
	{
		free(map->data[i]);
		++i;
	}
	free(map->data);
}

bool	create_map(t_map *map)
{
	if (!create_map_data(map))
		return (false);
	log_info("Created map");
	return (true);
}

void	temp_fill_map(t_map *map)
{
	for (int i = 0; i < map->rows; ++i)
	{
		for (int j = 0; j < map->cols; ++j)
		{
			map->data[i][j] = smap[i][j];
		}
	}
}

bool	create_map_data(t_map *map)
{
	int	i;

	map->rows = 10;
	map->cols = 21;
	map->data = malloc((map->rows + 1) * sizeof(char *));
	if (!map->data)
		return (false);
	i = -1;
	while (++i < map->rows)
	{
		map->data[i] = bfl_calloc((map->cols + 1), sizeof(char));
		if (!map->data[i])
		{
			destroy_map(map);
			return (false);
		}
	}
	map->data[i] = NULL;
	temp_fill_map(map);
	return (true);
}

void	clear_background(void *param)
{
	t_info			*info;
	unsigned int	i;

	info = param;
	i = 0;
	while (i < info->screen.buffer->width * info->screen.buffer->height
		* sizeof(int))
	{
		set_color(&info->screen.buffer->pixels[i], gray());
		i += 4;
	}
}

void	swap_buffers(void *param)
{
	t_info	*info;

	info = param;
	bfl_memcpy(info->screen.view->pixels, info->screen.buffer->pixels,
		info->screen.width * info->screen.height * sizeof(int));
}

void	update(void *param)
{
	t_info	*info;

	info = param;
	info->player.speed = 20 * info->mlx->delta_time;
}
