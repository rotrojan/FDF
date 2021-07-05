/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:44:29 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/20 23:07:09 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char		*str;
	size_t		len;

	len = ft_strlen(s1) + 1;
	str = NULL;
	str = malloc(sizeof(*s1) * len);
	if (str == NULL)
		return (NULL);
	return ((char *)ft_memcpy(str, s1, len));
}
