/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 00:45:45 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/20 16:33:53 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_tab(int n, unsigned char size, char **str)
{
	(*str)[--size] = '\0';
	if (n < 0)
	{
		(*str)[0] = '-';
		n = -n;
	}
	while (n)
	{
		(*str)[--size] = n % 10 + '0';
		n = n / 10;
	}
}

static char	*handle_special_cases(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	return (ft_strdup(INT_MIN_STR));
}

char	*ft_itoa(int n)
{
	unsigned int	size;
	int				tmp;
	char			*str;

	if (n == 0 || n == INT_MIN)
		str = handle_special_cases(n);
	else
	{
		if (n < 0)
			size = 2;
		else
			size = 1;
		tmp = n;
		while (tmp)
		{
			tmp /= 10;
			size++;
		}
		str = NULL;
		str = malloc(sizeof(*str) * size);
		if (str == NULL)
			return (NULL);
		fill_tab(n, size, &str);
	}
	return (str);
}
