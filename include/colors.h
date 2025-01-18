#ifndef COLORS_H
# define COLORS_H

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

typedef union u_color	t_color;

/* @------------------------------------------------------------------------@ */
/* |                            Struct Section                              | */
/* @------------------------------------------------------------------------@ */

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

#endif // COLORS_H
