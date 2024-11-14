/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:11:38 by hiennguy          #+#    #+#             */
/*   Updated: 2024/11/13 17:19:39 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		target;
	size_t				i;

	ptr = (unsigned char *)s;
	target = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == target)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}

int main() 
{
    char s[] = "Hihahohe539275";
    void *ft_memchr_result = ft_memchr(s, 'a', 7);
    void *memchr_result = memchr(s, 'a', 7);
    
    printf("ft_memchr result: %p\n", ft_memchr_result);
    printf("memchr result: %p\n", memchr_result);

    if (ft_memchr_result == memchr_result)
        printf("Both functions returned the same result.\n");
    else
        printf("The functions returned different results.\n");

    return 0;

}
