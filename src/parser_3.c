
#include "cub3d.h"

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
	if (ft_open_file(cub->f, &cub->fd_f) != BFL_OK)
		return (BFL_LKO);
	if (ft_open_file(cub->c, &cub->fd_c) != BFL_OK)
		return (BFL_LKO);
	return (BFL_OK);
}

int	ft_open_file(char *filename, int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
	{
		bfl_fprintf(STDERR, "Error in opening file\n");
		return (BFL_LKO);
	}
	return (BFL_OK);
}