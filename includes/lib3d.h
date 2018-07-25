/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 08:32:29 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/25 14:36:10 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB3D_H
# define LIB3D_H
# include <math.h>
# include <stddef.h>

# ifndef ABS
#  define ABS(x) ((x < 0) ? -(x) : (x))
# endif

/*
** Your standard 2D point
*/
typedef struct	s_v2d
{
	float		x;
	float		y;
}				t_v2d;

/*
** Your standard 3D point
*/
typedef struct	s_v3d
{
	float		x;
	float		y;
	float		z;
}				t_v3d;

/*
** A transformation matrix
** (it's actually just a float*)
*/
typedef float	t_mat[4][4];

/*
** Cached and approximate versions of sin and cos that accept degrees
*/
# define CACHTAY_SIZE 360
typedef struct	s_cachtay
{
	float		e[CACHTAY_SIZE];
}				t_cachtay;
float			fast_sin(float deg);
float			fast_cos(float deg);

/*
** Maps a value from one range to another
*/
float					ft_fmapf(float n, float s1, float e1, float s2,
																	float e2);
long					ft_lmapl(long n, long s1, long e1, long s2, long e2);
float					ft_lmapf(long n, long s1, long e1, float s2, float e2);
long					ft_fmapl(float n, float s1, float e1, long s2, long e2);

/*
** Matrix stuff
*/
void			mat_copy(t_mat dest, const t_mat src);
void			mat_set_row(float dest[4], float a, float b, float c, float d);

/*
** Sets a matrix to an identity matrix (aka a "blank" matrix)
*/
void			mat_set_identity(t_mat m);

/*
** Multiplies (combines) two matricies and stores the result in dest
*/
void			mat_mult(const t_mat m1, const t_mat m2, t_mat dest);

/*
** Transforms a 3d point using a matrix
*/
t_v3d			v3d_transform(const t_v3d src, const t_mat m);

/*
** Applies a translation to a matrix
*/
void			mat_translate(t_mat dest, float x, float y, float z);

/*
** Applies a scale operation to a matrix
*/
void			mat_scale(t_mat dest, float x, float y, float z);

/*
** Applies a (x, y, z) rotation to a matrix
*/
void			mat_rotate_x(t_mat dest, float x);
void			mat_rotate_y(t_mat dest, float y);
void			mat_rotate_z(t_mat dest, float z);
void			mat_rotate_xyz(t_mat dest, float x, float y, float z);

#endif

