/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:38:48 by user42            #+#    #+#             */
/*   Updated: 2021/09/05 23:45:23 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <limits.h>
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

typedef struct s_transformations
{
	float	zoom;
	int		trans_x;
	int		trans_y;
}	t_transformations;

void	destructor(void) __attribute__((destructor));

/*
** display_projection.c
*/

t_bool	display_projection(void);

/*
** drawing_utils.c
*/

t_point	get_point(int x, int y);
void	bresenham(t_point a, t_point b, t_color, t_mlx *mlx);

/*
** display_projection.c
*/

void	scale_map(t_point **map, int width, int height, float coef);
t_point	***get_transformed_map(void);
void	free_transformed_map(t_point ***transformed_map, int height);
void	print_projection(
		t_point **transformed_map, int width, int height, t_mlx *mlx);

t_transformations	*get_transformations(void);

#endif
