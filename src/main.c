// Single file program to facilitate the development, I'll refactor it later

// TODO: Make logs to accept va_args or create something like sprintf
// to allow giving more information

#include "cub3d.h"
#define WIDTH 800
#define HEIGHT 600
#define LOGGING 1
#define PIXEL_SIZE 16
#define RESIZE 4

// Hardcoded map for testing
static const char *smap[] = {
	"              1111111",
	"111111111111111000001",
	"100000000011000000001",
	"100000000001000000001",
	"11100000N100000000001",
	"  1000011111111111111",
	"  100001             ",
	"11100001             ",
	"10000001             ",
	"11111111             ",
};

typedef enum e_log_level	t_log_level;
typedef enum e_type			t_type;
typedef struct s_weapon		t_weapon;
typedef struct s_toolbar	t_toolbar;
typedef struct s_player		t_player;
typedef struct s_map		t_map;
typedef struct s_screen		t_screen;
typedef struct s_info		t_info;

enum e_log_level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
};

enum e_type
{
	HAND,
	KNIFE,
	GUN,
	SHOTGUN,
	MAX_TYPES,
};

struct s_weapon
{
	t_type	type;
	char	name[32];
	int		damage;
	int		ammo;
	int		max_ammo;
	int		total_ammo;
	int		range;
};

struct s_toolbar
{
	t_weapon	weapons[MAX_TYPES];
	int			index;
	t_weapon	*current_weapon;
};

struct s_player
{
	t_v2		position;
	t_toolbar	toolbar;
	float		speed;
	int			fov;
	float		angle;
};

struct s_map
{
	char		**data;
	int			rows;
	int			cols;
};

struct s_screen
{
	mlx_image_t	*view;
	mlx_image_t	*buffer;
	int			width;
	int			height;
};

struct s_info
{
	mlx_t		*mlx;
	t_player	player;
	t_map		map;
	t_screen	screen;
};

// Cub
bool		cub_create(t_info *info);
void		cub_close_window(mlx_t *mlx);
void		cub_destroy(t_info *info);
int			cub_log(t_log_level level, const char *message);
int			log_info(const char *message);
int			log_error(const char *message);

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

// Weapons
t_weapon	create_hand(void);
t_weapon	create_knife(void);
t_weapon	create_gun(void);
t_weapon	create_shotgun(void);
bool		create_weapon(t_weapon *weapon_address, t_type type);

void		switch_weapon(t_toolbar *toolbar, t_type type);
void		attack(t_weapon *weapon);

void		reduce_ammo(t_weapon *weapon);
void		reload_ammo(t_weapon *weapon);

// Toolbar
bool		create_toolbar(t_toolbar *toolbar);

// Player
bool		create_player(t_player *player);
t_v2		get_player_position(void);

// Map
bool		create_map(t_map *map);
bool		create_map_data(t_map *map);
void		destroy_map(t_map *map);

// Debug
void		print_info(t_info *info);
void		print_player(t_player *player);
void		print_toolbar(t_toolbar *toolbar);
void		print_weapon(t_weapon *weapon);

// Render
void		render(void *param);
void		render_map(t_map *map, t_screen *screen);
void		render_player(t_player *player, t_screen *screen);
void		render_fov(t_player *player, t_screen *screen, t_map *map);

// Screen
bool		create_screen(t_screen *screen, mlx_t *mlx);

// MLX Utils
void		set_color(uint8_t *pixel, t_color color);
void		put_pixel(mlx_image_t *img, int x, int y, t_color color);
void		clear_background(void *param);
void		swap_buffers(void *param);

void		draw_rectangle(mlx_image_t *img, t_v2 position, t_v2 size,
				t_color color);
int			calculate_step(float dx, float dy);
void		draw_line(mlx_image_t *img, t_v2 start, t_v2 end, t_color color);

// Utils
float		deg_to_rads(float angle);

