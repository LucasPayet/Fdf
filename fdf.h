/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:20:05 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/15 13:43:13 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibx-linux/mlx.h"
# include "s_fdf.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define ESC	0xff1b
# define ADD 0x003d
# define SUB 0x002d
# define LEFT 0x0061 
# define UP 0x0077
# define RIGHT 0x0064
# define DOWN 0x0073
# define X_A 0xff53
# define X_S 0xff51
# define Y_A 0xff52
# define Y_S 0xff54
# define Z_A 0x002e
# define Z_S 0x002c
# define ISO 0x0031
# define PARA 0x0032
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define ZOOM 20
# define ANGLE_X 0
# define ANGLE_Y 0
# define ANGLE_Z 0

int				input(int keycode, t_fdf *vars);
void			clean_fdf(t_fdf *fdf);
int				close_fdf(t_fdf *fdf);
int				map_init(char *path, t_fdf *fdf);
unsigned int	hex_rgb_to_int(char *hex);
void			clean_split(char **split);
t_pixel			iso_proj(t_fdf *fdf, t_pixel p);
t_pixel			para_proj(t_fdf *fdf, t_pixel p);
void			update_offset(t_fdf *fdf, t_map *map);
int				draw_iso(t_fdf *fdf);
void			update_angle_x(t_fdf *fdf, int x);
void			update_angle_y(t_fdf *fdf, int y);
void			update_angle_z(t_fdf *fdf, int z);
int				ft_abs(int n);
int				slope(int n0, int n1);
#endif
