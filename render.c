/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:31:47 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/11 16:39:00 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./Gnl/get_next_line.h"

void	update_offset(t_fdf *fdf, t_map *map)
{
	t_pixel	xy[4];

	xy[0] = (*fdf->proj)(fdf, map->pixels[0]);
	xy[1] = (*fdf->proj)(fdf, map->pixels[map->width - 1]);
	xy[2] = (*fdf->proj)(fdf, map->pixels[map->width * (map->height - 1) - 1]);
	xy[3] = (*fdf->proj)(fdf, map->pixels[map->width * map->height - 1]);
	fdf->img.x_len = xy[1].x - xy[0].x;
	fdf->img.y_len = xy[2].y - xy[0].y;
	fdf->offset_x = (WIN_WIDTH) / 2;
	fdf->offset_y = (WIN_HEIGHT - (xy[2].y - xy[0].y)) / 2;
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
	t_draw	dr;
	
	dr.dx = ft_abs(p1.x - p0.x);
	dr.dy = ft_abs(p1.y - p0.y);
	dr.sx = slope(p0.x, p1.x);
    dr.sy = slope(p0.y, p1.y);
	dr.d = dr.dx - dr.dy;
	while(1)
	{
		if (!(p0.y >= WIN_HEIGHT || p0.x >= WIN_WIDTH || p0.y < 0 || p0.x < 0))
			update_pixel(img, p0.x, p0.y, p0.color);
		if (p0.x == p1.x && p0.y == p1.y)
			break;
		dr.d2 = 2 * dr.d;
		if (dr.d2 > -dr.dy)
		{
			dr.d -= dr.dy; 
			p0.x += dr.sx;
		}
        if (dr.d2 < dr.dx)
		{
			dr.d += dr.dx;
			p0.y += dr.sy;
		}
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
	ft_bzero(img->addr, (size_t)(1000 * 1000 * 4));
	while(i < fdf->map.width * fdf->map.height)
	{
		if (i + 1 < fdf->map.width * fdf->map.height && (i + 1) % fdf->map.width != 0)
			draw_line(img, (*fdf->proj)(fdf, pixels[i]), (*fdf->proj)(fdf, pixels[i + 1]));
		if (i + fdf->map.width  < fdf->map.width * fdf->map.height)
				draw_line(img, (*fdf->proj)(fdf, pixels[i]), (*fdf->proj)(fdf, pixels[i + fdf->map.width]));
		i++;
	}
	return (1);
}
