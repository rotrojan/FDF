/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:30:23 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/01 16:44:54 by bigo             ###   ########.fr       */
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

t_map	*get_map(void);

#endif
