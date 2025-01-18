#include "utils.h"

t_v2	v2_create(float x, float y)
{
	return ((t_v2){
		.x = x,
		.y = y,
	});
}
