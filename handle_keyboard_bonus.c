/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyboard_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:09:12 by mohaben-          #+#    #+#             */
/*   Updated: 2025/02/03 11:48:46 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_input(int keycode, t_map *map)
{
	if (keycode == 53)
		handle_close(map);
	if (keycode == UP_ARROW || keycode == DOWN_ARROW 
		|| keycode == LEFT_ARROW || keycode == RIGHT_ARROW)
		move(keycode, map);
	else if (keycode == PLUS_KEY || keycode == MINUS_KEY)
		zoom(keycode, map);
	else if (keycode == NUM_1 || keycode == NUM_3 || keycode == NUM_4 
		|| keycode == NUM_6 || keycode == NUM_7 || keycode == NUM_9)
		rotate(keycode, map);
	else if (keycode == P_KEY)
	{
		map->iso = 0;
		ft_draw(map);
	}
	else if (keycode == I_KEY)
	{
		map->iso = 1;
		ft_draw(map);
	}
	else if (keycode == R_KEY)
		map->autorotate = !map->autorotate;
	return (0);
}

void	zoom(int keycode, t_map *map)
{
	if (keycode == PLUS_KEY)
		map->scale++;
	else if (keycode == MINUS_KEY)
	{
		map->scale--;
		if (map->scale < 1)
			map->scale = 1;
	}
	ft_draw(map);
}

void	move(int keycode, t_map *map)
{
	if (keycode == LEFT_ARROW)
		map->x_offset -= 10;
	else if (keycode == RIGHT_ARROW)
		map->x_offset += 10;
	else if (keycode == DOWN_ARROW)
		map->y_offset -= 10;
	else if (keycode == UP_ARROW)
		map->y_offset += 10;
	ft_draw(map);
}

void	rotate(int keycode, t_map *map)
{
	if (keycode == NUM_1)
		map->rotation_x -= 3;
	else if (keycode == NUM_3)
		map->rotation_x += 3;
	else if (keycode == NUM_4)
		map->rotation_y -= 3;
	else if (keycode == NUM_6)
		map->rotation_y += 3;
	else if (keycode == NUM_7)
		map->rotation_z -= 3;
	else if (keycode == NUM_9)
		map->rotation_z += 3;
	ft_draw(map);
}
