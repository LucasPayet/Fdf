/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_fdf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:39:00 by lupayet           #+#    #+#             */
/*   Updated: 2025/06/18 13:40:41 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_pixel
{
	int	x;
	int y;
	int	z;
	int	color;
}	t_pixel;

typedef struct s_map
{
	int	width;
	int	height;
	t_pixel	*pixels;
}	t_map;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct	s_fdf
{
	t_mlx	mlx;
	t_map	map;
	t_img	img;
	int		zoom;
	int		offset_x;
	int		offset_y;
	int		angle;
}	t_fdf;
