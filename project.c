/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:58:38 by lupayet           #+#    #+#             */
/*   Updated: 2025/06/26 14:10:47 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_pixel rotate(t_pixel p, t_fdf *fdf) {
    t_pixel tmp;

	tmp.y = p.y * cos(fdf->angle_x) - p.z * sin(fdf->angle_x);
	tmp.z = p.y * sin(fdf->angle_x) + p.z * cos(fdf->angle_x);
	tmp.x = p.x;
	p.x = tmp.x * cos(fdf->angle_y) + tmp.z * sin(fdf->angle_y);
	p.z = -tmp.x * sin(fdf->angle_y) + tmp.z * cos(fdf->angle_y);
	p.y = tmp.y;
	tmp.x = p.x * cos(fdf->angle_z) - p.y * sin(fdf->angle_z);
	tmp.y = p.x * sin(fdf->angle_z) + p.y * cos(fdf->angle_z);
	tmp.z = p.z;
	return tmp;
}

t_pixel	iso_proj(t_fdf *fdf, t_pixel p)
{
	t_pixel np;

	p = rotate(p, fdf);
	np.x = (p.x - p.y) * cos(30 * M_PI/180);
	np.y = (p.x + p.y) * cos(30 * M_PI/180) - p.z;
	np.x = np.x * fdf->zoom + fdf->offset_x;
	np.y = np.y * fdf->zoom + fdf->offset_y;
	np.color = p.color;
	return (np);
}
