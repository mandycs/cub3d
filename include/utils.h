#ifndef UTILS_H
# define UTILS_H

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
