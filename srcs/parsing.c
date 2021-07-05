/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 20:10:27 by user42            #+#    #+#             */
/*   Updated: 2021/07/05 20:54:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bool	check_map_extension(char  const *pathname)
{
	const char	extension[4];

	ft_strlcpy(extension, ".fdf")
	if (ft_strcmp(pathname + ft_strlen(pathname) - ft_strlen(extension),
			extension) == 0)
		return (MAP_EXTENSION_ERROR);
}

int	open_map(char const *pathnmame)
{
	if (open(pathnmame, O_DIRECTORY) != -1)
	{
		close(fd);
		return (OPENING_DIR_ERROR);
	}
	fd = open(pathnmame, O_RDONLY);
}

t_error	parse_map(char const *pathnmame)
{
	t_error	error;
	int		fd;

	if (check_map_extension(pathname) == FALSE)
		return (MAP_EXTENSION_ERROR);
	fd = open_map(pathname)
	return (NO_ERROR);
}

