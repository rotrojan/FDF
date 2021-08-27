/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:08:57 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/07 16:09:36 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_t_t_bool	check_line(char const *line)
{
	unsigned int	i;

	i = 0;
	while (ft_isspace(line[i]) == 1)
		++i;
	while (line[i] != '\0')
	{
		if (line[i] == '+' || line[i] == '-')
			++i;
		if (ft_isdigit(line[i]) == 0)
			return (FALSE);
		while (ft_isdigit(line[i]) == 1)
			++i;
		if (ft_isspace(line[i]) == 0 && line[i] != '\0')
			return (FALSE);
		while (ft_isspace(line[i]) == 1)
			++i;
	}
	return (TRUE);
}

t_t_t_bool	check_map(char **map_str_array,
		unsigned int *nb_lines, unsigned int *nb_columns)
{
	unsigned int	i;

	*nb_lines = 0;
	while (map_str_array[*nb_lines] != NULL)
		++*nb_lines;
	*nb_columns = count_words(*map_str_array, WHITESPACES);
	i = 0;
	while (map_str_array[i] != NULL)
	{
		if (check_line(map_str_array[i]) == FALSE)
			return (FALSE);
		if (count_words(map_str_array[i], WHITESPACES) != *nb_columns)
			return (FALSE);
		++i;
	}
	return (TRUE);
}
