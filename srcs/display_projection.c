/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:22:11 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/03 20:58:50 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define SIZE_SECTION 50

void	scale_map(t_point **map, int width, int height, int coef)
{
	int	i;
	int	j;

	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			map[j][i].x = map[j][i].x * coef;
			map[j][i].y = map[j][i].y * coef;
			++i;
		}
		++j;
	}
}

void	apply_offset(t_point **map, t_map old_map, t_limit limit, t_mlx *mlx)
{
	int	i;
	int	j;
	int	offset_x;
	int offset_y;

	offset_x = 0;
	offset_y = 0;
	(void)mlx;
	offset_x = (mlx->win_width - (limit.x_max - limit.x_min)) / 2
		- limit.x_min;
	offset_y = (mlx->win_height - (limit.y_max - limit.y_min)) / 2
		- limit.y_min;
	j = 0;
	while (j < old_map.height)
	{
		i = 0;
		while (i < old_map.width)
		{
			map[j][i].x += offset_x;
			map[j][i].y += offset_y;
			++i;
		}
		++j;
	}
}

void	save_mins_and_maxs(t_point point, t_limit *limit)
{
	if (point.x < limit->x_min)
		limit->x_min = point.x;
	if (point.x > limit->x_max)
		limit->x_max = point.x;
	if (point.y < limit->y_min)
		limit->y_min = point.y;
	if (point.y > limit->y_max)
		limit->y_max = point.y;
}

void	transform_map(t_point **map, t_map old_map, t_limit *limit, t_mlx *mlx)
{
	int		i;
	int		j;
	t_point	tmp;

	scale_map(map, old_map.width, old_map.height, SIZE_SECTION);
	j = 0;
	while (j < old_map.height)
	{
		i = 0;
		while (i < old_map.width)
		{
			tmp.x = (map[j][i].x - map[j][i].y) * cos(120);
			tmp.y = (map[j][i].x + map[j][i].y) * sin(120)
				- old_map.data[j][i];
			save_mins_and_maxs(tmp, limit);
			map[j][i].x = tmp.x;
			map[j][i].y = tmp.y;
			++i;
		}
		++j;
	}
	apply_offset(map, old_map, *limit, mlx);
}

t_point	**alloc_new_map_data(t_map map)
{
	t_point	**transformed_map;
	int		i;
	int		j;

	transformed_map = malloc(sizeof(*transformed_map) * map.height);
	if (transformed_map == NULL)
		return (NULL);
	j = 0;
	while (j < map.height)
	{
		transformed_map[j] = malloc(sizeof(**transformed_map) * map.width);
		if (transformed_map[j] == NULL)
		{
			i = 0;
			while (i < j)
			{
				free(transformed_map[i]);
				transformed_map[i] = NULL;
				++i;
			}
			return (NULL);
		}
		i = 0;
		while (i < map.width)
		{
			transformed_map[j][i].x = i;
			transformed_map[j][i].y = j;
			++i;
		}
		++j;
	}
	return (transformed_map);
}

void	print_projection(
		t_point **transformed_map, int width, int height, t_mlx *mlx)
{
	int		i;
	int		j;

	j = 0;
	while (j < height)
	{
		i = 0;
		while (i + 1 < width)
		{
			bresenham(transformed_map[j][i], transformed_map[j][i + 1],
				get_color(1, 1, 1), mlx);
			++i;
		}
		i = 0;
		if (j + 1 < height)
			while (i < width)
			{
				bresenham(transformed_map[j][i], transformed_map[j + 1][i],
					get_color(1, 1, 1), mlx);
				++i;
			}
		++j;
	}
}

t_bool	display_projection(t_map *map, t_mlx *mlx)
{
	t_point	**transformed_map;
	t_limit	limit;

	transformed_map = alloc_new_map_data(*map);
	if (transformed_map == NULL)
		return (FALSE);
	limit.x_min = INT32_MAX;
	limit.x_max = INT32_MIN;
	limit.y_min = INT32_MAX;
	limit.y_max = INT32_MIN;
	transform_map(transformed_map, *map, &limit, mlx);
	print_projection(transformed_map, map->width, map->height, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (FALSE);
}
