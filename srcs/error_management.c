/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:49:05 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/25 17:20:13 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	return_error(t_error error)
{
	static char	*error_messages[] = {
		NULL,
		OPENING_ERROR_MSG,
		OPENING_DIR_ERROR_MSG,
		MAP_EXTENSION_ERROR_MSG,
		READ_ERROR_MSG,
		READING_ERROR_MSG,
		MALLOC_ERROR_MSG,
		MAP_ERROR_MSG
	};

	ft_dprintf(STDERR_FILENO, "Error\n%s\n", error_messages[error]);
	return (EXIT_FAILURE);
}
