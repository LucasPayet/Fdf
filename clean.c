/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:12:28 by lupayet           #+#    #+#             */
/*   Updated: 2025/06/17 18:48:32 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_map(t_map *map)
{
	int i;

	i = 0;
	//if (!map->map)
	//	return ;
	while (i < map->height * map->width)
	{	
		free(map->pixels[i]);
		i++;
	}
	free(map->pixels);
}

void	clean_img(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx.mlx, fdf->img.img);
/*	if (fdf->img.img)
	{
		free(fdf->img.img);
		ft_printf("img\n");
	}*/
/*	if (img->addr)
	{
		free(img->addr);
		ft_printf("addr\n");
	}*/
}

void	clean_fdf(t_fdf *fdf)
{
	clean_map(&fdf->map);
	clean_img(fdf);
}
