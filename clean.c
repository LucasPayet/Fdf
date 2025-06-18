/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:12:28 by lupayet           #+#    #+#             */
/*   Updated: 2025/06/18 14:37:48 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_map(t_map *map)
{
	//if (!map->map)
	//	return ;
/*	while (i < map->height * map->width)
	{	
		free(map->pixels[i]);
		i++;
	}*/
	free(map->pixels);
}

void	clean_img(t_fdf *fdf)
{
	if (fdf->img.img)
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
