/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 22:06:11 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/06 22:23:58 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, char const *sep)
{
	char	*str;

	str = ft_strjoin(s1, s2, sep);
	ft_memdel((void **)&s1);
	ft_memdel((void **)&s2);
	return (str);
}
