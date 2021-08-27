/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:38:48 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/25 17:20:05 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGEMENT_H
# define ERROR_MANAGEMENT_H

# define OPENING_ERROR_MSG "The fdf file cannot be opened"
# define OPENING_DIR_ERROR_MSG "The fdf file is a directory"
# define MAP_EXTENSION_ERROR_MSG "The file extension must be \".fdf\""
# define READ_ERROR_MSG "The fdf file cannot be read"
# define READING_ERROR_MSG "The fdf file could not be read entirely"
# define MALLOC_ERROR_MSG "Malloc failure"
# define MAP_ERROR_MSG "Map not well formatted"

typedef enum e_error
{
	NO_ERROR,
	OPENING_ERROR,
	OPENING_DIR_ERROR,
	MAP_EXTENSION_ERROR,
	READ_ERROR,
	READING_ERROR,
	MALLOC_ERROR,
	MAP_ERROR
}	t_error;

int	return_error(t_error error);

#endif
