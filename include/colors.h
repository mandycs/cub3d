#ifndef COLORS_H
# define COLORS_H

/* @------------------------------------------------------------------------@ */
/* |                            Include Section                             | */
/* @------------------------------------------------------------------------@ */

# include <stdint.h>

/* @------------------------------------------------------------------------@ */
/* |                            Typedef Section                             | */
/* @------------------------------------------------------------------------@ */

typedef union u_color	t_color;

/* @------------------------------------------------------------------------@ */
/* |                            Struct Section                              | */
/* @------------------------------------------------------------------------@ */

union u_color
{
	struct
	{
		uint8_t	a;
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
	};
	uint8_t		data[4];
	uint32_t	hex;
};

/* @------------------------------------------------------------------------@ */
/* |                           Function Section                             | */
/* @------------------------------------------------------------------------@ */

t_color	get_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
t_color	white(void);
t_color	black(void);
t_color	red(void);
t_color	green(void);
t_color	blue(void);
t_color	yellow(void);
t_color	lightred(void);
t_color	lightgreen(void);
t_color	lightblue(void);
t_color	lightyellow(void);
t_color	darkgray(void);
t_color	gray(void);

#endif // COLORS_H
