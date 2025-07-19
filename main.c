/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 22:02:35 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/19 20:20:35 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_init(t_fdf *fdf)
{
	fdf->proj = 1;
	fdf->zoom = ZOOM;
	fdf->def_zoom = ZOOM;
	fdf->angle_x = ANGLE_X;
	fdf->angle_y = ANGLE_Y;
	fdf->angle_z = ANGLE_Z;
	fdf->offset_x = 0;
	fdf->offset_y = 0;
	fdf->trans_x = 0;
	fdf->trans_y = 0;
	fdf->img.x_len = 0;
	fdf->img.y_len = 0;
	fdf->z_mod = 0;
	fdf->map.line = NULL;
	fdf->map.pixels = NULL;
}

void	set_proj(t_fdf *fdf)
{
	update_offset(fdf, &fdf->map);
	draw_img(fdf);
	if (fdf->img.x_len > fdf->img.y_len)
		fdf->zoom = (WIN_HEIGHT - 50) / (fdf->map.width
				+ (fdf->img.x_len / fdf->map.width));
	else
		fdf->zoom = (WIN_WIDTH - 50) / (fdf->map.height
				+ (fdf->img.y_len / fdf->map.height));
	fdf->def_zoom = fdf->zoom;
	update_offset(fdf, &fdf->map);
	draw_img(fdf);
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->img.img, 0, 0);
}

int	main(int ac, char *av[])
{
	t_fdf	fdf;

	if (ac != 2)
	{
		ft_putstr_fd("Wrong input", 2);
		return (1);
	}
	fdf_init(&fdf);
	fdf.mlx.mlx = mlx_init();
	fdf.mlx.win = mlx_new_window(fdf.mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "test");
	fdf.img.img = mlx_new_image(fdf.mlx.mlx, 1000, 1000);
	fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bits_per_pixel,
			&fdf.img.line_length, &fdf.img.endian);
	map_init(av[1], &fdf);
	set_proj(&fdf);
	mlx_key_hook(fdf.mlx.win, input, &fdf);
	mlx_hook(fdf.mlx.win, 17, 0, close_fdf, &fdf);
	mlx_loop(fdf.mlx.mlx);
	return (0);
}
