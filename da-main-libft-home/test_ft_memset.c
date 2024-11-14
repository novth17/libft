/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:11:38 by hiennguy          #+#    #+#             */
/*   Updated: 2024/11/13 20:47:15 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

int main()
{
    char str1[20] = "Hello, World!";
    char str2[20] = "Hello, World!";
    size_t len = 3;
    int c = 'X';

    // Using your custom ft_memset
    ft_memset(str1, c, len);
    printf("ft_memset result: %s\n", str1);

    // Reset str2 for comparison
    strcpy(str2, "Hello, World!");

    // Using standard memset
    memset(str2, c, len);
    printf("memset result: %s\n", str2);

    // Additional Check to make sure they are equivalent
    if (strcmp(str1, str2) == 0)
        printf("Both functions give the same result.\n");
    else
        printf("The functions give different results.\n");

    return 0;
}
