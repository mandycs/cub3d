
#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	cub;

	initialize_cub(&cub);
	ft_check_arg(argc, argv, &cub);
	ft_free_cub(&cub);
}
