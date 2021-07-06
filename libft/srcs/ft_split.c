/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:46:11 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/06 19:48:31 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static char	*get_word(char const *str, int *i, char *charset)
{
	int		len_word;
	char	*word;

	len_word = 0;
	while (str[*i + len_word] && is_charset(str[*i + len_word], charset) == 0)
		++len_word;
	word = NULL;
	word = ft_strndup(&str[*i], len_word);
	*i += ++len_word;
	return (word);
}

char	**ft_split(char const *str, char *charset)
{
	int		i;
	int		j;
	char	**word_array;
	int		nb_words;

	word_array = NULL;
	nb_words = count_words(str, charset);
	word_array = malloc(sizeof(*word_array) * (nb_words + 1));
	if (word_array == NULL)
		return (word_array);
	i = 0;
	while (i <= nb_words)
		word_array[i++] = NULL;
	i = 0;
	skip_separators(str, &i, charset);
	j = 0;
	while (j < nb_words)
	{
		word_array[j] = get_word(str, &i, charset);
		if (word_array[j] == NULL)
			return (malloc_failure(word_array, j));
		skip_separators(str, &i, charset);
		++j;
	}
	return (word_array);
}
