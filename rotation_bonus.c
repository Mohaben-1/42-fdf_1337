/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:11:29 by mohaben-          #+#    #+#             */
/*   Updated: 2025/01/23 20:09:52 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(double *y, double *z, double radian)
{
	double	previous_y;

	previous_y = *y;
	*y = previous_y * cos(radian) + *z * sin(radian);
	*z = -previous_y * sin(radian) + *z * cos(radian);
}

void	rotate_y(double *x, double *z, double radian)
{
	double	previous_x;

	previous_x = *x;
	*x = previous_x * cos(radian) + *z * sin(radian);
	*z = -previous_x * sin(radian) + *z * cos(radian);
}

void	rotate_z(double *x, double *y, double radian)
{
	double	previous_x;
	double	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(radian) - previous_y * sin(radian);
	*y = previous_x * sin(radian) + previous_y * cos(radian);
}

void	ft_apply_rotation(double *x, double *y, double *z, t_map *map)
{
	rotate_x(y, z, to_radians(map->rotation_x));
	rotate_y(x, z, to_radians(map->rotation_y));
	rotate_z(x, y, to_radians(map->rotation_z));
}
