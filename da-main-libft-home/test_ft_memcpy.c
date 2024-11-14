/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:11:38 by hiennguy          #+#    #+#             */
/*   Updated: 2024/11/13 20:10:22 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dest && !src)
		return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

int main()
{
    char src[30];
    char dst[30];

    // Test case 1
    memset(dst, 'o', 30);
    strcpy(src, "zyxwvutsrqponCUTHEREmlkjihg");
    if (dst != ft_memcpy(dst, src, 14))
        printf("dest's address was not returned\n");
    printf("Test case 1: %.*s\n", 30, dst);

    // Test case 2
    memset(dst, 'o', 30);
    strcpy(src, "zyxwvutst");
    if (dst != ft_memcpy(dst, src, 0))
        printf("dest's address was not returned\n");
    printf("Test case 2: %.*s\n", 30, dst);

    // Test case 3
    memset(dst, 'o', 30);
    memcpy(src, "zy\0xw\0vu\0\0tsr", 11);  // Manually copy with null characters
    if (dst != ft_memcpy(dst, src, 11))
        printf("dest's address was not returned\n");
    printf("Test case 3: ");
    for (int i = 0; i < 30; i++)
        printf("%c", dst[i] ? dst[i] : '.'); // if dst[i] is not null, DO LIKE NORMAL , if null, print '.' -> Display null characters as dots for visibility
    printf("\n");
    
    return 0;
}
