/**
 * TODO: Refactor utils.h into colors.h and vector.h
 */
#ifndef UTILS_H
# define UTILS_H

/* @------------------------------------------------------------------------@ */
/* |                            Define Section                              | */
/* @------------------------------------------------------------------------@ */

#define WHITE ((t_color){.r = 255, .g = 255, .b = 255, .a = 255})
#define BLACK ((t_color){.r = 0, .g = 0, .b = 0, .a = 255})
#define RED ((t_color){.r = 255, .g = 0, .b = 0, .a = 255})
#define GREEN ((t_color){.r = 0, .g = 255, .b = 0, .a = 255})
#define BLUE ((t_color){.r = 0, .g = 0, .b = 255, .a = 255})
#define YELLOW ((t_color){.r = 255, .g = 255, .b = 0, .a = 255})
#define LIGHTRED ((t_color){.r = 255, .g = 127, .b = 127, .a = 255})
#define LIGHTGREEN ((t_color){.r = 127, .g = 255, .b = 127, .a = 255})
#define LIGHTBLUE ((t_color){.r = 127, .g = 127, .b = 255, .a = 255})
#define LIGHTYELLOW ((t_color){.r = 255, .g = 255, .b = 127, .a = 255})
#define DARKGRAY ((t_color){.hex = 0x303030FF})
#define GRAY ((t_color){.hex = 0x606060FF})

/* @------------------------------------------------------------------------@ */
/* |                            Typedef Section                             | */
/* @------------------------------------------------------------------------@ */

typedef union u_v2		t_v2;
typedef union u_color	t_color;

/* @------------------------------------------------------------------------@ */
/* |                            Struct Section                              | */
/* @------------------------------------------------------------------------@ */

union u_v2
{
	struct
	{
		float	x;
		float	y;
	};
	float	data[2];
};

union u_color
{
	struct
	{
		unsigned char	a;
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
	};
	unsigned char	data[4];
	unsigned long	hex;
};

/* @------------------------------------------------------------------------@ */
/* |                           Function Section                             | */
/* @------------------------------------------------------------------------@ */

t_v2	v2_create(float x, float y);
t_v2	v2_zero(void);
t_v2	v2_add(t_v2 *v1, t_v2 *v2);
t_v2	v2_add_scalar(t_v2 *v1, float scalar);
t_v2	v2_sub(t_v2 *v1, t_v2 *v2);
t_v2	v2_sub_scalar(t_v2 *v1, float scalar);
t_v2	v2_mult(t_v2 *v1, t_v2 *v2);
t_v2	v2_mult_scalar(t_v2 *v1, float scalar);
t_v2	v2_div(t_v2 *v1, t_v2 *v2);
t_v2	v2_div_scalar(t_v2 *v1, float scalar);

#endif // UTILS_H
