/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:59:19 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/03 13:46:51 by lupayet          ###   ########.fr       */
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

int	input(int keycode, t_fdf *fdf)
{
	if (keycode == Esc)
		close_fdf(fdf);
	if (keycode == Left)
		update_tx(fdf, -1);
	if (keycode == Right)
		update_tx(fdf, 1);
	if (keycode == Up)
		update_ty(fdf, -1);
	if (keycode == Down)
		update_ty(fdf, 1);
	return (0);
}
