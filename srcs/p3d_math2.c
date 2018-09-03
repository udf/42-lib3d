/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p3d_math2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 15:44:47 by mhoosen           #+#    #+#             */
/*   Updated: 2018/09/03 20:32:18 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

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
