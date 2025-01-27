/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:32:58 by mohaben-          #+#    #+#             */
/*   Updated: 2025/01/27 13:16:18 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu(t_map map)
{
	void	*mlx;
	void	*ptr;

	mlx = map.mlx_ptr;
	ptr = map.mlx_win;
	mlx_string_put(mlx, ptr, 30, 50, COLOR_RED, "-----List Of Actions-----");
	mlx_string_put(mlx, ptr, 30, 100, COLOR_WHITE, "Exit: ESC");
	mlx_string_put(mlx, ptr, 30, 120, COLOR_WHITE, "Parallel projection: p");
	mlx_string_put(mlx, ptr, 30, 140, COLOR_WHITE, "Isometric projection: i");
	mlx_string_put(mlx, ptr, 30, 160, COLOR_WHITE, "Zoom in: +");
	mlx_string_put(mlx, ptr, 30, 180, COLOR_WHITE, "Zoom out: -");
	mlx_string_put(mlx, ptr, 30, 200, COLOR_WHITE, "Move up   : Up arrow");
	mlx_string_put(mlx, ptr, 30, 220, COLOR_WHITE, "Move down : Down arrow");
	mlx_string_put(mlx, ptr, 30, 240, COLOR_WHITE, "Move left : Left arrow");
	mlx_string_put(mlx, ptr, 30, 260, COLOR_WHITE, "Move right: Right arrow");
	mlx_string_put(mlx, ptr, 30, 280, COLOR_WHITE, "Rotate x: 1 / 3");
	mlx_string_put(mlx, ptr, 30, 300, COLOR_WHITE, "Rotate y: 4 / 6");
	mlx_string_put(mlx, ptr, 30, 320, COLOR_WHITE, "Rotate z: 7 / 9");
}

int	main(int ac, char **av)
{
	t_map		map;
	int			fd;

	fd = ft_check_arg_and_get_fd(ac, av[1]);
	ft_get_width_height(av[1], fd, &map);
	map.grid = ft_fill_2d_array(fd, map);
	ft_mlx_init(&map);
	ft_draw(&map);
	mlx_key_hook(map.mlx_win, handle_input, &map);
	mlx_hook(map.mlx_win, 17, 0, handle_close, &map);
	mlx_loop(map.mlx_ptr);
	handle_close(&map);
	return (0);
}
