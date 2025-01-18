#include "colors.h"

t_color	get_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return ((t_color){
		.r = r,
		.g = g,
		.b = b,
		.a = a,
	});
}
