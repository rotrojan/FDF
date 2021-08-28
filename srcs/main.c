/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:42:15 by user42            #+#    #+#             */
/*   Updated: 2021/08/28 03:17:02 by bigo             ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_error	error;
	int		fd;
	t_mlx	mlx;

	if (ac != 2)
		return (display_usage());
	error = check_fdf_file(av[1], &fd);
	if (error != NO_ERROR)
	{
		display_error(error);
		return (EXIT_FAILURE);
	}
	error = parse_map(fd, get_map());
	if (error != NO_ERROR)
	{
		display_error(error);
		return (EXIT_FAILURE);
	}
	if (init_mlx(&mlx) != NO_ERROR)
	{
		display_error(error);
		close_mlx(&mlx);
	}
	display_projection(get_map(), &mlx);
	return (EXIT_FAILURE);
}
