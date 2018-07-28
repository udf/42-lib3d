/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_from_v3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:05:01 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/28 20:37:49 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

void	mat_from_v3d(t_mat mat_cam, const t_p3d pos, const t_p3d rot)
{
	mat_set_identity(mat_cam);
	mat_translate(mat_cam, -pos.x, -pos.y, -pos.z);
	mat_rotate_xyz(mat_cam, -rot.x, -rot.y, -rot.z);
}
