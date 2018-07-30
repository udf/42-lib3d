/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 10:57:56 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/29 03:53:17 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

void mat_rotate_x(t_mat dest, float x)
{
	t_mat m_trans;
	t_mat tmp;
	const float cosx = cos_deg(x);
	const float sinx = sin_deg(x);

	mat_set_row(m_trans[0],     1,     0,    0,     0);
	mat_set_row(m_trans[1],     0,  cosx, sinx,     0);
	mat_set_row(m_trans[2],     0, -sinx, cosx,     0);
	mat_set_row(m_trans[3],     0,     0,    0,     1);
	mat_mult(dest, m_trans, tmp);
	mat_copy(dest, tmp);
}

void mat_rotate_y(t_mat dest, float y)
{
	t_mat m_trans;
	t_mat tmp;
	const float cosy = cos_deg(y);
	const float siny = sin_deg(y);

	mat_set_row(m_trans[0],  cosy,     0, -siny,     0);
	mat_set_row(m_trans[1],     0,     1,     0,     0);
	mat_set_row(m_trans[2],  siny,     0,  cosy,     0);
	mat_set_row(m_trans[3],     0,     0,     0,     1);
	mat_mult(dest, m_trans, tmp);
	mat_copy(dest, tmp);
}

void mat_rotate_z(t_mat dest, float z)
{
	t_mat m_trans;
	t_mat tmp;
	const float cosz = cos_deg(z);
	const float sinz = sin_deg(z);

	mat_set_row(m_trans[0],  cosz,  sinz,     0,     0);
	mat_set_row(m_trans[1], -sinz,  cosz,     0,     0);
	mat_set_row(m_trans[2],     0,     0,     1,     0);
	mat_set_row(m_trans[3],     0,     0,     0,     1);
	mat_mult(dest, m_trans, tmp);
	mat_copy(dest, tmp);
}

void mat_rotate_xyz(t_mat dest, float x, float y, float z)
{
	mat_rotate_x(dest, x);
	mat_rotate_y(dest, y);
	mat_rotate_z(dest, z);
}
