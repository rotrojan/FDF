/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:04:42 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/20 23:42:46 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gc_free_all(void)
{
	t_gc_lst	**garbage;
	t_gc_lst	*current;
	t_gc_lst	*next;

	garbage = _get_gc_lst();
	current = *garbage;
	while (current)
	{
		next = current->next;
		ft_memdel((void **)&current->ptr);
		ft_memdel((void **)&current);
		current = next;
	}
}
