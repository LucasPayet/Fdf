/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:31:47 by lupayet           #+#    #+#             */
/*   Updated: 2025/06/17 16:27:27 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <./Gnl/get_next_line.h>

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_lin_h(t_img *img, int x, int y, int color)
{
	if ()
}

int	update_pixel(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_length * y) + (x * (img->bits_per_pixel / 8));
	(unsigned int)(img->addr + offset) = color;
	return (1);
}
/*
int set_img(char *addr, int fd)
{
	char *line;

	while;
}*/
