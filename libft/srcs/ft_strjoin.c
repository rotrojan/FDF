/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:11:55 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/07 19:09:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*return_one_string(char const *s1, char const *s2)
{
	if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	else if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2, char const *sep)
{
	char	*str;
	char	*tmp;

	if (s1 == NULL || s2 == NULL)
		str = return_one_string(s1, s2);
	else
	{
		str = NULL;
		ft_strlen(s1);
		str = malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2)
					+ ft_strlen(sep) + 1));
		if (str == NULL)
			return (NULL);
		tmp = str;
		while (*s1)
			*tmp++ = *s1++;
		if (sep != NULL)
			while (*sep)
				*tmp++ = *sep++;
		while (*s2)
			*tmp++ = *s2++;
		*tmp = '\0';
	}
	return (str);
}
