/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 20:10:27 by user42            #+#    #+#             */
/*   Updated: 2021/08/28 03:05:42 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	*get_map_line(char *map_line_str, unsigned int width)
{
	int				*map_line;
	unsigned int	i;
	unsigned int	j;

	map_line = NULL;
	map_line = malloc(sizeof(*map_line) * width);
	if (map_line == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < width)
	{
		map_line[i] = ft_atoi(&map_line_str[i]);
		while (ft_isspace(map_line_str[j]) == 1 && map_line_str[j] != '\0')
			++j;
		while (ft_isspace(map_line_str[j]) == 0 && map_line_str[j] != '\0')
			++j;
		++i;
	}
	return (map_line);
}

static t_map	*get_map(char **map_str_array, t_map *map)
{
	unsigned int	i;

	map->data = NULL;
	map->data = malloc(sizeof(*map) * map->height);
	if (map->data == NULL)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		map->data[i] = get_map_line(map_str_array[i], map->width);
		++i;
	}
	return (map);
}

static char	*read_map(int fd)
{
	int		ret_gnl;
	char	*map_str;
	char	*line_map;

	map_str = NULL;
	line_map = NULL;
	ret_gnl = get_next_line(fd, &line_map);
	while (ret_gnl > 0)
	{
		map_str = ft_strjoin_free(map_str, line_map, "\n");
		if (map_str == NULL)
			return (NULL);
		ret_gnl = get_next_line(fd, &line_map);
	}
	ft_memdel((void **)&line_map);
	if (ret_gnl == -1)
		ft_memdel((void **)(&map_str));
	return (map_str);
}

t_error	parse_map(int fd, t_map *map)
{
	char			*map_str;
	char			**map_str_array;

	map_str = read_map(fd);
	if (map_str == NULL)
		return (READING_ERROR);
	map_str_array = ft_split(map_str, "\n");
	ft_memdel((void **)&map_str);
	if (map_str_array == NULL)
		return (MALLOC_ERROR);
	if (check_map(map_str_array, map) == FALSE)
	{
		free_array(((void **)map_str_array));
		return (MAP_ERROR);
	}
	map = get_map(map_str_array, map);
	free_array(((void **)map_str_array));
	if (map == NULL)
		return (MALLOC_ERROR);
	return (NO_ERROR);
}
