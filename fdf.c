/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:32:58 by mohaben-          #+#    #+#             */
/*   Updated: 2025/02/03 11:54:50 by mohaben-         ###   ########.fr       */
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
	mlx_string_put(mlx, ptr, 50, 100, COLOR_WHITE, "Moves: Arrows < ^ v >");
	mlx_string_put(mlx, ptr, 50, 120, COLOR_WHITE, "Parallel projection: p");
	mlx_string_put(mlx, ptr, 50, 140, COLOR_WHITE, "Isometric projection: i");
	mlx_string_put(mlx, ptr, 50, 160, COLOR_WHITE, "Zoom in/out: +/-");
	mlx_string_put(mlx, ptr, 50, 180, COLOR_WHITE, "Rotate X: 1/3");
	mlx_string_put(mlx, ptr, 50, 200, COLOR_WHITE, "Rotate Y: 4/6");
	mlx_string_put(mlx, ptr, 50, 220, COLOR_WHITE, "Rotate Z: 7/9");
	mlx_string_put(mlx, ptr, 50, 240, COLOR_WHITE, "Auto rotation: R");
	mlx_string_put(mlx, ptr, 50, 260, COLOR_WHITE, "Exit: ESC");
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
	mlx_loop_hook(map.mlx_ptr, ft_auto_rotation, &map);
	mlx_loop(map.mlx_ptr);
	handle_close(&map);
	return (0);
}
