/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 22:02:35 by lupayet           #+#    #+#             */
/*   Updated: 2025/06/08 23:15:15 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include <stdio.h>

typedef struct	s_app
{
	void	*mlx;
	void	*win;
}				t_app;

int	close(t_app *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main()
{
	t_app	fdf;

	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 500, 400, "test");

	mlx_key_hook(fdf.win, &close, &fdf);
	mlx_loop(fdf.mlx);
}
