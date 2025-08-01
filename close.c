/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 00:05:10 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/10 16:21:42 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_fdf(t_fdf *fdf)
{
	clean_fdf(fdf);
	if (fdf->mlx.mlx)
	{
		if (fdf->mlx.win)
		{
			mlx_destroy_window(fdf->mlx.mlx, fdf->mlx.win);
			mlx_destroy_display(fdf->mlx.mlx);
			free(fdf->mlx.mlx);
		}
	}
	exit(0);
	return (0);
}
