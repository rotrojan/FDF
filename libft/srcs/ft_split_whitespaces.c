/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:31:28 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/07 19:00:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define WHITESPACES " \t\n\v\f\r"

char	**ft_split_whitespaces(char const *str)
{
	return (ft_split(str, WHITESPACES));
}
