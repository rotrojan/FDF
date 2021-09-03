/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:38:48 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/01 18:50:07 by bigo             ###   ########.fr       */
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
# define MLX_INIT_ERROR_MSG "Could not establish connexion with the X server"
# define MLX_WIN_ERROR_MSG "Could not create a new window"
# define MLX_IMG_ERROR_MSG "Could not create a new image"

typedef enum e_error
{
	NO_ERROR,
	OPENING_ERROR,
	OPENING_DIR_ERROR,
	MAP_EXTENSION_ERROR,
	READ_ERROR,
	READING_ERROR,
	MALLOC_ERROR,
	MAP_ERROR,
	MLX_INIT_ERROR,
	MLX_WIN_ERROR,
	MLX_IMG_ERROR
}	t_error;

void	display_error(t_error error);
int		return_error(t_error error);

#endif
