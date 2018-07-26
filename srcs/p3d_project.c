/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p3d_project.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 15:37:35 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/26 21:58:47 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

int	p3d_project(t_p2d *p_raster, t_p2d r_size, t_p2d c_size, t_p3d p_world,
					const t_mat mat_cam)
{
	t_p3d p_camera;
	t_p2d p_screen;

	p_camera = p3d_transform(p_world, mat_cam);
	if(p_camera.z >= 0)
		return (0);
	p_screen.x = p_camera.x / -p_camera.z;
	p_screen.y = p_camera.y / -p_camera.z;
	if (ABS(p_screen.x) > c_size.x / 2.0f && ABS(p_screen.y) > c_size.y / 2.0f)
		return (0);
	p_raster->x = (p_screen.x / c_size.x + 0.5f) * r_size.x;
	p_raster->y = (p_screen.y / c_size.y + 0.5f) * r_size.y;
	return (1);
}
