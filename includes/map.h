/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:30:23 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/03 19:03:08 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "fdf.h"

typedef struct s_map
{
	int	**data;
	int	height;
	int	width;
}	t_map;

typedef struct s_limit
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;
}	t_limit;

t_map	*get_map(void);

#endif
