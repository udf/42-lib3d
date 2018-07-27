/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_trig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:10:55 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/27 10:14:09 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

float sin_deg(float deg)
{
	const float pi_over_180 = (float)(M_PI / 180.0);

	return (sinf(deg * pi_over_180));
}

float cos_deg(float deg)
{
	const float pi_over_180 = (float)(M_PI / 180.0);

	return (cosf(deg * pi_over_180));
}
