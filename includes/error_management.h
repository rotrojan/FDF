/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:38:48 by user42            #+#    #+#             */
/*   Updated: 2021/07/05 20:54:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGEMENT_H
# define ERROR_MANAGEMENT_H

typedef enum e_error
{
	NO_ERROR,
	OPENING_ERROR,
	OPENING_DIR_ERROR,
	MAP_EXTENSION_ERROR,
	READ_ERR,
	MALLOC_ERROR
}

#endif

