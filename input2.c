/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:37:20 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/10 13:15:35 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_angle_x(t_fdf *fdf, int x)
{
	if (fdf->angle_x == 0 && x == -5)
		fdf->angle_x = 355;
	else if (fdf->angle_x == 355 && x == 5)
		fdf->angle_x = 0;
	else
		fdf->angle_x += x;
	draw_iso(fdf);
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->img.img, 0, 0);
}

void	update_angle_y(t_fdf *fdf, int y)
{
	if (fdf->angle_y == 0 && y == -5)
		fdf->angle_y = 355;
	else if (fdf->angle_y == 355 && y == 5)
		fdf->angle_y = 0;
	else
		fdf->angle_y += y;
	draw_iso(fdf);
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->img.img, 0, 0);
}

void	update_angle_z(t_fdf *fdf, int z)
{
	if (fdf->angle_z == 0 && z == -5)
		fdf->angle_z = 355;
	else if (fdf->angle_z == 355 && z == 5)
		fdf->angle_z = 0;
	else
		fdf->angle_z += z;
	draw_iso(fdf);
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->img.img, 0, 0);
}
