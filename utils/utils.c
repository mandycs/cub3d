#include "cub3d.h"

void	ribanab(void)
{
	printf("Hello World, I am ribana-b from 42 Malaga c:\n");
	return ;
}

void	ft_print_map(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map_dup[i])
	{
		bfl_printf("%s\n", cub->map_dup[i]);
		i++;
	}
}

void	ft_print_paths(t_cub *cub)
{
	cub->i = 0;
	bfl_printf("NO: %s\n", cub->no);
	bfl_printf("SO: %s\n", cub->so);
	bfl_printf("WE: %s\n", cub->we);
	bfl_printf("EA: %s\n", cub->ea);
	bfl_printf("F: %s\n", cub->f);
	bfl_printf("C: %s\n", cub->c);
	while (cub->map[cub->i] != NULL)
	{
		bfl_printf("%s\n", cub->map[cub->i]);
		cub->i++;
	}
}

void	ft_free_cub(t_cub *cub)
{
	bfl_free(&cub->text, 2);
	bfl_free(&cub->no, 1);
	bfl_free(&cub->so, 1);
	bfl_free(&cub->we, 1);
	bfl_free(&cub->ea, 1);
	bfl_free(&cub->f, 1);
	bfl_free(&cub->c, 1);

	bfl_free(&cub->map, 2);
}

void	initialize_cub(t_cub *cub)
{
	cub->i = 0;
	cub->count = 0;
	cub->text = NULL;
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->f = NULL;
	cub->c = NULL;
	cub->map = NULL;
	cub->line = NULL;
	cub->new_lines = NULL;
	cub->fd_no = 0;
	cub->fd_so = 0;
	cub->fd_we = 0;
	cub->fd_ea = 0;
	cub->error = 0;
	cub->floor_c.a = 255;
	cub->ceiling_c.a = 255;
	cub->height = 0;
	cub->width = 0;
	cub->flag = 0;
	cub->error = CUB_OK;
}
