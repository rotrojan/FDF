/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:22:11 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/02 21:35:14 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define SIZE_SECTION 50

void	transform_map(t_point **map, t_map old_map, t_mlx *mlx)
{
	int	i;
	int	j;
	t_point tmp;
	int	offset_x;
	int offset_y;

	j = 0;
	while (j < old_map.height)
	{
		i = 0;
		while (i < old_map.width)
		{
			map[j][i].x = map[j][i].x * SIZE_SECTION;
			map[j][i].y = map[j][i].y * SIZE_SECTION;
			++i;
		}
		++j;
	}
	j = 0;
	while (j < old_map.height)
	{
		i = 0;
		while (i < old_map.width)
		{
			tmp.x = (map[j][i].x - map[j][i].y) * cos(0.523599);
			tmp.y = (map[j][i].x + map[j][i].y) * sin(0.523599) - old_map.data[j][i];
			map[j][i].x = tmp.x;
			map[j][i].y = tmp.y;
			++i;
		}
		++j;
	}
	offset_x = (mlx->win_width - (map[0][old_map.width - 1].x - map[old_map.height - 1][0].x));
	offset_y = (mlx->win_height - (map[old_map.height - 1][old_map.width - 1].y - map[0][0].y)) / 2;
	/* ft_printf("x = %d\ny = %d\n", map[0][old_map.width - 1].x - map[old_map.height - 1][0].x, map[old_map.height - 1][old_map.width - 1].y - map[0][0].y); */
	ft_printf("ox = %d\noy = %d\n", offset_x, offset_y);
	/* offset_x = mlx->win_width / 3; */
	/* offset_y = mlx->win_height / 2; */
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
/* { */
	/* int		offset_x; */
	/* int		offset_y; */
	/* t_map	map; */
	/* t_point	med; */
	/* t_point	new; */

	/* map = *get_map(); */
	/* med.x = (a.x * SIZE_SECTION); */
	/* med.y = (a.y * SIZE_SECTION); */
	/* new.x = (med.x - med.y) * cos(120); */
	/* new.y = (med.x + med.y) * sin(120);// - map.data[a.x][a.y]; */
	/* return (new); */
/* } */

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



t_bool	display_projection(t_map *map, t_mlx *mlx)
{
	int		x;
	int		y;
	t_point	**transformed_map;

	transformed_map = alloc_new_map_data(*map);
	if (transformed_map == NULL)
		return (FALSE);
	transform_map(transformed_map, *map, mlx);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x + 1 < map->width)
		{
			bresenham(transformed_map[y][x], transformed_map[y][x + 1],
				get_color(1, 1, 1), mlx);
			++x;
		}
		x = 0;
		if (y + 1 < map->height)
			while (x < map->width)
			{
				bresenham(transformed_map[y][x], transformed_map[y + 1][x],
					get_color(1, 1, 1), mlx);
				++x;
			}
		++y;
	}
	mlx_loop(mlx->mlx_ptr);
	return (FALSE);
}
