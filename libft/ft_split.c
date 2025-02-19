/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:55:59 by pkieszek          #+#    #+#             */
/*   Updated: 2024/12/17 10:56:00 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Allocates (with malloc(3)) and returns an array of strings obtained 
	by splitting ’s’ using the character ’c’ as a delimiter. The array 
	must end with a NULL pointer.
	It returns the array of new strings resulting from the split or NULL 
	if the allocation fails.
*/

#include "libft.h"

static int		count_words(char const *s, char c);
static char		*add_word(char *word, char const *s, size_t i, size_t word_len);
static char		**split_words(char const *s, char c, char **ptr, size_t words);
static void		mem_free(char **strs, size_t count);

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	words;

	if (!s || !*s)
	{
		ptr = malloc(sizeof(char *));
		if (ptr == NULL)
			return (NULL);
		ptr[0] = NULL;
		return (ptr);
	}
	words = count_words(s, c);
	ptr = malloc((words + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	split_words(s, c, ptr, words);
	ptr[words] = NULL;
	return (ptr);
}

static int	count_words(char const *s, char c)
{
	size_t	i;
	int		counter;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			counter++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (counter);
}

static char	*add_word(char *word, char const *s, size_t i, size_t word_len)
{
	size_t	k;

	k = 0;
	while (k < word_len)
	{
		word[k] = s[i + k];
		++k;
	}
	word[k] = '\0';
	return (word);
}

static char	**split_words(char const *s, char c, char **ptr, size_t words)
{
	size_t	i;
	size_t	word_no;
	size_t	word_len;

	i = 0;
	word_no = 0;
	while (word_no < words)
	{
		word_len = 0;
		while (s[i] && s[i] == c)
			++i;
		while (s[i + word_len] && s[i + word_len] != c)
			++word_len;
		ptr[word_no] = malloc(word_len + 1);
		if (ptr[word_no] == NULL)
		{
			mem_free(ptr, word_no);
			return (NULL);
		}
		add_word(ptr[word_no], s, i, word_len);
		i += word_len;
		++word_no;
	}
	ptr[word_no] = NULL;
	return (ptr);
}

static void	mem_free(char **strs, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		++i;
	}
	free(strs);
}
