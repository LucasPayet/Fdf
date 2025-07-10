/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:12:28 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/10 16:42:45 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./Gnl/get_next_line.h"

void	clean_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

void	clean_map(t_map *map)
{
	while (map->line)
	{
		free(map->line);
		map->line = get_next_line(map->fd);
	}
	map->line = NULL;
	free(map->pixels);
	map->pixels = NULL;
}

void	clean_img(t_fdf *fdf)
{
	if (fdf->img.img)
		mlx_destroy_image(fdf->mlx.mlx, fdf->img.img);
}

void	clean_fdf(t_fdf *fdf)
{
	clean_map(&fdf->map);
	clean_img(fdf);
}
