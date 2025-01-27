/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:07:29 by mohaben-          #+#    #+#             */
/*   Updated: 2025/01/24 20:28:58 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_z_min_max(t_map *map)
{
	int	x;
	int	y;
	int	z;

	map->z_max = INT_MIN;
	map->z_min = INT_MAX;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			z = map->grid[y][x].z;
			if (z < map->z_min)
				map->z_min = z;
			if (z > map->z_max)
				map->z_max = z;
			x++;
		}
		y++;
	}
}

int	get_color(t_point grid, int z_min, int z_max)
{
	double	percentage;
	int		color[2];
	int		red_gren_ble[3];

	if (grid.color != -1)
		return (grid.color);
	color[0] = COLOR_BLUE;
	color[1] = COLOR_RED;
	if (z_max == z_min)
		return (color[0]);
	percentage = (double)(grid.z - z_min) / (z_max - z_min);
	red_gren_ble[0] = ((color[1] >> 16) & 0xFF) * percentage;
	red_gren_ble[0] += ((color[0] >> 16) & 0xFF) * (1 - percentage);
	red_gren_ble[1] = ((color[1] >> 8) & 0xFF) * percentage;
	red_gren_ble[1] += ((color[0] >> 8) & 0xFF) * (1 - percentage);
	red_gren_ble[2] = (color[1] & 0xFF) * percentage;
	red_gren_ble[2] += (color[0] & 0xFF) * (1 - percentage);
	return ((red_gren_ble[0] << 16) | (red_gren_ble[1] << 8) | red_gren_ble[2]);
}
