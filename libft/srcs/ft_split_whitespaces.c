/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:31:28 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/21 11:56:12 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str)
{
	int	nb_words;
	int	state_in_word;
	int	i;

	i = 0;
	nb_words = 0;
	state_in_word = 0;
	while (str[i])
	{
		if (state_in_word == 0)
		{
			if (!ft_isspace(str[i]))
			{
				++nb_words;
				state_in_word = 1;
			}
		}
		else
			if (ft_isspace(str[i]))
				state_in_word = 0;
		++i;
	}
	return (nb_words);
}

static void	skip_separators(char const *str, int *i)
{
	while (ft_isspace(str[*i]))
		++(*i);
}

static void	*malloc_failure(char **word_array, int nb_malloced_words)
{
	int	j;

	j = 0;
	while (j < nb_malloced_words)
	{
		free(word_array[j]);
		word_array[j] = NULL;
		j++;
	}
	free(word_array);
	word_array[j] = NULL;
	return (NULL);
}

static char	*get_word(char const *str, int *i)
{
	int		len_word;
	char	*word;

	len_word = 0;
	while (str[*i + len_word] && !ft_isspace(str[*i + len_word]))
		++len_word;
	word = NULL;
	word = ft_strndup(&str[*i], len_word);
	*i += ++len_word;
	return (word);
}

char	**ft_split_whitespaces(char const *str)
{
	int		i;
	int		j;
	char	**word_array;
	int		nb_words;

	word_array = NULL;
	nb_words = count_words(str);
	word_array = malloc(sizeof(*word_array) * (nb_words + 1));
	if (word_array == NULL)
		return (word_array);
	i = 0;
	while (i <= nb_words)
		word_array[i++] = NULL;
	i = 0;
	skip_separators(str, &i);
	j = 0;
	while (j < nb_words)
	{
		word_array[j] = get_word(str, &i);
		if (word_array[j] == NULL)
			return (malloc_failure(word_array, j));
		skip_separators(str, &i);
		++j;
	}
	return (word_array);
}
