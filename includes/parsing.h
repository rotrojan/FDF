/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:30:23 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/25 11:55:27 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "fdf.h"

/*
** parsing_utils.c
*/

t_error	check_fdf_file(char const *pathnmame, int *fd);
t_bool	check_map(char **map_str_array, t_map *map);

/*
** parsing.c
*/

t_error	parse_map(int fd, t_map *map);

/*
** utils.c
*/

void	free_array(void **array);
void	free_map(t_map *map);

#endif
