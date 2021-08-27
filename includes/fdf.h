/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:38:48 by user42            #+#    #+#             */
/*   Updated: 2021/08/25 15:31:39 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
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
/*
** display_projection.c
*/

void	display_projection(t_map map, t_mlx *mlx);

#endif
