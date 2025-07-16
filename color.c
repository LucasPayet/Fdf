/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:38:43 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/16 18:18:00 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hex_to_int(char c)
{
	if ('0' <= c && c <= '9')
		return (c - '0');
	if ('a' <= c && c <= 'f')
		return (10 + (c - 'a'));
	if ('A' <= c && c <= 'F')
		return (10 + (c - 'A'));
	return (-1);
}

int	hex_rgb_to_int(char *hex)
{
	int	i;
	int	d;
	int	color;

	i = 0;
	if (hex[i] == '0')
		i++;
	if (hex[i] == 'x')
		i++;
	color = 0;
	while (i <= 7)
	{
		d = hex_to_int(hex[i]);
		ft_printf("%d ", d);
		if (d == -1)
			return (16777215);
		color = (color << 4) | d;
		i++;
	}
	ft_printf("\n%d > %x\n", color, color);
	return (color);
}
