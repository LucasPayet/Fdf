/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 22:02:35 by lupayet           #+#    #+#             */
/*   Updated: 2025/06/26 14:33:00 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

#define WIN_WIDTH 1000
#define WIN_HEIGHT 1000
#define ZOOM 50
#define ANGLE_X 0.5
#define	ANGLE_Y 0.5
#define ANGLE_Z 0

void info(t_fdf *fdf)
{
	int	i;

	i = 0;
	ft_printf("###MLX###\nmlx_p => %p;\nwin_p => %p;\n", fdf->mlx.mlx, fdf->mlx.win);
	ft_printf("\n###MAP###\nwidth => %d;\nheight => %d;\nmap_p => %p;\n", fdf->map.width, fdf->map.height, fdf->map.pixels);
	while (i < fdf->map.height * fdf->map.width)
	{
		if (!(i % fdf->map.width))
			ft_printf("\n");
		ft_printf("(%d, %d, %d, %x);\n", fdf->map.pixels[i].x, fdf->map.pixels[i].y, fdf->map.pixels[i].z, fdf->map.pixels[i].color);
		i++;
	}
	ft_printf("\n###IMG###\nimg_p => %p;\naddr => %p;\nbits_p_pixel => %d;\nline_length => %d;\nendian => %d;\n", fdf->img.img, fdf->img.addr, fdf->img.bits_per_pixel, fdf->img.line_length, fdf->img.endian);
}

void	fdf_init(t_fdf *fdf)
{
	fdf->zoom = ZOOM;
	fdf->angle_x = ANGLE_X;
	fdf->angle_y = ANGLE_Y;
	fdf->angle_z = ANGLE_Z;
	fdf->offset_x = WIN_WIDTH / 2;
	fdf->offset_y = WIN_HEIGHT / 2;
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
	fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bits_per_pixel, &fdf.img.line_length, &fdf.img.endian);
	map_init(av[1], &fdf);
	draw_iso(&fdf);
	mlx_put_image_to_window(fdf.mlx.mlx, fdf.mlx.win, fdf.img.img, 0, 0);
	info(&fdf);
	mlx_key_hook(fdf.mlx.win, input, &fdf);
	mlx_hook(fdf.mlx.win, 17, 0, close_fdf, &fdf);
	mlx_loop(fdf.mlx.mlx);
	return (0);
}

/*
#define WIDTH 800
#define HEIGHT 600
#define ESC_KEY 65307 // Use 53 for macOS

typedef struct s_data {
    void *mlx;
    void *win;
} t_data;

int handle_keypress(int keycode, t_data *data)
{
    if (keycode == ESC_KEY)
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    return (0);
}

int main(void)
{
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Press ESC to Exit");

    mlx_key_hook(data.win, (int (*)(int, void *))handle_keypress, &data);
    mlx_loop(data.mlx);
    return (0);
}*/
