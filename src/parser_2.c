#include "cub3d.h"
//AÑADIR MENSAJE DE ERROR PARA CADA UNO DE LOS PATHS
//FUNCION CON FLAGS Y ENUM PARA MENSAJES DE ERROR?
void	ft_process_texture(t_cub *cub)
{
	if (bfl_strncmp(cub->text[cub->count], "NO", 2) == 0)
		ft_extract_path_texture(cub, 0);
	else if (bfl_strncmp(cub->text[cub->count], "SO", 2) == 0)
		ft_extract_path_texture(cub, 1);
	else if (bfl_strncmp(cub->text[cub->count], "WE", 2) == 0)
		ft_extract_path_texture(cub, 2);
	else if (bfl_strncmp(cub->text[cub->count], "EA", 2) == 0)
		ft_extract_path_texture(cub, 3);
	else if (bfl_strncmp(cub->text[cub->count], "F", 1) == 0)
		ft_extract_color(cub, 0);
	else if (bfl_strncmp(cub->text[cub->count], "C", 1) == 0)
		ft_extract_color(cub, 1);
}

void	ft_extract_path_texture(t_cub *cub, int flag)
{
	while (cub->text[cub->count][cub->i] != '.'
		&& cub->text[cub->count][cub->i])
		cub->i++;
	if (flag == 0)
		cub->no = bfl_strdup(&cub->text[cub->count][cub->i]);
	else if (flag == 1)
		cub->so = bfl_strdup(&cub->text[cub->count][cub->i]);
	else if (flag == 2)
		cub->we = bfl_strdup(&cub->text[cub->count][cub->i]);
	else if (flag == 3)
		cub->ea = bfl_strdup(&cub->text[cub->count][cub->i]);
	cub->count++;
	cub->i = 0;
}
int	ft_extract_color(t_cub *cub, int flag)
{
	while (!bfl_isdigit(cub->text[cub->count][cub->i]))
		cub->i++;
	if(cub->text[cub->count][cub->i] == '\0')
	{
		bfl_fprintf(STDERR, "Error (Missing Color)\n");
		return (BFL_LKO);
	}
	if (flag == 0 && cub->text[cub->count][cub->i])
	{
		cub->f = bfl_strdup(&cub->text[cub->count][cub->i]);
		if (ft_extract_color_aux(cub, flag) == BFL_LKO)
			return (BFL_LKO);
	}
	else if (flag == 1 && cub->text[cub->count][cub->i])
	{
		cub->c = bfl_strdup(&cub->text[cub->count][cub->i]);
		if (ft_extract_color_aux(cub, flag) == BFL_LKO)
			return (BFL_LKO);
	}
	cub->count++;
	cub->i = 0;
	return (BFL_OK);
}

int	ft_extract_map(t_cub *cub)
{
	int	len;
	int	tmp;

	tmp = 0;
	tmp = cub->count;
	len = 0;
	cub->i = 0;
	while (cub->text[cub->count])
	{
		cub->i = 0;
		while (cub->text[cub->count][cub->i])
			cub->i++;
		cub->count++;
		len++;
	}
	cub->map = bfl_calloc(len + 1, sizeof(char *));
	cub->i = 0;
	while (cub->text[tmp])
	{
		cub->map[cub->i] = bfl_strdup(cub->text[tmp]);
		cub->i++;
		tmp++;
	}
	return (BFL_OK);
}

int	ft_extract_color_aux(t_cub *cub, int flag)
{
	if (flag == 0)
	{
		cub->f_r = bfl_atoi(cub->f);
		cub->f_aux = bfl_strchr(cub->f, ',');
		if (!cub->f_aux)
			return (BFL_LKO);
		cub->f_g = bfl_atoi(cub->f_aux + 1);
		cub->f_aux = bfl_strchr(cub->f_aux + 1, ',');
		if (!cub->f_aux)
			return (BFL_LKO);
		cub->f_b = bfl_atoi(cub->f_aux + 1);
	}
	if (flag == 1)
	{
		cub->c_r = bfl_atoi(cub->c);
		cub->f_aux = bfl_strchr(cub->c, ',');
		if (!cub->f_aux)
			return (BFL_LKO);
		cub->c_g = bfl_atoi(cub->f_aux + 1);
		cub->f_aux = bfl_strchr(cub->f_aux + 1, ',');
		if (!cub->f_aux)
			return (BFL_LKO);
		cub->c_b = bfl_atoi(cub->f_aux + 1);
	}
	return (BFL_OK);
}
