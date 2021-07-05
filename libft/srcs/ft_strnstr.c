/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:50:19 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/20 22:48:56 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t len)
{
	size_t		len_needle;

	if (*needle)
	{
		len_needle = ft_strlen(needle);
		if (!len || ft_strlen(haystack) < len_needle)
			return (NULL);
		while (len-- && ft_strncmp(haystack, needle, len_needle))
		{
			if (len < len_needle)
				return (NULL);
			haystack++;
		}
	}
	return ((char *)haystack);
}
