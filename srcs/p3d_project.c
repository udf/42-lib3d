/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p3d_project.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 15:37:35 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/25 15:59:12 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_p2d p3d_project(float fov, t_p2d origin, t_p3d p_world, const t_mat mat_cam)
{
	t_p3d p_aligned;
	t_p2d p_screen;

	p_aligned = p3d_transform(p_world, mat_cam);
	if(!p_aligned.z)
		p_aligned.z = 1;
	p_screen.x = fov * p_aligned.x / p_aligned.z + origin.x;
	p_screen.y = fov * p_aligned.y / p_aligned.z + origin.y;
	return (p_screen);
}
