/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:19:10 by mancorte          #+#    #+#             */
/*   Updated: 2024/12/21 01:33:15 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Cambiar este 0 a 1 para activar este main
#if 1

int	main(int argc, char **argv)
{
	t_cub	cub;

	initialize_cub(&cub);
	cub.error = ft_check_arg(argc, argv, &cub) != CUB_OK;
	if (cub.error != CUB_OK)
		ft_check_error(&cub);
	printf("PITOPITOPITO\n");
}

#else

int	main(int argc, char **argv)
{
	mlx_t	*mlx;

	(void)argc;
	(void)argv;
	mlx = mlx_init(800, 600, "Cub3D", false);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
#endif

// PLANTEAR SI FALLA UN MALLOC DE ALGUN STRDUP COMO GESTIONAR ESE ERROR
// SI PASAN UN MAPA VACIO EXPLOTA
// AGREGAR FLOODFILL
