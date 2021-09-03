/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:02:29 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/03 21:00:48 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_array(void **array)
{
	unsigned int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free((array[i]));
		array[i] = NULL;
		++i;
	}
	free(array);
	array = NULL;
}

void	free_map(t_map *map)
{
	int	i;

	if (map->data == NULL)
		return ;
	i = 0;
	while (i < map->height)
	{
		free(map->data[i]);
		map->data[i] = NULL;
		++i;
	}
	free(map->data);
	map->data = NULL;
}
