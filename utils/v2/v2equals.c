#include "utils.h"

bool	v2_equals(t_v2 *v1, t_v2 *v2)
{
	const int epsilon = 1;
	return (v1->x >= v2->x - epsilon && v1->x <= v2->x + epsilon
			&& v1->y >= v2->y - epsilon && v1->y <= v2->y + epsilon);
}
