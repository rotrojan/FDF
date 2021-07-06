/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 20:10:27 by user42            #+#    #+#             */
/*   Updated: 2021/07/06 21:11:26 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define WHITESPACES " \t\n\v\f\r"

void	free_array(void **array)
{
	unsigned int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free((array[i]));
		array[i] = NULL;
		++i;
	}
	free(*array);
	array = NULL;
}

t_bool	check_line(char const *line)
{
	unsigned int	i;

	i = 0;
	while (line[i] != '\0')
	{
		while (ft_isspace(line[i]) == 1)
			++i;
		if (line[i] == '+' || line[i] == '-')
			++i;
		if (ft_isdigit(line[i]) == 0)
			return (FALSE);
		while (ft_isdigit(line[i]) == 1)
			++i;
		if (ft_isspace(line[i]) == 0 && line[i] != '\0')
			return (FALSE);
	}
	return (TRUE);
}

t_error	check_map(char **map_str_array, t_map *map)
{
	unsigned int	nb_lines;
	unsigned int	nb_columns;
	unsigned int	i;

	nb_lines = 0;
	while (map_str_array[nb_lines] != NULL)
		++nb_lines;
	nb_columns = count_words(*map_str_array, WHITESPACES);
	i = 0;
	while (map_str_array[i] != NULL)
	{
		if (check_line(map_str_array[i]) == FALSE)
			return (MAP_ERROR);
		if (count_words(map_str_array[i], WHITESPACES) != nb_columns)
			return (MAP_ERROR);
		++i;
	}
	(void)map;
	return (NO_ERROR);
}

char	*read_map(int fd)
{
	int		ret_gnl;
	char	*map_str;
	char	*line_map;
	char	*tmp;

	map_str = NULL;
	line_map = NULL;
	tmp = NULL;
	ret_gnl = get_next_line(fd, &line_map);
	ft_printf("yolo\n");
	while (ret_gnl > 0)
	{
		tmp = map_str;
		map_str = ft_strjoin(map_str, line_map, "\n");
		ft_memdel((void **)(&tmp));
		if (map_str == NULL)
			return (NULL);
		ret_gnl = get_next_line(fd, &line_map);
	}
	if (ret_gnl == -1)
	{
		ft_memdel((void **)(&tmp));
		return (NULL);
	}
	return (map_str);
}

void	print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_printf("%s\n", array[i]);
		++i;
	}
	ft_printf("%p\n", array[i]);
}

t_error	parse_map(int fd, t_map *map)
{
	char	*map_str;
	char	**map_str_array;
	t_error	error;

	map_str = read_map(fd);
	if (map_str == NULL)
		return (READING_ERROR);
	map_str_array = ft_split(map_str, "\n");
	if (map_str_array == NULL)
		return (MALLOC_ERROR);
	print_array(map_str_array);
	error = check_map(map_str_array, map);
	if (error != NO_ERROR)
		return (error);
	/* (void)map; */
	free_array(((void **)map_str_array));
	return (NO_ERROR);
}
