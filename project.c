/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:58:38 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/16 14:29:09 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_pixel	rotate(t_pixel p, t_fdf *fdf)
{
	t_pixel	tmp;
	t_rot	rt;

	rt.cx = ((fdf->map.width - 1) * fdf->zoom) / 2;
	rt.cy = ((fdf->map.height - 1) * fdf->zoom) / 2;
	rt.x = fdf->angle_x * M_PI / 180;
	rt.y = fdf->angle_y * M_PI / 180;
	rt.z = fdf->angle_z * M_PI / 180;
	p.y -= rt.cy;
	p.x -= rt.cx;
	tmp.y = p.y * cos(rt.x) - p.z * sin(rt.x);
	tmp.z = p.y * sin(rt.x) + p.z * cos(rt.x);
	tmp.x = p.x;
	p.x = tmp.x * cos(rt.y) + tmp.z * sin(rt.y);
	p.z = -tmp.x * sin(rt.y) + tmp.z * cos(rt.y);
	p.y = tmp.y;
	tmp.x = p.x * cos(rt.z) - p.y * sin(rt.z);
	tmp.y = p.x * sin(rt.z) + p.y * cos(rt.z);
	tmp.z = p.z;
	tmp.x += rt.cx;
	tmp.y += rt.cy;
	return (tmp);
}

t_pixel	iso_proj(t_fdf *fdf, t_pixel p)
{
	t_pixel	np;

	p.x *= fdf->zoom;
	p.y *= fdf->zoom;
	p.z *= fdf->zoom + fdf->z_mod;
	p = rotate(p, fdf);
	np.x = (p.x - p.y) * cos(30 * M_PI / 180);
	np.y = (p.x + p.y) * cos(30 * M_PI / 180) - p.z;
	np.x = np.x + fdf->offset_x + fdf->trans_x * (fdf->img.x_len / 100);
	np.y = np.y + fdf->offset_y + fdf->trans_y * (fdf->img.y_len / 100);
	np.color = p.color;
	return (np);
}

t_pixel	para_proj(t_fdf *fdf, t_pixel p)
{
	t_pixel	np;

	p.x *= fdf->zoom;
	p.y *= fdf->zoom;
	p.z *= fdf->zoom;
	p = rotate(p, fdf);
	np.x = p.x;
	np.y = p.y;
	np.x = np.x + fdf->offset_x + fdf->trans_x * (fdf->img.x_len / 100);
	np.y = np.y + fdf->offset_y + fdf->trans_y * (fdf->img.y_len / 100);
	np.color = p.color;
	return (np);
}
