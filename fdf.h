/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:20:05 by lupayet           #+#    #+#             */
/*   Updated: 2025/06/09 11:40:49 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "./minilibx-linux/mlx.h"
#include <stdlib.h>
#define Esc	0xff1b

typedef struct	s_app
{
	void	*mlx;
	void	*win;
}	t_app;

int input(int keycode, t_app *vars);

#endif
