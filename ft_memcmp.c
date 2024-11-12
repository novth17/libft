/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:11:38 by hiennguy          #+#    #+#             */
/*   Updated: 2024/11/12 16:21:12 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;
	int				result;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		result = str1[i] - str2[i];
		if (result != 0)
			return (result);
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>
#include "libft.h"
int	ft_memcmp (const void *s1, const void *s2, size_t n);

int main()
{
	char test1[] = {0, 0, 127, 0};
	char test2[] = {0, 0, 42, 0};

	printf("my ft_memcmp is %d\n", ft_memcmp(test1, test2, 4));

	printf("REAL memcmp is %d\n", memcmp(test1, test2, 4));

	return 0;
}
