#include "utils.h"

float	calculate_distance(t_player *player, t_map *map, float angle)
{
	float	distance;
	t_v2	start;
	t_v2	end;

	start = v2_create(player->position.y + PIXEL_SIZE * 0.5,
			player->position.x + PIXEL_SIZE * 0.5);
	end = calculate_wall_collision(start, deg_to_rads(angle), player->fov, map);
	distance = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
	distance *= cos(deg_to_rads(bfl_mod(angle - player->angle, 360)));
	return (distance);
}
