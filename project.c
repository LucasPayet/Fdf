/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:58:38 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/09 00:06:58 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_pixel rotate(t_pixel p, t_fdf *fdf) {
    t_pixel tmp;
	float	x;
	float	y;
	float	z;

	x = fdf->angle_x * M_PI/180;
	y = fdf->angle_y * M_PI/180;
	z = fdf->angle_z * M_PI/180;
	tmp.y = p.y * cos(x) - p.z * sin(x);
	tmp.z = p.y * sin(x) + p.z * cos(x);
	tmp.x = p.x;
	p.x = tmp.x * cos(y) + tmp.z * sin(y);
	p.z = -tmp.x * sin(y) + tmp.z * cos(y);
	p.y = tmp.y;
	tmp.x = p.x * cos(z) - p.y * sin(z);
	tmp.y = p.x * sin(z) + p.y * cos(z);
	tmp.z = p.z;
	return tmp;
}

t_pixel	iso_proj(t_fdf *fdf, t_pixel p)
{
	t_pixel np;

	p.x *= fdf->zoom;
	p.y *= fdf->zoom;
	p.z *= 4;
	p = rotate(p, fdf);
	np.x = (p.x - p.y) * cos(30 * M_PI/180);
	np.y = (p.x + p.y) * cos(30 * M_PI/180) - p.z;
	np.x = np.x + fdf->offset_x + fdf->trans_x * (fdf->img.x_len / 100);
	np.y = np.y + fdf->offset_y + fdf->trans_y * (fdf->img.y_len / 100);
	np.color = p.color;
	return (np);
}
