/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 00:05:10 by lupayet           #+#    #+#             */
/*   Updated: 2025/06/12 19:39:35 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_fdf(char *msg, int fd, t_fdf *fdf)
{
	clean_fdf(fdf);
	mlx_clear_window(fdf->mlx.mlx, fdf->mlx.win);
	mlx_destroy_window(fdf->mlx.mlx, fdf->mlx.win);
	mlx_destroy_display(fdf->mlx.mlx);
	free(fdf->mlx.mlx);
	if (msg)
		ft_putstr_fd(msg, fd);
	exit(0);
}
