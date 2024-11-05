/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:11:38 by hiennguy          #+#    #+#             */
/*   Updated: 2024/11/04 20:01:36 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int count_words(const char *s, char c)
{
	int in_word = 0;
	int count = 0;
	
	while (*s != '\0')
	{
		if (*s != c)
		{
			if (in_word == 0)
			{
				in_word = 1;
				count++;				
			}
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char *copy_word(const char *s, int start, char c)
{
	int end;
	int word_len;
	int i;

	end = start;

	while (s[end] != '\0' && s[end] != c)
		end++;
	word_len = end - start;
	char *word = malloc((word_len + 1) * sizeof(char));
	if (word == NULL)
		return NULL;
	i = 0;
	while (i < word_len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[word_len] = '\0';
	return word;
}


char **ft_split(char const *s, char c)
{	
	const int	word_count = count_words(s, c);
	char		**all_words;
	int	start;
	int index;

	all_words = malloc((word_count + 1) * sizeof(char *));
	if (!all_words)
		return NULL;
	
	start = 0;
	index = 0;
	while (s[start] != '\0')
	{
		//skip delimiters
		while (s[start] == c)
			start++;
		//if end of string, break the loop
		if (s[start] == '\0')
			break;
		//copy each word
		all_words[index] = copy_word(s, start, c);
		if (all_words[index] == NULL)
		{
			while (index > 0)
				free(all_words[--index]);
            free(all_words);
            return NULL;
		}
		//If you just freed all_words without freeing each word first, you'd lose the pointers to those words, which //means they would be inaccessible and the memory would not be freed, leading to a memory leak.
		index++;
		//move start to the end
		while (s[start] != '\0' && s[start] != c)
			start++;
	}
	all_words[index] == '\0';
	return all_words;
}


int main()
{
	ft_split("Hello World", ' ');
}
