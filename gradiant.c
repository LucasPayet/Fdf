/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradiant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:26:07 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/18 13:06:42 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

unsigned char	lerp(unsigned char a, unsigned char b, float t)
{
	return ((unsigned char)(a + t * (b - a)));
}

float	distance(int x0, int y0, int x1, int y1)
{
	return (sqrtf((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0)));
}

int	get_gradiant(t_pixel s, t_pixel e, t_pixel c)
{
	int		color;
	float	total_dist;
	float	curr_dist;
	float	t;

	total_dist = distance(s.x, s.y, e.x, e.y);
	curr_dist = distance(s.x, s.y, c.x, c.y);
	if (total_dist == 0)
		t = 0;
	else
		t = curr_dist / total_dist;
	color = create_trgb(lerp(get_r(s.color), get_r(e.color), t),
			lerp(get_g(s.color), get_g(e.color), t),
			lerp(get_b(s.color), get_b(e.color), t));
	return (color);
}
