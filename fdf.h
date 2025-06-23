/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:20:05 by lupayet           #+#    #+#             */
/*   Updated: 2025/06/23 19:41:26 by lupayet          ###   ########.fr       */
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

int 			input(int keycode, t_fdf *vars);
void			clean_fdf(t_fdf *fdf);
int				close_fdf(t_fdf *fdf);
int				map_init(char *path, t_fdf *fdf);
unsigned int	hex_rgb_to_int(char *hex);
void			clean_split(char **split);
#endif
