/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l3d_v3d_transform.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 10:57:56 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/25 12:18:32 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_v3d v3d_transform(const t_v3d src, const t_mat m)
{
	t_v3d out;
	out.x = src.x * m[0][0] + src.y * m[1][0] + src.z * m[2][0] + m[3][0];
	out.y = src.x * m[0][1] + src.y * m[1][1] + src.z * m[2][1] + m[3][1];
	out.z = src.x * m[0][2] + src.y * m[1][2] + src.z * m[2][2] + m[3][2];
	return (out);
}
