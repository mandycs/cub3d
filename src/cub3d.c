
#include "cub3d.h"

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

// PLANTEAR SI FALLA UN MALLOC DE ALGUN STRDUP COMO GESTIONAR ESE ERROR