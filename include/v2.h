#ifndef V2_H
# define V2_H

/* @------------------------------------------------------------------------@ */
/* |                            Include Section                             | */
/* @------------------------------------------------------------------------@ */

# include <stdbool.h>

/* @------------------------------------------------------------------------@ */
/* |                            Typedef Section                             | */
/* @------------------------------------------------------------------------@ */

typedef union u_v2		t_v2;

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
bool	v2_equals(t_v2 *v1, t_v2 *v2);

#endif // V2_H
