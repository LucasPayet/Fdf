/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:20:05 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/08 18:40:37 by lupayet          ###   ########.fr       */
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
#define Add 0xffab
#define Sub 0xffad
#define Left 0xff96 
#define Up 0xff97
#define Right 0xff98
#define Down 0xff99
#define WIN_WIDTH 1000
#define WIN_HEIGHT 1000
#define ZOOM 20
#define ANGLE_X 0
#define	ANGLE_Y 0
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
