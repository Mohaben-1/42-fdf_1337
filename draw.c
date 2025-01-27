/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:05:41 by mohaben-          #+#    #+#             */
/*   Updated: 2025/01/25 13:28:02 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_map *map, int x, int y, int color)
{
	int	index;

	index = 0;
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		index = (x * (map->bpp / 8)) + (y * map->size_line);
		*(int *)(map->img_data + index) = color;
	}
}

t_prjc	ft_set_point(int x, int y, int z, t_map *map)
{
	t_prjc	p;
	double	xf;
	double	yf;
	double	zf;

	xf = (double)x;
	yf = (double)y;
	zf = (double)z;
	if (map->iso == 1)
	{
		ft_apply_rotation(&xf, &yf, &zf, map);
		p.x = (xf - yf) * cos(to_radians(30)) * map->scale + map->x_offset;
		p.y = ((xf + yf) * sin(to_radians(30)) - zf) * map->scale;
		p.y += map->y_offset;
	}
	else
	{
		p.x = xf * map->scale + map->x_offset;
		p.y = yf * map->scale + map->y_offset;
	}
	p.x += WIN_HEIGHT / 2;
	p.y += WIN_HEIGHT / 2;
	return (p);
}

void	ft_draw_line_helper(t_map *map, t_prjc p1, int x, int y)
{
	t_prjc	p2;
	int		color;

	if (x + 1 < map->width)
	{
		p2 = ft_set_point(x + 1, y, map->grid[y][x + 1].z, map);
		color = get_color(map->grid[y][x], map->z_min, map->z_max);
		ft_bresenham(map, p1, p2, color);
	}
	if (y + 1 < map->height)
	{
		p2 = ft_set_point(x, y + 1, map->grid[y + 1][x].z, map);
		color = get_color(map->grid[y][x], map->z_min, map->z_max);
		ft_bresenham(map, p1, p2, color);
	}
}

void	ft_draw(t_map *map)
{
	t_prjc	p1;
	int		x;
	int		y;

	ft_memset(map->img_data, 0, WIN_HEIGHT * WIN_WIDTH * (map->bpp / 8));
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			p1 = ft_set_point(x, y, map->grid[y][x].z, map);
			ft_draw_line_helper(map, p1, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->img, 0, 0);
	menu(*map);
}
