/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:59:19 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/20 17:14:41 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_tx(t_fdf *fdf, int m)
{
	fdf->trans_x += m;
	update_img(fdf);
}

void	update_ty(t_fdf *fdf, int m)
{
	fdf->trans_y += m;
	update_img(fdf);
}

void	update_zoom(t_fdf *fdf, int z)
{
	if (fdf->zoom + z < 0)
		return ;
	fdf->zoom += z;
	update_offset(fdf, &fdf->map);
	update_img(fdf);
}

void	keybinds(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
		close_fdf(fdf);
}

int	input(int keycode, t_fdf *fdf)
{
	keybinds(keycode, fdf);
	return (0);
}