int	main(int argc, char **argv)
{
	static t_info	info;

	(void)argc;
	(void)argv;
	if (!cub_create(&info))
		return (log_error("Couldn't create cub resources"));
	if (mlx_image_to_window(info.mlx, info.screen.view, 0, 0) < 0)
	{
		log_error("Couldn't draw the screen");
		cub_destroy(&info);
		return (1);
	}
	hook_loader(&info);
	mlx_loop(info.mlx);
	cub_destroy(&info);
	return (0);
}

int	cub_log(t_log_level level, const char *message)
{
	if (LOGGING)
	{
		if (level == DEBUG)
			bfl_fprintf(STDOUT, "[DEBUG] %s\n", message);
		else if (level == INFO)
			bfl_fprintf(STDOUT, "[INFO] %s\n", message);
		else if (level == WARNING)
			bfl_fprintf(STDERR, "[WARNING] %s\n", message);
		else if (level == ERROR)
			bfl_fprintf(STDERR, "[ERROR] %s\n", message);
	}
	return (1);
}

int	log_info(const char *message)
{
	return (cub_log(INFO, message));
}

int	log_error(const char *message)
{
	return (cub_log(ERROR, message));
}

void	hook_loader(t_info *info)
{
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
	if (keydata.key == MLX_KEY_P)
		print_info(info);
	if (keydata.key == MLX_KEY_1)
		switch_weapon(&info->player.toolbar, HAND);
	if (keydata.key == MLX_KEY_2)
		switch_weapon(&info->player.toolbar, KNIFE);
	if (keydata.key == MLX_KEY_3)
		switch_weapon(&info->player.toolbar, GUN);
	if (keydata.key == MLX_KEY_4)
		switch_weapon(&info->player.toolbar, SHOTGUN);
}

void	switch_weapon(t_toolbar *toolbar, t_type type)
{
	toolbar->current_weapon = &toolbar->weapons[type];
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
	info->player.position.x -= info->player.speed;
	log_info("Move forward");
}

void	move_left(t_info *info)
{
	info->player.position.y -= info->player.speed;
	log_info("Move left");
}

void	move_right(t_info *info)
{
	info->player.position.y += info->player.speed;
	log_info("Move right");
}

void	move_backward(t_info *info)
{
	info->player.position.x += info->player.speed;
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
		return (log_error("Couldn't create player"));
	if (!create_map(&info->map))
		return (log_error("Couldn't create map"));
	if (!create_screen(&info->screen, info->mlx))
		return (log_error("Couldn't create screen"));
	return (true);
}

void	cub_close_window(mlx_t *mlx)
{
	log_info("Window closed");
	mlx_close_window(mlx);
}

void	cub_destroy(t_info *info)
{
	mlx_terminate(info->mlx);
	destroy_map(&info->map);
	log_info("Resources destroyed");
}

t_weapon	create_hand(void)
{
	t_weapon	weapon;

	weapon.type = HAND;
	bfl_memcpy(weapon.name, "HAND", 5);
	weapon.damage = 1;
	weapon.ammo = -1;
	weapon.max_ammo = -1;
	weapon.total_ammo = -1;
	weapon.range = 1;
	log_info("Created weapon HAND");
	return (weapon);
}

t_weapon	create_knife(void)
{
	t_weapon	weapon;

	weapon.type = KNIFE;
	bfl_memcpy(weapon.name, "KNIFE", 6);
	weapon.damage = 2;
	weapon.ammo = -1;
	weapon.max_ammo = -1;
	weapon.total_ammo = -1;
	weapon.range = 1;
	log_info("Created weapon KNIFE");
	return (weapon);
}

t_weapon	create_gun(void)
{
	t_weapon	weapon;

	weapon.type = GUN;
	bfl_memcpy(weapon.name, "GUN", 4);
	weapon.damage = 4;
	weapon.ammo = 16;
	weapon.max_ammo = 16;
	weapon.total_ammo = 64;
	weapon.range = 8;
	log_info("Created weapon GUN");
	return (weapon);
}

