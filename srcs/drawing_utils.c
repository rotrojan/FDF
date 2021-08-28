/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:57:22 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/28 19:18:36 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color	get_color(float r, float g, float b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_point	get_point(unsigned int x, unsigned int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

void	put_pixel(t_mlx *mlx, unsigned int x, unsigned int y, t_color color)
{
	int		final_color;

	if ((x >= mlx->win_width && x < 0) || (y >= mlx->win_height && y < 0))
		return ;
	final_color = ((((int)(color.r * 255) << 8) | (int)(color.g * 255)) << 8)
		| (int)(color.b * 255);
	mlx->data[x + y * mlx->win_width] = final_color;
}

static void	initialize_bresenham_variables(
			t_bresenham *bres, t_point const a, t_point const b)
{
	bres->diff_x = abs(b.x - a.x);
	if (a.x < b.x)
		bres->slope_x = 1;
	else
		bres->slope_x = -1;
	bres->diff_y = -abs(b.y - a.y);
	if (a.y < b.y)
		bres->slope_y = 1;
	else
		bres->slope_y = -1;
	bres->err = bres->diff_x + bres->diff_y;
}

void	bresenham(
		t_point a, t_point const b, t_color const color, t_mlx *mlx)
{
	t_bresenham	bres;

	initialize_bresenham_variables(&bres, a, b);
	while (a.x != b.x || a.y != b.y)
	{
		bres.err_times_two = 2 * bres.err;
		if (bres.err_times_two >= bres.diff_y)
		{
			bres.err += bres.diff_y;
			a.x += bres.slope_x;
		}
		if (bres.err_times_two <= bres.diff_x)
		{
			bres.err += bres.diff_x;
			a.y += bres.slope_y;
		}
		put_pixel(mlx, a.x, a.y, color);
	}
}
