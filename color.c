/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:38:43 by lupayet           #+#    #+#             */
/*   Updated: 2025/06/17 18:19:47 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	hex_to_int(char c)
{
	if ('0' <= c && c <= '9') return c - '0';
    if ('a' <= c && c <= 'f') return 10 + (c - 'a');
    if ('A' <= c && c <= 'F') return 10 + (c - 'A');
    return -1;
}

unsigned int	hex_rgb_to_int(char *hex)
{
	unsigned int	i;
	int	d;
	unsigned int	color;
	if (*hex == '#')
		hex++;

	i = 0;
	while (i < 6)
	{
		d = hex_to_int(*hex);
		if (d == -1)
			return (16777215);
		color = (color << 4) | d;
	}
	return (color);
}
