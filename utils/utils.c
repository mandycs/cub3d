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
	while (cub->text[i])
	{
		bfl_printf("%s\n", cub->text[i]);
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
	int	i;

	i = 0;
	while (cub->text[i] != NULL)
	{
		free(cub->text[i]);
		i++;
	}
	free(cub->text);
	free(cub->no);
	free(cub->so);
	free(cub->we);
	free(cub->ea);
	free(cub->f);
	free(cub->c);
	i = 0;
	while (cub->map[i] != NULL)
	{
		free(cub->map[i]);
		i++;
	}
	free(cub->map);
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
}
