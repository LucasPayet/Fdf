/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:31:47 by lupayet           #+#    #+#             */
/*   Updated: 2025/06/26 14:42:03 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./Gnl/get_next_line.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	update_pixel(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_length * y) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = color;
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

	ft_printf("%d, %d\n", p0.x, p0.y);
	dx = abs(p1.x - p0.x);
	dy = abs(p1.y - p0.y);
	sx = (p0.x < p1.x) ? 1 : -1;
    sy = (p0.y < p1.y) ? 1 : -1;
	d = dx - dy;

	while(1)
	{
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
	while(i < fdf->map.width * fdf->map.height)
	{
		if (i + 1 < fdf->map.width * fdf->map.height)
			draw_line(img, iso_proj(fdf, pixels[i]), iso_proj(fdf, pixels[i + 1]));
		if (i + fdf->map.width  < fdf->map.width * fdf->map.height)
			draw_line(img, iso_proj(fdf, pixels[i]), iso_proj(fdf, pixels[i + fdf->map.width]));
		i++;
	}
	return (1);
}
