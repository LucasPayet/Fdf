/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:20:05 by lupayet           #+#    #+#             */
/*   Updated: 2025/06/30 16:50:36 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "./minilibx-linux/mlx.h"
#include "s_fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define Esc	0xff1b
#define WIN_WIDTH 1000
#define WIN_HEIGHT 1000
#define ZOOM 10
#define ANGLE_X 0.5
#define	ANGLE_Y 0.5
#define ANGLE_Z 0

int 			input(int keycode, t_fdf *vars);
void			clean_fdf(t_fdf *fdf);
int				close_fdf(t_fdf *fdf);
int				map_init(char *path, t_fdf *fdf);
unsigned int	hex_rgb_to_int(char *hex);
void			clean_split(char **split);
t_pixel			iso_proj(t_fdf *fdf, t_pixel p);
int				draw_iso(t_fdf *fdf);
#endif
