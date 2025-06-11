/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_fdf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:39:00 by lupayet           #+#    #+#             */
/*   Updated: 2025/06/11 11:31:44 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
}	t_fdf;

typedef struct s_map
{
	int	width;
	int	height;
}	t_map;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;
