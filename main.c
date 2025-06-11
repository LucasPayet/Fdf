/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 22:02:35 by lupayet           #+#    #+#             */
/*   Updated: 2025/06/11 00:42:15 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define WIN_WIDTH 1000
#define WIN_HEIGHT 1000

int	main()
{
	t_fdf	fdf;
	t_img	img;
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, WIN_WIDTH, WIN_HEIGHT, "test");
	img.img = mlx_new_image(fdf.mlx);
	mlx_put_image_to_window(fdf.mlx, fdf.win, );
	mlx_key_hook(fdf.win, input, &fdf);
	mlx_loop(fdf.mlx);
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