t_weapon	create_shotgun(void)
{
	t_weapon	weapon;

	weapon.type = HAND;
	bfl_memcpy(weapon.name, "SHOTGUN", 8);
	weapon.damage = 10;
	weapon.ammo = 5;
	weapon.max_ammo = 5;
	weapon.total_ammo = 20;
	weapon.range = 3;
	log_info("Created weapon SHOTGUN");
	return (weapon);
}

bool	create_weapon(t_weapon *weapon, t_type type)
{
	if (type < 0 || type >= MAX_TYPES)
		return (false);
	if (type == HAND)
		*weapon = create_hand();
	else if (type == KNIFE)
		*weapon = create_knife();
	else if (type == GUN)
		*weapon = create_gun();
	else if (type == SHOTGUN)
		*weapon = create_shotgun();
	return (true);
}

bool	create_toolbar(t_toolbar *toolbar)
{
	t_type	type;

	type = 0;
	while (type < MAX_TYPES)
	{
		if (!create_weapon(&toolbar->weapons[type], type))
			return (false);
		++type;
	}
	toolbar->index = 0;
	toolbar->current_weapon = &toolbar->weapons[0];
	log_info("Created toolbar");
	return (true);
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
	return ((t_v2){.x = -1, .y = -1});
}

bool	create_player(t_player *player)
{
	player->position = get_player_position();
	if (!create_toolbar(&player->toolbar))
		return (false);
	player->speed = 1;
	player->fov = 100;
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

bool	create_screen(t_screen *screen, mlx_t *mlx)
{
	screen->width = mlx->width;
	screen->height = mlx->height;
	screen->view = mlx_new_image(mlx, screen->width, screen->height);
	screen->buffer = mlx_new_image(mlx, screen->width, screen->height);
	if (!screen->view || !screen->buffer)
		return (false);
	log_info("Created screen");
	return (true);
}

void	reload_ammo(t_weapon *weapon)
{
	if (weapon->max_ammo > weapon->total_ammo)
	{
		weapon->ammo = weapon->total_ammo;
		weapon->total_ammo = 0;
	}
	else
	{
		weapon->ammo = weapon->max_ammo;
		weapon->total_ammo -= weapon->max_ammo;
	}
	log_info("Reload ammo");
}

void	reduce_ammo(t_weapon *weapon)
{
	if (weapon->total_ammo <= 0 && weapon->ammo <= 0)
		return ;
	if (weapon->ammo == 0)
		reload_ammo(weapon);
	--weapon->ammo;
	log_info("Reduce ammo");
}

void	attack(t_weapon *weapon)
{
	if (weapon->ammo == 0 && weapon->total_ammo == 0)
	{
		log_info("No ammo");
		return ;
	}
	log_info("Attack");
	reduce_ammo(weapon);
}

void	print_info(t_info *info)
{
	print_player(&info->player);
}

void	print_player(t_player *player)
{
	printf("Player position: %f, %f\n", player->position.x, player->position.y);
	printf("Player angle: %f\n", player->angle);
	print_toolbar(&player->toolbar);
}

void	print_toolbar(t_toolbar *toolbar)
{
	print_weapon(toolbar->current_weapon);
}

void	print_weapon(t_weapon *weapon)
{
	// This has to be replaced to a log_info, but I don't have support
	// for va_args yet
	printf("%s: %d/%d\n", weapon->name, weapon->ammo, weapon->total_ammo);
}

void	render(void *param)
{
	t_info	*info;

	info = param;
	render_map(&info->map, &info->screen);
	render_player(&info->player, &info->screen);
	render_fov(&info->player, &info->screen, &info->map);
}

void	render_map_element(t_map *map, t_screen *screen, int i, int j)
{
	t_v2	position;
	t_v2	size;

	position = (t_v2){
		.x = j * PIXEL_SIZE,
		.y = i * PIXEL_SIZE,
	};
	size = (t_v2){
		.x = PIXEL_SIZE,
		.y = PIXEL_SIZE,
	};
	if (map->data[i][j] != '1' && map->data[i][j] != ' ')
		draw_rectangle(screen->buffer, position, size, WHITE);
	else if (map->data[i][j] == '1')
		draw_rectangle(screen->buffer, position, size, BLACK);
}

void	render_map(t_map *map, t_screen *screen)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			render_map_element(map, screen, i, j);
		}
	}
}

