/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_vec_mult.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:52:36 by mhoosen           #+#    #+#             */
/*   Updated: 2018/08/30 15:10:46 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_p3d	mat_vec_mult(const t_p3d src, const t_mat m)
{
	float w;
	t_p3d out;

	out.x = src.x * m[0][0] + src.y * m[1][0] + src.z * m[2][0] + m[3][0];
	out.y = src.x * m[0][1] + src.y * m[1][1] + src.z * m[2][1] + m[3][1];
	out.z = src.x * m[0][2] + src.y * m[1][2] + src.z * m[2][2] + m[3][2];
	w = src.x * m[0][3] + src.y * m[1][3] + src.z * m[2][3] + m[3][3];
	out.x = out.x / w;
	out.y = out.y / w;
	out.z = out.z / w;
	return (out);
}
