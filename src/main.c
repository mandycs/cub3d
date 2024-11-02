// Single file program to facilitate the development, I'll refactor it later

#include "cub3d.h"
#define WIDTH 800
#define HEIGHT 600
#define LOGGING 1

typedef enum e_log_level t_log_level;

enum e_log_level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
};

mlx_t	*cub_init(int width, int height, const char *title, bool resize);
void	cub_close_window(mlx_t *mlx);
void	cub_destroy(mlx_t *mlx);

int		cub_log(t_log_level, const char *message);
int		log_info(const char *message);
int		log_error(const char *message);

void	hook_control_keys(void *param);
void	move_forward(void *param);
void	move_left(void *param);
void	move_right(void *param);
void	move_backward(void *param);

int	main(int argc, char **argv)
{
	mlx_t	*mlx;

	(void)argc;
	(void)argv;
	mlx = cub_init(WIDTH, HEIGHT, "Cub3D", false);
	if (!mlx)
		return (log_error("Couldn't init mlx"));
	mlx_loop_hook(mlx, hook_control_keys, mlx);
	mlx_loop(mlx);
	cub_destroy(mlx);
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
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_Q) || mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		cub_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		move_forward(param);
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		move_left(param);
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		move_right(param);
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		move_backward(param);
}

void	move_forward(void *param)
{
	(void)param;
	log_info("Move forward");
}

void	move_left(void *param)
{
	(void)param;
	log_info("Move left");
}

void	move_right(void *param)
{
	(void)param;
	log_info("Move right");
}

void	move_backward(void *param)
{
	(void)param;
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
