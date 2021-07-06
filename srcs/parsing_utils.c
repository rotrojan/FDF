/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 20:10:27 by user42            #+#    #+#             */
/*   Updated: 2021/07/06 20:03:08 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
