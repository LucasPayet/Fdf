/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 23:42:02 by lupayet           #+#    #+#             */
/*   Updated: 2025/06/10 00:02:23 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	map_init(int	fd)
{
	char	*line;
	s_map	map;
	int		tmp;

	map.x = 0;
	map.y = 0;
	get_next_line(fd);
	while (line)
	{
		tmp = ft_strlen(line);
		if 
	}
}
