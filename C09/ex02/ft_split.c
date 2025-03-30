/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:59:55 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/27 09:45:52 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	is_sep(char c, char *sep)
{
	size_t	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
		{
			return (1);
		}
		++i;
	}
	return (0);
}

int	count_word(char *str, char *sep)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (!is_sep(str[i], sep))
		{
			++words;
			while (str[i] && !is_sep(str[i], sep))
				++i;
		}
		else
			++i;
	}
	return (words);
}

char	*ft_words_split(char *str, char *sep)
{
	size_t	i;
	char	*word;

	i = 0;
	while (str[i] && !is_sep(str[i], sep))
		++i;
	word = malloc(i + 1);
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[i] && !is_sep(str[i], sep))
	{
		word[i] = str[i];
		++i;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**words;
	size_t	i;
	size_t	j;

	if (!str || !charset)
		return (NULL);
	words = malloc((sizeof (char *)) * count_word(str, charset) + 1);
	if (words == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (!is_sep(str[i], charset))
		{
			words[j] = ft_words_split(&str[i], charset);
			while (!is_sep(str[i], charset) && str[i])
				++i;
			++j;
		}
		else
			++i;
	}
	words[j] = NULL;
	return (words);
}
