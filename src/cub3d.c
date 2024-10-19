#include "cub3d.h"

// Cambiar este 0 a 1 para activar este main
#if 0
int	main(int argc, char **argv)
{
	t_cub	cub;

	initialize_cub(&cub);
	cub.error = ft_check_arg(argc, argv, &cub) != CUB_OK;
	if (cub.error != CUB_OK)
		ft_check_error(&cub);
	printf("PITOPITOPITO\n");
	// ft_free_cub(&cub);
}
#else
int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	mlx_t	*mlx;
	mlx = mlx_init(800, 600, "Cub3D", false);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
#endif

// PLANTEAR SI FALLA UN MALLOC DE ALGUN STRDUP COMO GESTIONAR ESE ERROR
