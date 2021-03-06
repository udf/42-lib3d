/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p3d_math2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 15:44:47 by mhoosen           #+#    #+#             */
/*   Updated: 2018/09/04 21:39:50 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_p3d		p3d_elem_mult(t_p3d a, t_p3d b)
{
	return (t_p3d){a.x * b.x, a.y * b.y, a.z * b.z};
}

t_p3d		p3d_mult(t_p3d a, float s)
{
	return (t_p3d){a.x * s, a.y * s, a.z * s};
}

t_p3d		p3d_clip(t_p3d p, float min, float max)
{
	p.x = CLAMP(p.x, min, max);
	p.y = CLAMP(p.y, min, max);
	p.z = CLAMP(p.z, min, max);
	return (p);
}

float		p3d_mag(t_p3d p)
{
	return (sqrtf(p.x * p.x + p.y * p.y + p.z * p.z));
}

float		p3d_mag_norm(t_p3d *p)
{
	const float mag = p3d_mag(*p);

	if (fpclassify(mag) == FP_ZERO)
		*p = (t_p3d){0, 0, 0};
	else
		*p = (t_p3d){p->x / mag, p->y / mag, p->z / mag};
	return (mag);
}
