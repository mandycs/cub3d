// Single file program to facilitate the development, I'll refactor it later

// TODO: Make logs to accept va_args or create something like sprintf
// to allow giving more information

#include "cub3d.h"
#define WIDTH 800
#define HEIGHT 600
#define LOGGING 1

typedef enum e_log_level	t_log_level;
typedef enum e_type			t_type;
typedef struct s_weapon		t_weapon;
typedef struct s_toolbar	t_toolbar;
typedef struct s_player		t_player;
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
	int			speed;
	int			fov;
};

struct s_info
{
	mlx_t		*mlx;
	t_player	player;
};

mlx_t		*cub_init(int width, int height, const char *title, bool resize);
void		cub_close_window(mlx_t *mlx);
void		cub_destroy(mlx_t *mlx);

int			cub_log(t_log_level, const char *message);
int			log_info(const char *message);
int			log_error(const char *message);

void		hook_control_keys(void *param);
void		move_forward(t_info *info);
void		move_left(t_info *info);
void		move_right(t_info *info);
void		move_backward(t_info *info);
void		rotate_left(t_info *info);
void		rotate_right(t_info *info);

void		hook_option_key(mlx_key_data_t keydata, void *param);
void		switch_weapon(t_toolbar *toolbar, t_type type);

void		hook_control_mouse(mouse_key_t button, action_t action,
							modifier_key_t mods, void* param);
void		attack(t_weapon *weapon);

t_weapon	create_hand(void);
t_weapon	create_knife(void);
t_weapon	create_gun(void);
t_weapon	create_shotgun(void);
bool		create_weapon(t_weapon *weapon_address, t_type type);

void		reduce_ammo(t_weapon *weapon);
void		reload_ammo(t_weapon *weapon);

bool		create_toolbar(t_toolbar *toolbar);

bool		create_player(t_player *player);

void		print_info(t_info *info);
void		print_player(t_player *player);
void		print_toolbar(t_toolbar *toolbar);
void		print_weapon(t_weapon *weapon);

int	main(int argc, char **argv)
{
	static t_info	info;

	(void)argc;
	(void)argv;

	if (!create_player(&info.player))
		log_error("you know wa");
	info.mlx = cub_init(WIDTH, HEIGHT, "Cub3D", false);
	if (!info.mlx)
		return (log_error("Couldn't init mlx"));
	mlx_loop_hook(info.mlx, hook_control_keys, &info);
	mlx_key_hook(info.mlx, hook_option_key, &info);
	mlx_mouse_hook(info.mlx, hook_control_mouse, &info);
	mlx_loop(info.mlx);
	cub_destroy(info.mlx);
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
	t_info *info;

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
							modifier_key_t mods, void* param)
{
	t_info	*info;

	info = param;
	(void)mods;
	if (action == MLX_PRESS && button == MLX_MOUSE_BUTTON_LEFT)
		attack(info->player.toolbar.current_weapon);
}

void	rotate_left(t_info *info)
{
	(void)info;
	log_info("Rotate left");
}

void	rotate_right(t_info *info)
{
	(void)info;
	log_info("Rotate right");
}

void	move_forward(t_info *info)
{
	(void)info;
	log_info("Move forward");
}

void	move_left(t_info *info)
{
	(void)info;
	log_info("Move left");
}

void	move_right(t_info *info)
{
	(void)info;
	log_info("Move right");
}

void	move_backward(t_info *info)
{
	(void)info;
	log_info("Move backward");
}

mlx_t	*cub_init(int width, int height, const char *title, bool resize)
{
	log_info("Window initialized");
	return (mlx_init(width, height, title, resize));
}

void	cub_close_window(mlx_t *mlx)
{
	log_info("Window closed");
	mlx_close_window(mlx);
}

void	cub_destroy(mlx_t *mlx)
{
	log_info("Resources destroyed");
	mlx_terminate(mlx);
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

bool	create_player(t_player *player)
{
	player->position = (t_v2){.x = 0, .y = 0};
	if (!create_toolbar(&player->toolbar))
		return (false);
	player->speed = 1;
	player->fov = 10;
	log_info("Created player");
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
