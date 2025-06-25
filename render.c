/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:31:47 by lupayet           #+#    #+#             */
/*   Updated: 2025/06/24 21:55:16 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <./Gnl/get_next_line.h>

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	update_pixel(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_length * y) + (x * (img->bits_per_pixel / 8));
	(unsigned int)(img->addr + offset) = color;
	return (1);
}

void	draw_line_h(t_img *img, t_pixel tp0, t_pixel tp1)
{
	t_pixel	p0;
	t_pixel	p1;
	if (tp0.x > tp1.x)
	{
		p0 = tp1;
		p1 = tp0;
	}
	else
	{
		p0 = tp0;
		p1 = tp1
	}
}

void	draw_line_v()
{

}

/*
int set_img(char *addr, int fd)
{
	char *line;

	while;
}*/
