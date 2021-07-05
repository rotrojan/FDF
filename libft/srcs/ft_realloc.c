/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:37:25 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/21 11:47:41 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = NULL;
	new_ptr = malloc(sizeof(*new_ptr) * size);
	if (new_ptr == NULL)
		return (NULL);
	ft_memcpy(new_ptr, ptr, sizeof(ptr));
	ft_memdel(&ptr);
	return (new_ptr);
}
