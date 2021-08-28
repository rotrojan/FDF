/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:38:48 by user42            #+#    #+#             */
/*   Updated: 2021/08/28 17:21:46 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
# define XK_MISCELLANY
# define XK_LATIN1
# include <X11/keysymdef.h>
# include "libft.h"
# include "ft_printf.h"
# include "ft_bool.h"
# include "error_management.h"
# include "map.h"
# include "parsing.h"
# include "mlx.h"
# include "ft_mlx.h"

void	destructor(void) __attribute__((destructor));

/*
** display_projection.c
*/

void	display_projection(t_map *map, t_mlx *mlx);

/*
** drawing_utils.c
*/

t_point	get_point(unsigned int x, unsigned int y);
void	bresenham(t_point a, t_point b, t_color, t_mlx *mlx);

#endif
