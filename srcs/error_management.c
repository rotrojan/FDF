/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:49:05 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/28 02:23:33 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_error(t_error error)
{
	char const	*error_messages[] = {
		NULL,
		OPENING_ERROR_MSG,
		OPENING_DIR_ERROR_MSG,
		MAP_EXTENSION_ERROR_MSG,
		READ_ERROR_MSG,
		READING_ERROR_MSG,
		MALLOC_ERROR_MSG,
		MAP_ERROR_MSG,
		MLX_INIT_ERROR_MSG,
		MLX_WIN_ERROR_MSG,
		MLX_IMG_ERROR_MSG
	};

	if (error != NO_ERROR)
		ft_dprintf(STDERR_FILENO, "Error\n%s\n", error_messages[error]);
}
