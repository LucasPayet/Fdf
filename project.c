/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:58:38 by lupayet           #+#    #+#             */
/*   Updated: 2025/06/25 23:00:08 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Point rotate(Point p, Vars *vars) {
    Point tmp;

	tmp.y = p.y * cos(vars->angle_x) - p.z * sin(vars->angle_x);
	tmp.z = p.y * sin(vars->angle_x) + p.z * cos(vars->angle_x);
	tmp.x = p.x;
	p.x = tmp.x * cos(vars->angle_y) + tmp.z * sin(vars->angle_y);
	p.z = -tmp.x * sin(vars->angle_y) + tmp.z * cos(vars->angle_y);
	p.y = tmp.y;
	tmp.x = p.x * cos(vars->angle_z) - p.y * sin(vars->angle_z);
	tmp.y = p.x * sin(vars->angle_z) + p.y * cos(vars->angle_z);
	tmp.z = p.z;
	return tmp;
}
