/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:42:15 by user42            #+#    #+#             */
/*   Updated: 2021/07/05 20:10:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	display_usage(void)
{
	ft_dprintf(STDOUT_FILENO, "Usage: ./fdf <map>.fdf");
	return (EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_error	error;

	if (ac != 2)
		return (display_usage());
	error  = parse_map(av[1]);
	if (error != NO_ERROR)
		free_and_return();
	init_mlx();
	display_projection();
	return (EXIT_SUCCESS);
}
