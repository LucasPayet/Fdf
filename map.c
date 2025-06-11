/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 23:42:02 by lupayet           #+#    #+#             */
/*   Updated: 2025/06/11 16:15:53 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= )
}

static int	ft_linecheck(char *str)
{
	int	c;
	
	c = 0;
	while(*str && *str != '\n')
	{
		if (!is_digit(*str))	
		{
			ft_putstr_fd("Wrong map", 2);
			exit(0);
		}
		c++;
	}
	return (c);
}

int	map_init(int fd)
{
	char	*line;
	s_map	map;
	int		tmp;

	map.x = 0;
	map.y = 0;
	line = get_next_line(fd);
	map.x = ft_linecheck(line);
	while (line)
	{
		tmp = ft_linecheck(line);
		if (temp != map.x)
		{
			ft_putstr_fd("Wrong map", 2);
			exit(0);
		}
		line = get_next_line(line);
	}
	return (1);
}