void	render_player(t_player *player, t_screen *screen)
{
	t_v2	position;
	t_v2	size;

	position = (t_v2){
		.x = player->position.y,
		.y = player->position.x,
	};
	size = (t_v2){
		.x = PIXEL_SIZE,
		.y = PIXEL_SIZE,
	};
	draw_rectangle(screen->buffer, position, size, LIGHTRED);
}

// NOTE: Angle must be in rads
t_v2	calculate_fov_end(t_v2 start, float angle, int fov, t_map *map)
{
	t_v2	p;
	int		i;

	i = -1;
	p = (t_v2){.x = start.x, .y = start.y};
	while (++i < fov)
	{
		p.x += cos(angle);
		p.y += sin(angle);
		if (p.x / PIXEL_SIZE < 0 || p.x / PIXEL_SIZE >= map->cols
			|| p.y / PIXEL_SIZE < 0 || p.y / PIXEL_SIZE >= map->rows)
			break ;
		if (map->data[(int)(p.y / PIXEL_SIZE)][(int)(p.x / PIXEL_SIZE)] == '1')
			break ;
	}
	return (p);
}

void	render_fov(t_player *player, t_screen *screen, t_map *map)
{
	t_v2	start;
	t_v2	end;

	start = (t_v2){
		.x = player->position.y + PIXEL_SIZE * 0.5,
		.y = player->position.x + PIXEL_SIZE * 0.5,
	};
	end = calculate_fov_end(start, deg_to_rads(player->angle),
			player->fov, map);
	draw_line(screen->buffer, start, end, GREEN);
}

void	set_color(uint8_t *pixel, t_color color)
{
	pixel[0] = color.r;
	pixel[1] = color.g;
	pixel[2] = color.b;
	pixel[3] = color.a;
}

void	put_pixel(mlx_image_t *img, int x, int y, t_color color)
{
	int	pos;

	pos = y * img->width + x;
	if (pos < 0 || pos >= (int)(img->width * img->height))
	{
		log_error("Tried to put pixel, but is out of bounds!");
		return ;
	}
	set_color(&img->pixels[pos * sizeof(int)], color);
}

void	draw_rectangle(mlx_image_t *img, t_v2 position, t_v2 size,
		t_color color)
{
	int	i;
	int	j;

	i = position.x - 1;
	while (++i < position.x + size.x)
	{
		j = position.y - 1;
		while (++j < position.y + size.y)
		{
			put_pixel(img, i, j, color);
		}
	}
}

int	calculate_step(float dx, float dy)
{
	if (dx < 0)
		dx *= -1;
	if (dy < 0)
		dy *= -1;
	if (dx > dy)
		return (dx);
	return (dy);
}

void	draw_line(mlx_image_t *img, t_v2 start, t_v2 end, t_color color)
{
	int		step;
	t_v2	increment;
	t_v2	p;
	int		i;

	step = calculate_step(end.x - start.x, end.y - start.y);
	increment.x = (end.x - start.x) / step;
	increment.y = (end.y - start.y) / step;
	p = start;
	i = -1;
	while (++i <= step)
	{
		put_pixel(img, p.x, p.y, color);
		p.x += increment.x;
		p.y += increment.y;
	}
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
		set_color(&info->screen.buffer->pixels[i], GRAY);
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

float	deg_to_rads(float angle)
{
	return (angle * M_PI / 180);
}
