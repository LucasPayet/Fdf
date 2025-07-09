/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:59:19 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/09 16:06:14 by lupayet          ###   ########.fr       */
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
	if (fdf->def_zoom / 10 < 1)
		fdf->zoom += z;
	else
		fdf->zoom += z * fdf->def_zoom / 10;
	ft_printf("%d\n", fdf->zoom);
	draw_iso(fdf);
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->img.img, 0, 0);
}

int	input(int keycode, t_fdf *fdf)
{
	if (keycode == Esc)
		close_fdf(fdf);
	if (keycode == Left)
		update_tx(fdf, 1);
	if (keycode == Right)
		update_tx(fdf, -1);
	if (keycode == Up)
		update_ty(fdf, 1);
	if (keycode == Down)
		update_ty(fdf, -1);
	if (keycode == Add)
		update_zoom(fdf, 1);
	if (keycode == Sub)
		update_zoom(fdf, -1);
	return (0);
}
