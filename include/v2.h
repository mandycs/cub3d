/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:22:18 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/02/15 13:49:02 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

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
		double	x;
		double	y;
	};
	double	data[2];
};

/* @------------------------------------------------------------------------@ */
/* |                           Function Section                             | */
/* @------------------------------------------------------------------------@ */

t_v2	v2_create(double x, double y);
t_v2	v2_zero(void);
t_v2	v2_add(t_v2 v1, t_v2 v2);
t_v2	v2_add_scalar(t_v2 v1, double scalar);
t_v2	v2_sub(t_v2 v1, t_v2 v2);
t_v2	v2_sub_scalar(t_v2 v1, double scalar);
t_v2	v2_mult(t_v2 v1, t_v2 v2);
t_v2	v2_mult_scalar(t_v2 v1, double scalar);
t_v2	v2_div(t_v2 v1, t_v2 v2);
t_v2	v2_div_scalar(t_v2 v1, double scalar);
bool	v2_equals(t_v2 v1, t_v2 v2);

#endif // V2_H
