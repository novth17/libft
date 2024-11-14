/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:11:38 by hiennguy          #+#    #+#             */
/*   Updated: 2024/11/13 17:31:19 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;
	int				result;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		result = ptr1[i] - ptr2[i];
		if (result != 0)
			return (result);
		i++;
	}
	return (0);
}

int main() {
    // Test case 1: Identical strings
    printf("ft_memcmp result: %d\n", ft_memcmp("salut", "salut", 5));
    printf("memcmp result: %d\n", memcmp("salut", "salut", 5));

    // Test case 2: Strings with non-printable characters
    printf("ft_memcmp result: %d\n", ft_memcmp("t\200", "t\0", 2));
    printf("memcmp result: %d\n", memcmp("t\200", "t\0", 2));

    // Test case 3: First string is longer
    printf("ft_memcmp result: %d\n", ft_memcmp("testss", "test", 5));
    printf("memcmp result: %d\n", memcmp("testss", "test", 5));

    // Test case 4: Different case in characters
    printf("ft_memcmp result: %d\n", ft_memcmp("test", "tEst", 4));
    printf("memcmp result: %d\n", memcmp("test", "tEst", 4));

    // Test case 5: Empty string vs non-empty
    printf("ft_memcmp result: %d\n", ft_memcmp("", "test", 4));
    printf("memcmp result: %d\n", memcmp("", "test", 4));

    // Test case 6: Non-empty string vs empty
    printf("ft_memcmp result: %d\n", ft_memcmp("test", "", 4));
    printf("memcmp result: %d\n", memcmp("test", "", 4));

    // Test case 7: Strings differ after a few characters
    printf("ft_memcmp result: %d\n", ft_memcmp("abcdefghij", "abcdefgxyz", 7));
    printf("memcmp result: %d\n", memcmp("abcdefghij", "abcdefgxyz", 7));

    // Test case 8: Strings differ in a specific character
    printf("ft_memcmp result: %d\n", ft_memcmp("abcdefgh", "abcdwxyz", 6));
    printf("memcmp result: %d\n", memcmp("abcdefgh", "abcdwxyz", 6));

    // Test case 9: Zero length comparison
    printf("ft_memcmp result: %d\n", ft_memcmp("zyxbcdefgh", "abcdefgxyz", 0));
    printf("memcmp result: %d\n", memcmp("zyxbcdefgh", "abcdefgxyz", 0));

    return 0;
}
