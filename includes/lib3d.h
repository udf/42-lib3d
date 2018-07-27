/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 08:32:29 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/27 10:15:28 by mhoosen          ###   ########.fr       */
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
typedef struct	s_p2d
{
	float		x;
	float		y;
}				t_p2d;

/*
** Your standard 3D point
*/
typedef struct	s_p3d
{
	float		x;
	float		y;
	float		z;
}				t_p3d;

/*
** 3D point with direction (AKA a vector)
*/
typedef struct	s_v3d
{
	t_p3d		pos;
	t_p3d		rot;
}				t_v3d;

/*
** A transformation matrix
** (it's actually just a float*)
*/
typedef float	t_mat[4][4];

float			sin_deg(float deg);
float			cos_deg(float deg);

/*
** Maps a value from one range to another
*/
float			ft_fmapf(float n, float s1, float e1, float s2, float e2);
long			ft_lmapl(long n, long s1, long e1, long s2, long e2);
float			ft_lmapf(long n, long s1, long e1, float s2, float e2);
long			ft_fmapl(float n, float s1, float e1, long s2, long e2);

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
t_p3d			p3d_transform(const t_p3d src, const t_mat m);

/*
** Creates a matrix that translates/rotates by the negative position/angle
** of the specified vector
*/
void			mat_from_v3d(t_mat mat_cam, const t_v3d src);

/*
** Projects a 3d point using a camera matrix (use mat_from_v3d to get one)
** Returns 1 if the point is visible, 0 otherwise
*/
int	p3d_project(t_p2d *p_raster, t_p2d r_size, t_p2d c_size, t_p3d p_world,
					const t_mat mat_cam);

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

