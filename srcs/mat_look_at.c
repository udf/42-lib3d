/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_look_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 15:43:26 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/27 23:05:30 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

void			mat_look_at(t_mat dest, t_p3d from, t_p3d to)
{
	const t_p3d forward = p3d_norm(p3d_sub(from, to));
	const t_p3d right = p3d_cross((t_p3d){0, 0, 1}, forward);
	const t_p3d up = p3d_cross(forward, right);

	mat_set_row(dest[0], right.x, right.y, right.z, 0);
	mat_set_row(dest[1], up.x, up.y, up.z, 0);
	mat_set_row(dest[2], forward.x, forward.y, forward.z, 0);
	mat_set_row(dest[3], from.x, from.y, from.z, 1);
}
