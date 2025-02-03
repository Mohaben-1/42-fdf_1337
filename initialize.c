/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:03:11 by mohaben-          #+#    #+#             */
/*   Updated: 2025/02/03 11:50:00 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**ft_fill_2d_array(int fd, t_map map)
{
	t_point	**grid;
	char	*line;
	char	**split;
	int		y;
	int		x;

	grid = malloc(map.height * sizeof(t_point *));
	y = 0;
	while (y < map.height)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		free(line);
		grid[y] = malloc(map.width * sizeof(t_point));
		x = 0;
		while (x < map.width)
		{
			ft_handle_z_color(split[x], &grid[y][x]);
			x++;
		}
		free_split(split);
		y++;
	}
	close(fd);
	return (grid);
}

void	ft_mlx_init_helper(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
		p_exit("Failed to initialize mlx!");
	map->mlx_win = mlx_new_window(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, TITLE);
	if (!map->mlx_win)
	{
		free_2d_array(map->grid, map->height);
		p_exit("Failed to initialize mlx!");
	}
	map->img = mlx_new_image(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!map->img)
	{
		free_2d_array(map->grid, map->height);
		mlx_destroy_window(map->mlx_ptr, map->mlx_win);
		p_exit("Failed to initialize mlx!");
	}
}

void	ft_mlx_init(t_map *map)
{
	int	*bbp;
	int	*size_line;
	int	*endian;

	bbp = &map->bpp;
	size_line = &map->size_line;
	endian = &map->endian;
	ft_mlx_init_helper(map);
	map->img_data = mlx_get_data_addr(map->img, bbp, size_line, endian);
	if (map->height > 50)
		map->scale = 2;
	else
		map->scale = 20;
	map->x_offset = 0;
	map->y_offset = 0;
	map->rotation_x = 1;
	map->rotation_y = 1;
	map->rotation_z = 1;
	map->iso = 1;
	ft_set_z_min_max(map);
}

int	handle_close(t_map *map)
{
	free_2d_array(map->grid, map->height);
	mlx_destroy_image(map->mlx_ptr, map->img);
	mlx_destroy_window(map->mlx_ptr, map->mlx_win);
	exit(0);
}
