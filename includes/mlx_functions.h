/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:13:01 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/17 21:36:04 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_FUNCTIONS_H
# define MLX_FUNCTIONS_H
# include "minirt.h"

/*
** mlx_utils.c
*/

void	init_mlx(t_mlx *mlx);
int		close_mlx(t_main *main);
int		run_window(t_main *main);
void	put_pixel(t_mlx *mlx, unsigned int x, unsigned int y, t_color color);
t_bool	run_mlx(t_main *main);

/*
** mlx_hooks.c
*/

int		set_mlx_hooks(t_main *main);

#endif
