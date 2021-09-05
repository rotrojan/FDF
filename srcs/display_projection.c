/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:22:11 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/06 00:52:55 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define INITIAL_ZOOM_FACTOR 50.0

void	scale_map(
		t_point **transformed_map, int width, int height, float zoom_coef)
{
	int		i;
	int		j;

	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			transformed_map[j][i].x = transformed_map[j][i].x * zoom_coef;
			transformed_map[j][i].y = transformed_map[j][i].y * zoom_coef;
			++i;
		}
		++j;
	}
}

void	apply_offset(t_point **map, t_map old_map, t_limit limit, t_mlx *mlx)
{
	int					i;
	int					j;
	int					offset_x;
	int					offset_y;
	t_transformations	transformations;

	transformations = *get_transformations();
	offset_x = 0;
	offset_y = 0;
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
			map[j][i].x += offset_x + transformations.trans_x;
			map[j][i].y += offset_y + transformations.trans_y;
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

void	transform_map(
		t_point **transformed_map, t_map map, t_limit *limit)
{
	int					i;
	int					j;
	t_point				tmp;
	t_transformations	transformations;

	transformations = *get_transformations();
	scale_map(transformed_map, map.width, map.height, transformations.zoom);
	j = 0;
	while (j < map.height)
	{
		i = 0;
		while (i < map.width)
		{
			tmp.x = (transformed_map[j][i].x - transformed_map[j][i].y
					+ transformations.trans_x + transformations.trans_y)
				* cos(120);
			tmp.y = (transformed_map[j][i].x + transformed_map[j][i].y
					+ transformations.trans_x + transformations.trans_y)
				* sin(120) - (transformations.zoom / INITIAL_ZOOM_FACTOR)
				* map.data[j][i];
			save_mins_and_maxs(tmp, limit);
			transformed_map[j][i].x = tmp.x;
			transformed_map[j][i].y = tmp.y;
			++i;
		}
		++j;
	}
	apply_offset(transformed_map, map, *limit, get_mlx());
}

void	*free_and_return(t_point ***transformed_map, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free((*transformed_map)[i]);
		(*transformed_map)[i] = NULL;
		++i;
	}
	free(*transformed_map);
	*transformed_map = NULL;
	return (NULL);
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
			return(free_and_return(&transformed_map, j));
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

void	free_transformed_map(t_point ***transformed_map, int height)
{
	int		i;
	t_point	**to_free;

	to_free = *transformed_map;
		i = 0;
	while (i < height)
	{
		free(to_free[i]);
		to_free[i] = NULL;
		++i;
	}
		free(to_free);
		to_free = NULL;
}

t_point	***get_transformed_map(void)
{
	static	t_point	**transformed_map = NULL;

	return (&transformed_map);
}

t_bool	display_projection(void)
{
	t_point	**transformed_map;
	t_mlx	*mlx;
	t_limit	limit;
	t_map	map;

	map = *get_map();
	mlx = get_mlx();
	*get_transformed_map() = alloc_new_map_data(map);
	transformed_map = *get_transformed_map();
	if (transformed_map == NULL)
		return (FALSE);
	limit.x_min = INT_MAX;
	limit.x_max = INT_MIN;
	limit.y_min = INT_MAX;
	limit.y_max = INT_MIN;
	transform_map(transformed_map, map, &limit);
	print_projection(transformed_map, map.width, map.height, mlx);
	return (TRUE);
}
