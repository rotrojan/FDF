/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:42:15 by user42            #+#    #+#             */
/*   Updated: 2021/09/02 21:21:02 by bigo             ###   ########.fr       */
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
	t_mlx	mlx;

	if (ac != 2)
		return (display_usage());
	error = check_fdf_file(av[1], &fd);
	if (error != NO_ERROR)
		return (return_error(error));
	error = parse_map(fd, get_map());
	if (error != NO_ERROR)
		return (return_error(error));
	/* print_map(*get_map()); */
	if (init_mlx(&mlx) != NO_ERROR)
	{
		display_error(error);
		close_mlx(&mlx);
	}
	if (display_projection(get_map(), &mlx) == FALSE)
		return(return_error(MALLOC_ERROR));
	return (EXIT_FAILURE);
}
