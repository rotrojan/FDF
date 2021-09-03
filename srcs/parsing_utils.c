/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 20:10:27 by user42            #+#    #+#             */
/*   Updated: 2021/09/01 16:31:07 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define WHITESPACES " \t\n\v\f\r"

static t_bool	check_map_extension(char const *pathname)
{
	char	extension[4];

	ft_strlcpy(extension, ".fdf", sizeof(extension));
	if (ft_strcmp(pathname + ft_strlen(pathname) - ft_strlen(extension),
			extension) == 0)
		return (FALSE);
	return (TRUE);
}

static t_bool	check_directory(char const *pathnmame)
{
	int	fd;

	fd = open(pathnmame, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (FALSE);
	}
	return (TRUE);
}

t_error	check_fdf_file(char const *pathname, int *fd)
{
	if (check_map_extension(pathname) == FALSE)
		return (MAP_EXTENSION_ERROR);
	if (check_directory(pathname) == FALSE)
		return (OPENING_DIR_ERROR);
	*fd = open(pathname, O_RDONLY);
	if (*fd == -1)
		return (READ_ERROR);
	return (NO_ERROR);
}

static t_bool	check_line(char const *line)
{
	unsigned int	i;

	i = 0;
	while (ft_isspace(line[i]) == 1)
		++i;
	while (line[i] != '\0')
	{
		if (line[i] == '+' || line[i] == '-')
			++i;
		if (ft_isdigit(line[i]) == 0)
			return (FALSE);
		while (ft_isdigit(line[i]) == 1)
			++i;
		if (ft_isspace(line[i]) == 0 && line[i] != '\0')
			return (FALSE);
		while (ft_isspace(line[i]) == 1)
			++i;
	}
	return (TRUE);
}

t_bool	check_map(char **map_str_array, t_map *map)
{
	int	i;

	while (map_str_array[map->height] != NULL)
		++map->height;
	map->width = count_words(*map_str_array, WHITESPACES);
	i = 0;
	while (i < map->height)
	{
		if (check_line(map_str_array[i]) == FALSE)
			return (FALSE);
		if (count_words(map_str_array[i], WHITESPACES) != map->width)
			return (FALSE);
		++i;
	}
	return (TRUE);
}
