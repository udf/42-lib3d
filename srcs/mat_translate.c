/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l3d_mat_translate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 10:57:56 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/25 12:24:06 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

void mat_translate(t_mat dest, float x, float y, float z)
{
	t_mat m_trans;
	t_mat tmp;

	mat_set_row(m_trans[0], 1, 0, 0, 0);
	mat_set_row(m_trans[1], 0, 1, 0, 0);
	mat_set_row(m_trans[2], 0, 0, 1, 0);
	mat_set_row(m_trans[3], x, y, z, 1);
	mat_mult(dest, m_trans, tmp);
	mat_copy(dest, tmp);
}
