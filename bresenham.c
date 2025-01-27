/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:52:11 by mohaben-          #+#    #+#             */
/*   Updated: 2025/01/24 20:54:20 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_bresenham_step(t_prjc *p1, t_bresenham *bres)
{
	int	e2;

	e2 = 2 * bres->err;
	if (e2 > -(bres->dy))
	{
		bres->err -= bres->dy;
		p1->x += bres->steps[0];
	}
	if (e2 < bres->dx)
	{
		bres->err += bres->dx;
		p1->y += bres->steps[1];
	}
}

static void	ft_calculate_step(t_prjc p1, t_prjc p2, t_bresenham *bres)
{
	if (p1.x < p2.x)
		bres->steps[0] = 1;
	else
		bres->steps[0] = -1;
	if (p1.y < p2.y)
		bres->steps[1] = 1;
	else
		bres->steps[1] = -1;
}

void	ft_bresenham(t_map *map, t_prjc p1, t_prjc p2, int color)
{
	t_bresenham	bres;

	bres.dx = abs(p2.x - p1.x);
	bres.dy = abs(p2.y - p1.y);
	bres.err = bres.dx - bres.dy;
	ft_calculate_step(p1, p2, &bres);
	while (1)
	{
		put_pixel(map, p1.x, p1.y, color);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		ft_bresenham_step(&p1, &bres);
	}
}
