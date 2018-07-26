/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:40:40 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/26 15:39:52 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_fmapf(float n, float s1, float e1, float s2, float e2)
{
	return (s2 + (e2 - s2) * ((n - s1) / (e1 - s1)));
}

long	ft_lmapl(long n, long s1, long e1, long s2, long e2)
{
	return (s2 + (e2 - s2) * ((n - s1) / (e1 - s1)));
}

float	ft_lmapf(long n, long s1, long e1, float s2, float e2)
{
	return (ft_fmapf((float)n, (float)s1, (float)e1, s2, e2));
}

long	ft_fmapl(float n, float s1, float e1, long s2, long e2)
{
	return ((long)ft_fmapf(n, s1, e1, (float)s2, (float)e2));
}
