/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:22:11 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/27 18:51:30 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_projection(t_map map, t_mlx *mlx)
{
	(void)map;
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			put_pixel(mlx, j, i, get_color(1, 0, 0));
		}
	}
	run_mlx(&mlx);
}
