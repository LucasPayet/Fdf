/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:12:28 by lupayet           #+#    #+#             */
/*   Updated: 2025/06/23 20:16:58 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./Gnl/get_next_line.h"

void	clean_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

void	clean_map(t_map *map)
{
	while (map->line)
	{
		free(map->line);
		map->line = get_next_line(map->fd);
	}
	map->line = NULL;
	clean_split(map->split);
	free(map->pixels);
	map->pixels = NULL;
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
