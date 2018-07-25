/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l3d_trig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:10:55 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/25 14:25:20 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

static t_cachtay gen_cache(float (*func)(float))
{
	size_t i;
	t_cachtay cach;
	float x;

	i = 0;
	while (i < CACHTAY_SIZE)
	{
		x = ft_lmapf((long)(i + 1), 1, (long)CACHTAY_SIZE, 0, (float)(2*M_PI));
		cach.e[i] = func(x);
		i++;
	}
	return (cach);
}

float fast_sin(float deg)
{
	static t_cachtay cach = {{999.0}};
	size_t index;

	if (cach.e[0] >= 900)
		cach = gen_cache(sinf);
	index = (size_t)ft_fmapl(ABS(fmodf(deg, 360.0)), 0, 359, 0, CACHTAY_SIZE-1);
	return (cach.e[index]);
}

float fast_cos(float deg)
{
	static t_cachtay cach = {{999.0}};
	size_t index;

	if (cach.e[0] >= 900)
		cach = gen_cache(cosf);
	index = (size_t)ft_fmapl(ABS(fmodf(deg, 360.0)), 0, 359, 0, CACHTAY_SIZE-1);
	return (cach.e[index]);
}
