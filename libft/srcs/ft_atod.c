/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 03:07:45 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/18 13:54:25 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	trim_white_spaces(char const **str)
{
	while (ft_isspace(**str))
		++(*str);
}

static void	handle_sign(int *is_negative, char const **str)
{
	if (**str == '-')
		*is_negative = -1;
	else
		*is_negative = 1;
	if (**str == '-' || **str == '+')
		++(*str);
}

double	ft_atod(char const *str)
{
	double		int_part;
	double		dec_part;
	int			is_negative;
	int			len_dec_part;

	trim_white_spaces(&str);
	handle_sign(&is_negative, &str);
	int_part = 0;
	while (ft_isdigit(*str))
		int_part = int_part * 10.0f + (float)(*(str++) - '0');
	if (*str == '.')
		++str;
	len_dec_part = 0;
	dec_part = 0;
	while (ft_isdigit(*str))
	{
		dec_part = dec_part * 10.0f + (float)(*(str++) - '0');
		++len_dec_part;
	}
	while (len_dec_part--)
		dec_part /= 10.0f;
	return ((int_part + dec_part) * is_negative);
}
