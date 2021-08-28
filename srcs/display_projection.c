/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:22:11 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/28 18:08:56 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_projection(t_map *map, t_mlx *mlx)
{
	(void)map;
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			put_pixel(mlx, j, i, get_color(0, 0, 0));
		}
	}
	/* for (int i = 0; i < 50; i++) { */
		/* for (int j = 0; j < 200; j++) { */
			/* put_pixel(mlx, j, i, get_color(0, 0, 1)); */
		/* } */
	/* } */
	bresenham(get_point(400, 400), get_point(600, 0), get_color(1, 1, 1), mlx);
	bresenham(get_point(400, 400), get_point(800, 200), get_color(1, 1, 1), mlx);
	bresenham(get_point(400, 400), get_point(800, 600), get_color(1, 1, 1), mlx);
	bresenham(get_point(400, 400), get_point(600, 800), get_color(1, 1, 1), mlx);
	bresenham(get_point(400, 400), get_point(200, 800), get_color(1, 1, 1), mlx);
	bresenham(get_point(400, 400), get_point(0, 600), get_color(1, 1, 1), mlx);
	bresenham(get_point(400, 400), get_point(0, 200), get_color(1, 1, 1), mlx);
	bresenham(get_point(400, 400), get_point(200, 0), get_color(1, 1, 1), mlx);
	bresenham(get_point(400, 400), get_point(400, 0), get_color(1, 1, 1), mlx);
	bresenham(get_point(400, 400), get_point(800, 400), get_color(1, 1, 1), mlx);
	bresenham(get_point(400, 400), get_point(400, 800), get_color(1, 1, 1), mlx);
	bresenham(get_point(400, 400), get_point(0, 400), get_color(1, 1, 1), mlx);
	bresenham(get_point(400, 400), get_point(0, 0), get_color(1, 1, 1), mlx);
	bresenham(get_point(400, 400), get_point(0, 800), get_color(1, 1, 1), mlx);
	bresenham(get_point(400, 400), get_point(800, 0), get_color(1, 1, 1), mlx);
	bresenham(get_point(400, 400), get_point(800, 800), get_color(1, 1, 1), mlx);
	mlx_loop(mlx->mlx_ptr);
}
