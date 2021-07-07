/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:42:15 by user42            #+#    #+#             */
/*   Updated: 2021/07/07 22:52:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	display_usage(void)
{
	ft_dprintf(STDOUT_FILENO, "Usage: ./fdf <map>.fdf\n");
	return (EXIT_FAILURE);
}

#include "../test_functions.c"

int	main(int ac, char **av)
{
	t_error	error;
	int		fd;
	t_map	map;

	if (ac != 2)
		return (display_usage());
	error = check_fdf_file(av[1], &fd);
	if (error != NO_ERROR)
		return (return_error(error));
	ft_bzero(&map, sizeof(map));
	error = parse_map(fd, &map);
	if (error != NO_ERROR)
	{
		if (map.data != NULL)
			free_map(&map);
		return (return_error(error));
	}
	print_array_int(&map);
	init_mlx();
	/* display_projection(); */
	free_map(&map);
	return (EXIT_SUCCESS);
}
