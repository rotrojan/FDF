/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:57:22 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/30 22:08:18 by bigo             ###   ########.fr       */
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

t_point	get_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

void	put_pixel(t_mlx *mlx, int x, int y, t_color color)
{
	int		final_color;

	if ((x >= mlx->win_width || x < 0) || (y >= mlx->win_height || y < 0))
		return ;
	final_color = ((((int)(color.r * 255) << 8) | (int)(color.g * 255)) << 8)
		| (int)(color.b * 255);
	mlx->data[x + y * mlx->win_width] = final_color;
}

t_bool	get_valid_point(t_point *a, t_point *b, t_mlx *mlx)
{
	if (a->x >= 0 && a->y < (int)mlx->win_width
		&& b->x >= 0 && b->y < (int)mlx->win_height)
		return (TRUE);
	if ((a->x < 0 && b->x < 0)
		|| (a->x >= (int)mlx->win_width && b->x >= (int)mlx->win_width)
		|| (a->y >= (int)mlx->win_height && b->y >= (int)mlx->win_height)
		|| (a->x < 0 && b->x < 0) || (a->y < 0 && b->y < 0))
			return (FALSE);
	/* if (x->a < 0) */
	/* { */
		/* while  */
	/* } */
	return (TRUE);
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
		t_point a, t_point b, t_color const color, t_mlx *mlx)
{
	t_bresenham	bres;

	initialize_bresenham_variables(&bres, a, b);
	if (get_valid_point(&a, &b, mlx) == TRUE)
	{
		put_pixel(mlx, a.x, a.y, color);
		while (a.x != b.x || a.y != b.y)
		{
			bres.err_times_two = 2 * bres.err;
			if (bres.err_times_two >= bres.diff_y)
			{
				bres.err += bres.diff_y;
				a.x += bres.slope_x;
			}
			else if (bres.err_times_two <= bres.diff_x)
			{
				bres.err += bres.diff_x;
				a.y += bres.slope_y;
			}
			put_pixel(mlx, a.x, a.y, color);
		}
	}
}
