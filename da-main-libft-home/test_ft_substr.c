/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:41:01 by hiennguy          #+#    #+#             */
/*   Updated: 2024/11/25 16:14:20 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	substr_length;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	substr_length = len;
	if (len > s_len - start)
		substr_length = s_len - start;
	substr = malloc((substr_length + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy (substr, s + start, (substr_length + 1));
	return (substr);
}
// Test function
int main(void)
{
	char	*s;

	// Test case 1: Normal substring
	s = ft_substr("Hello, World!", 7, 5);
	printf("Test 1: %s\n", s); // Expected: "World"
	free(s);

	// Test case 2: Start is 0
	s = ft_substr("Hello, World!", 0, 5);
	printf("Test 2: %s\n", s); // Expected: "Hello"
	free(s);

	// Test case 3: Start out of bounds
	s = ft_substr("Hello, World!", 20, 5);
	printf("Test 3: %s\n", s); // Expected: ""
	free(s);

	// Test case 4: Start at the end of the string
	s = ft_substr("Hello, World!", 13, 5);
	printf("Test 4: %s\n", s); // Expected: ""
	free(s);

	// Test case 5: Length exceeds remaining string length
	s = ft_substr("Hello, World!", 7, 20);
	printf("Test 5: %s\n", s); // Expected: "World!"
	free(s);

	// Test case 6: Length is 0
	s = ft_substr("Hello, World!", 7, 0);
	printf("Test 6: %s\n", s); // Expected: ""
	free(s);

	// Test case 7: Empty string as input
	s = ft_substr("", 0, 5);
	printf("Test 7: %s\n", s); // Expected: ""
	free(s);

	// Test case 8: Start is 0, Length is 0
	s = ft_substr("", 0, 0);
	printf("Test 8: %s\n", s); // Expected: ""
	free(s);

	// Test case 9: Entire string
	s = ft_substr("Hello, World!", 0, ft_strlen("Hello, World!"));
	printf("Test 9: %s\n", s); // Expected: "Hello, World!"
	free(s);

	// Test case 10: Very large length
	s = ft_substr("Hello", 1, 100);
	printf("Test 10: %s\n", s); // Expected: "ello"
	free(s);

	// Test case 11: Single character substring
	s = ft_substr("Hello", 4, 1);
	printf("Test 11: %s\n", s); // Expected: "o"
	free(s);

	// Test case 12: Start and length at max possible unsigned int
	s = ft_substr("Hello", UINT_MAX, UINT_MAX);
	printf("Test 12: %s\n", s); // Expected: ""
	free(s);

	// Test case 13: Start is beyond the string but len is 0
	s = ft_substr("Hello", 10, 0);
	printf("Test 13: %s\n", s); // Expected: ""
	free(s);

	// Test case 14: Start at the exact end, len 0
	s = ft_substr("Hello", ft_strlen("Hello"), 0);
	printf("Test 14: %s\n", s); // Expected: ""
	free(s);

	return (0);
}
