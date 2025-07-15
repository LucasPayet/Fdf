/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:59:19 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/15 11:28:10 by lupayet          ###   ########.fr       */
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
	if (fdf->zoom + z < 0)
		return ;
	fdf->zoom += z;
	update_offset(fdf, &fdf->map);
	draw_iso(fdf);
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->img.img, 0, 0);
}

void	keybinds(int keycode, t_fdf *fdf)
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
}

int	input(int keycode, t_fdf *fdf)
{
	keybinds(keycode, fdf);
	if (keycode == X_A)
		update_angle_x(fdf, 5);
	if (keycode == X_S)
		update_angle_x(fdf, -5);
	if (keycode == Y_A)
		update_angle_y(fdf, 5);
	if (keycode == Y_S)
		update_angle_y(fdf, -5);
	if (keycode == Z_A)
		update_angle_z(fdf, 5);
	if (keycode == Z_S)
		update_angle_z(fdf, -5);
	if (keycode == ISO)
	{
		fdf->proj = iso_proj;
		update_offset(fdf, &fdf->map);
		draw_iso(fdf);
		mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->img.img, 0, 0);
	}
	if (keycode == PARA)
	{
		fdf->proj = para_proj;
		update_offset(fdf, &fdf->map);
		draw_iso(fdf);
		mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->img.img, 0, 0);
	}
	return (0);
}
