/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:30:23 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/06 15:51:05 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "fdf.h"

/*
** parsing_utils.c
*/

t_error	check_fdf_file(char const *pathnmame, int *fd);

/*
** parsing.c
*/

t_error	parse_map(int fd, t_map *map);

#endif
