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


char **ft_split(char const *s, char c)
{	
	const int	word_count = count_words(s, c);
	char		**words;

	words = malloc((word_count + 1) * sizeof(char *));

	words[0] = "ab";
	words[1] = "bc";
	words[2] = NULL;

	printf("%s\n", words[0]);
	printf("%s\n", words[1]);
	printf("is NULL? %d\n", words[2] == NULL);

}

int main()
{
	ft_split("Hello World", ' ');
}
