/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:42:15 by user42            #+#    #+#             */
/*   Updated: 2021/09/05 23:45:51 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*get_map(void)
{
	static t_map	map = {0};

	return (&map);
}

void	destructor(void)
{
	t_map *map;

	map = get_map();
	free_transformed_map(get_transformed_map(), map->height);
	free_map(get_map());
}

int	display_usage(void)
{
	ft_dprintf(STDOUT_FILENO, "Usage: ./fdf <map>.fdf\n");
	return (EXIT_FAILURE);
}

void print_map(t_map map)
{
	for (int j = 0; j < map.height; ++j){
		for (int i = 0; i < map.width; ++i){
			ft_printf("%-3d", map.data[j][i]);
		}
		write(1, "\n", 1);
	}
}

int	main(int ac, char **av)
{
	t_error	error;
	int		fd;

	if (ac != 2)
		return (display_usage());
	error = check_fdf_file(av[1], &fd);
	if (error != NO_ERROR)
		return (return_error(error));
	error = parse_map(fd, get_map());
	if (error != NO_ERROR)
		return (return_error(error));
	if (init_mlx() != NO_ERROR)
	{
		display_error(error);
		close_mlx();
	}
	if (display_projection() == FALSE)
	{
		display_error(MALLOC_ERROR);
		close_mlx();
	}
	mlx_loop(get_mlx()->mlx_ptr);
	return (EXIT_FAILURE);
}
