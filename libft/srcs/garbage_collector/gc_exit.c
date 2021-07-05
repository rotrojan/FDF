/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:01:22 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/20 23:52:34 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gc_exit(int status, char *message)
{
	gc_free_all();
	if (status == EXIT_SUCCESS && message != NULL)
		ft_putendl_fd(message, STDOUT_FILENO);
	else
	{
		ft_putstr_fd("Error: ", STDERR_FILENO);
		ft_putendl_fd(message, STDERR_FILENO);
	}
	exit(status);
}
