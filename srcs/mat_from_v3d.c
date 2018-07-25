/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_from_v3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:05:01 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/25 21:52:40 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

void	mat_from_v3d(t_mat mat_cam, const t_v3d src)
{
	mat_set_identity(mat_cam);
	mat_translate(mat_cam, -src.pos.x, -src.pos.y, -src.pos.z);
	mat_rotate_xyz(mat_cam, -src.rot.x, -src.rot.y, -src.rot.z);
}
