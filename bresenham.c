/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:52:11 by mohaben-          #+#    #+#             */
/*   Updated: 2025/02/03 11:38:31 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_calculate_step(t_prjc p1, t_prjc p2, t_bresenham *bres)
{
	if (p1.x < p2.x)
		bres->step_x = 1;
	else
		bres->step_x = -1;
	if (p1.y < p2.y)
		bres->step_y = 1;
	else
		bres->step_y = -1;
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_bresenham_helper(t_prjc *p1, t_bresenham *bres)
{
	if (bres->err >= 0)
	{
		if (bres->swap_axes)
			p1->x += bres->step_x;
		else
			p1->y += bres->step_y;
		bres->err -= 2 * bres->dx;
	}
	if (bres->swap_axes)
		p1->y += bres->step_y;
	else
		p1->x += bres->step_x;
	bres->err += 2 * bres->dy;
}

void	ft_bresenham(t_map *map, t_prjc p1, t_prjc p2, int color)
{
	t_bresenham	bres;

	bres.swap_axes = 0;
	bres.dx = abs(p2.x - p1.x);
	bres.dy = abs(p2.y - p1.y);
	ft_calculate_step(p1, p2, &bres);
	if (bres.dy > bres.dx)
	{
		ft_swap(&bres.dx, &bres.dy);
		bres.swap_axes = 1;
	}
	bres.err = 2 * bres.dy - bres.dx;
	while (1)
	{
		put_pixel(map, p1.x, p1.y, color);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		ft_bresenham_helper(&p1, &bres);
	}
}
