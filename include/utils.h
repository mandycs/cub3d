#ifndef UTILS_H
# define UTILS_H

/* @------------------------------------------------------------------------@ */
/* |                            Include Section                             | */
/* @------------------------------------------------------------------------@ */

# include "v2.h"
# include "colors.h"
# include <math.h>
# include "cub3d.h"

typedef struct s_player	t_player;
typedef struct s_map	t_map;

/* @------------------------------------------------------------------------@ */
/* |                           Function Section                             | */
/* @------------------------------------------------------------------------@ */

float	deg_to_rads(float angle);
int		calculate_step(float dx, float dy);
float	calculate_distance(t_player *player, t_map *map, float angle);
t_v2	calculate_wall_collision(t_v2 start, float angle, int fov, t_map *map);
bool	is_wall_collision(t_map *map, int x, int y);

#endif // UTILS_H
