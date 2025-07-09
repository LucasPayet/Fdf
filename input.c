/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:59:19 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/09 23:24:58 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_tx(t_fdf *fdf, int m)
{
	fdf->trans_x += m;
	draw_iso(fdf);
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->img.img, 0, 0);
}

void	update_ty(t_fdf *fdf, int m)
{
	fdf->trans_y += m;
	draw_iso(fdf);
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->img.img, 0, 0);
}

void	update_zoom(t_fdf *fdf, int z)
{
	fdf->zoom += z;
	draw_iso(fdf);
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->img.img, 0, 0);
}

int	input(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
		close_fdf(fdf);
	if (keycode == LEFT)
		update_tx(fdf, 1);
	if (keycode == RIGHT)
		update_tx(fdf, -1);
	if (keycode == UP)
		update_ty(fdf, 1);
	if (keycode == DOWN)
		update_ty(fdf, -1);
	if (keycode == ADD)
		update_zoom(fdf, 1);
	if (keycode == SUB)
		update_zoom(fdf, -1);
	return (0);
}
