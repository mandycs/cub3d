#include "utils.h"

t_v2	v2_div(t_v2 *v1, t_v2 *v2)
{
	return ((t_v2){
		.x = v1->x / v2->x,
		.y = v1->y / v2->y,
	});
}

t_v2	v2_div_scalar(t_v2 *v1, float scalar)
{
	return ((t_v2){
		.x = v1->x / scalar,
		.y = v1->y / scalar,
	});
}
