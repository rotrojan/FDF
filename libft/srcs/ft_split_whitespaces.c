/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:31:28 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/06 19:51:05 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define WHITESPACES " \t\n\v\f\r"

static void	skip_separators(char const *str, int *i, char *charset)
{
	if (*charset == '\0')
		return ;
	while (is_charset(str[*i], charset) == 1)
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
	nb_words = count_words(str, WHITESPACES);
	word_array = malloc(sizeof(*word_array) * (nb_words + 1));
	if (word_array == NULL)
		return (word_array);
	i = 0;
	while (i <= nb_words)
		word_array[i++] = NULL;
	i = 0;
	skip_separators(str, &i, WHITESPACES);
	j = 0;
	while (j < nb_words)
	{
		word_array[j] = get_word(str, &i);
		if (word_array[j] == NULL)
			return (malloc_failure(word_array, j));
		skip_separators(str, &i, WHITESPACES);
		++j;
	}
	return (word_array);
}
