/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:53:34 by hiennguy          #+#    #+#             */
/*   Updated: 2024/11/25 16:27:49 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	in_word;
	int	count;

	in_word = 0;
	count = 0;
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

static char	*copy_word(const char *s, int start, char c)
{
	int		end;
	int		word_len;
	int		i;
	char	*word;

	end = start;
	while (s[end] != '\0' && s[end] != c)
		end++;
	word_len = end - start;
	word = malloc((word_len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < word_len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[word_len] = '\0';
	return (word);
}

static void	cleanup(char **all_words)
{
	int	i;

	i = 0;
	while (all_words[i] != NULL)
	{
		free(all_words[i]);
		i++;
	}
	free(all_words);
}

static int	initialize(char const *s, char c, char **all_words)
{
	int	start;
	int	index;

	start = 0;
	index = 0;
	while (s[start] != '\0')
	{
		while (s[start] == c)
			start++;
		if (s[start] == '\0')
			break ;
		all_words[index] = copy_word(s, start, c);
		if (all_words[index] == NULL)
			return (0);
		index++;
		while (s[start] != '\0' && s[start] != c)
			start++;
	}
	all_words[index] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	if (!s)
		return (NULL);
	const int	word_count = count_words(s, c);
	char		**all_words;

	all_words = malloc((word_count + 1) * sizeof(char *));
	if (!all_words)
		return (NULL);
	if (initialize(s, c, all_words) == 0)
	{
		cleanup(all_words);
		return (NULL);
	}
	return (all_words);
}

//TEST STARTS HEEERREEEEE
void	print_split(char **result)
{
	if (!result)
	{
		printf("Result is NULL\n");
		return;
	}
	for (int i = 0; result[i] != NULL; i++)
		printf("[%d]: \"%s\"\n", i, result[i]);
}

// Function to free memory for split result
void	free_split(char **result)
{
	if (!result)
		return;
	for (int i = 0; result[i] != NULL; i++)
		free(result[i]);
	free(result);
}

// Test function for ft_split
void	test_ft_split(void)
{
	char	**result;

	printf("Test 1: Normal case\n");
	result = ft_split("Hello World Welcome to C", ' ');
	print_split(result);
	free_split(result);

	printf("\nTest 2: Multiple delimiters in a row\n");
	result = ft_split("Hello,,,World,,Welcome", ',');
	print_split(result);
	free_split(result);

	printf("\nTest 3: No delimiters\n");
	result = ft_split("HelloWorld", ',');
	print_split(result);
	free_split(result);

	printf("\nTest 4: Only delimiters\n");
	result = ft_split(",,,,,", ',');
	print_split(result);
	free_split(result);

	printf("\nTest 5: Leading and trailing delimiters\n");
	result = ft_split(",Hello,World,", ',');
	print_split(result);
	free_split(result);

	printf("\nTest 6: Empty string\n");
	result = ft_split("", ',');
	print_split(result);
	free_split(result);

	printf("\nTest 7: String with only spaces\n");
	result = ft_split("     ", ' ');
	print_split(result);
	free_split(result);

	printf("\nTest 8: Single word\n");
	result = ft_split("Hello", ' ');
	print_split(result);
	free_split(result);

	printf("\nTest 9: Single character delimiter\n");
	result = ft_split(",", ',');
	print_split(result);
	free_split(result);

	printf("\nTest 10: NULL input\n");
	result = ft_split(NULL, ',');
	print_split(result); // Undefined behavior if ft_split does not handle NULL
	free_split(result);

	printf("\nTest 11: Long string\n");
	result = ft_split("This,is,a,long,string,with,commas,separating,words", ',');
	print_split(result);
	free_split(result);

	printf("\nTest 12: Memory stress test\n");
	result = ft_split("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 'z');
	print_split(result);
	free_split(result);

	printf("\nTest 13: Delimiter not in string\n");
	result = ft_split("NoDelimitersHere", ',');
	print_split(result);
	free_split(result);
}

int	main(void)
{
	test_ft_split();
	return (0);
}
