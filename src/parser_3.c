
#include "cub3d.h"

// FALTA MENSAJE DE ERROR POR CADA UNO DE LOS PATHS
// FALTA CERRAR LOS ARCHIVOS SI ALGUNO FALLA
int	ft_check_paths(t_cub *cub)
{
	if (cub->no == NULL || cub->so == NULL || cub->we == NULL || cub->ea == NULL
		|| cub->f == NULL || cub->c == NULL)
	{
		bfl_fprintf(STDERR, "Error in paths\n");
		return (BFL_LKO);
	}
	if (ft_open_file(cub->no, &cub->fd_no) != BFL_OK)
		return (BFL_LKO);
	if (ft_open_file(cub->so, &cub->fd_so) != BFL_OK)
		return (BFL_LKO);
	if (ft_open_file(cub->we, &cub->fd_we) != BFL_OK)
		return (BFL_LKO);
	if (ft_open_file(cub->ea, &cub->fd_ea) != BFL_OK)
		return (BFL_LKO);
	if (ft_valid_color(cub) != BFL_OK)
		return (BFL_LKO);
	return (BFL_OK);
}
int	ft_valid_color(t_cub *cub)
{
	if (cub->f_b < 0 || cub->f_b > 255 || cub->f_g < 0 || cub->f_g > 255
		|| cub->f_r < 0 || cub->f_r > 255)
	{
		bfl_fprintf(STDERR, "Error in floor color(Overflow)\n");
		return (BFL_LKO);
	}
	if(cub->c_b < 0 || cub->c_b > 255 || cub->c_g < 0 || cub->c_g > 255
		|| cub->c_r < 0 || cub->c_r > 255)
	{
		bfl_fprintf(STDERR, "Error in ceiling color(Overflow)\n");
		return (BFL_LKO);
	}
	return (BFL_OK);
}

int	ft_open_file(char *filename, int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
	{
		bfl_fprintf(STDERR, "Error in opening file '%s'\n", filename);
		return (BFL_LKO);
	}
	return (BFL_OK);
}

int	ft_check_map(t_cub *cub)
{
	cub->i = 0;
	while (cub->map[cub->i])
	{
		cub->j = 0;
		while (cub->map[cub->i][cub->j])
		{
			if (cub->map[cub->i][cub->j] != '1'
				&& cub->map[cub->i][cub->j] != '0'
				&& bfl_isspace(cub->map[cub->i][cub->j]) == 0
				&& cub->map[cub->i][cub->j] != 'N'
				&& cub->map[cub->i][cub->j] != 'S'
				&& cub->map[cub->i][cub->j] != 'W'
				&& cub->map[cub->i][cub->j] != 'E')
			{
				bfl_fprintf(STDERR, "Error in map (Invalid char)\n");
				return (BFL_LKO);
			}
			cub->j++;
		}
		cub->i++;
	}
	return (BFL_OK);
}
