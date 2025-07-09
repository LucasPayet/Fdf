/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:31:47 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/09 11:46:02 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./Gnl/get_next_line.h"

void	update_offset(t_fdf *fdf, t_map *map)
{
	t_pixel	xy[4];
	int	minmax[4];
	int	i;

	xy[0] = iso_proj(fdf, map->pixels[0]);
	xy[1] = iso_proj(fdf, map->pixels[map->width - 1]);
	xy[2] = iso_proj(fdf, map->pixels[map->width * (map->height - 1) - 1]);
	xy[3] = iso_proj(fdf, map->pixels[map->width * map->height - 1]);
	minmax[0] = xy[0].x;
	minmax[1] = xy[0].x;
	minmax[2] = xy[0].y;
	minmax[3] = xy[0].y;
	i = 1;

	while (i < 3)
	{
		if (xy[i].x <= minmax[0]) minmax[0] = xy[i].x;
        if (xy[i].x >= minmax[1]) minmax[1] = xy[i].x;
        if (xy[i].y <= minmax[2]) minmax[2] = xy[i].y;
        if (xy[i].y >= minmax[3]) minmax[3] = xy[i].y;
		i++;
	}
	fdf->img.x_len = minmax[1] - minmax[0];
	fdf->img.y_len = minmax[3] - minmax[2];
	fdf->offset_x = (WIN_WIDTH - (minmax[1] - minmax[0])) / 2;
	fdf->offset_y = (WIN_HEIGHT - (minmax[3] - minmax[2])) / 2;
}

int	update_pixel(t_img *img, int x, int y, int color)
{
	int	offset;
	(void)color;
	offset = (img->line_length * y) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = 16711680;
	return (1);
}

void	draw_line(t_img *img, t_pixel p0, t_pixel p1)
{
	int	dx;
	int dy;
	int	sx;
	int	sy;
	int	d;
	int d2;
	
	dx = abs(p1.x - p0.x);
	dy = abs(p1.y - p0.y);
	sx = (p0.x < p1.x) ? 1 : -1;
    sy = (p0.y < p1.y) ? 1 : -1;
	d = dx - dy;

	while(1)
	{
		if (!(p0.y >= WIN_HEIGHT || p0.x >= WIN_WIDTH || p0.y < 0 || p0.x < 0))
			update_pixel(img, p0.x, p0.y, p0.color);
		if (p0.x == p1.x && p0.y == p1.y)
			break;
		d2 = 2 * d;
		if (d2 > -dy) {d -= dy; p0.x += sx;}
        if (d2 < dx) {d += dx; p0.y += sy;}
	}
}

int	draw_iso(t_fdf *fdf)
{
	int		i;
	t_pixel	*pixels;
	t_img	*img;

	i = 0;
	pixels = fdf->map.pixels;
	img = &fdf->img;
	update_offset(fdf, &fdf->map);
	ft_printf("%d ][ %d\n", fdf->img.x_len, fdf->img.y_len);
	ft_bzero(img->addr, (size_t)(1000 * 1000 * 4));
	while(i < fdf->map.width * fdf->map.height)
	{
		if (i + 1 < fdf->map.width * fdf->map.height && (i + 1) % fdf->map.width != 0)
			draw_line(img, iso_proj(fdf, pixels[i]), iso_proj(fdf, pixels[i + 1]));
		if (i + fdf->map.width  < fdf->map.width * fdf->map.height)
			draw_line(img, iso_proj(fdf, pixels[i]), iso_proj(fdf, pixels[i + fdf->map.width]));
		i++;
	}
	return (1);
}
