/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 23:42:02 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/10 01:34:07 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./Gnl/get_next_line.h"

static int	count_word(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (*str != c && *str != '\0' && c != '\0')
		count++;
	while (str[i])
	{
		if (str[i] != c && str[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

int	map_height(char *path)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	set_pixel(t_map *map, int l, char **value)
{
	char	*sep;
	char	z[13];
	int		i;

	i = 0;
	while (value[i])
	{
		sep = ft_strchr(value[i], ',');
		if (!sep)
		{
			map->pixels[l + i].z = ft_atoi(value[i]);
		}
		else
		{
			ft_strlcpy(z, value[i], (sep - value[i]));
			map->pixels[l + i].z = ft_atoi(z);
			map->pixels[l + i].color = hex_rgb_to_int(++sep);
		}
		map->pixels[l + i].x = i;
		map->pixels[l + i].y = (l / map->width);
		i++;
	}
	return (l + i);
}

void	set_pixels(char *path, t_map *map, t_fdf *fdf)
{
	int		l;
	int		tmp;

	map->fd = open(path, O_RDONLY);
	map->line = get_next_line(map->fd);
	map->width = count_word(map->line, ' ');
	map->pixels = malloc(sizeof(t_pixel) * map->height * map->width);
	if (!map->pixels)
		close_fdf(fdf);
	l = 0;
	while (map->line)
	{
		tmp = count_word(map->line, ' ');
		if (map->width != tmp)
			close_fdf(fdf);
		map->split = ft_split(map->line, ' ');
		l = set_pixel(map, l, map->split);
		free(map->line);
		clean_split(map->split);
		map->line = get_next_line(map->fd);
	}
	close(map->fd);
}

int	map_init(char *path, t_fdf *fdf)
{
	t_map	*map;

	map = &fdf->map;
	map->height = map_height(path);
	set_pixels(path, map, fdf);
	return (1);
}
