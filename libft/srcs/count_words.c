/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:17:39 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/06 20:45:30 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	count_words(char const *str, char *charset)
{
	int	nb_words;
	int	state_in_word;
	int	i;

	i = 0;
	nb_words = 0;
	state_in_word = 0;
	while (str[i] != '\0')
	{
		if (state_in_word == 0)
		{
			if (is_charset(str[i], charset) == 0)
			{
				++nb_words;
				state_in_word = 1;
			}
		}
		else
			if (is_charset(str[i], charset) == 1)
				state_in_word = 0;
		++i;
	}
	return (nb_words);
}
