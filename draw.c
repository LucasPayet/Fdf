/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:26:20 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/11 00:17:14 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	draw_loop()
{
}

void	draw_line(t_img *img, t_pixel p0, t_pixel p1)
{
	int	dx;
	int dy;
	int	sx;
	int	sy;
	int	d;
	int d2;
	
	dx = ft_abs(p1.x - p0.x);
	dy = ft_abs(p1.y - p0.y);
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

void	draw_line(t_img *img, t_pixel p0, t_pixel p1)
{
	if (ft_abs(p1.x - p0.x) < ft_abs(p1.y - p0.y))
		draw_line_h(img, p0, p1);
	else
		draw_line_v(img, p1, p0);
}
