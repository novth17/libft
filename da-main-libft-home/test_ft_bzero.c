/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:11:38 by hiennguy          #+#    #+#             */
/*   Updated: 2024/11/13 16:18:06 by hiennguy         ###   ########.fr       */
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

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

int main()
{
	void	*mem1;
	void	*mem2;

	// Allocate memory
	mem2 = malloc(5);
	if (!mem1 || !mem2)
		return (1);

	// Test 1: Set both buffers to 'e' and apply ft_bzero and bzero
	memset(mem1, 'e', 5);
	memset(mem2, 'e', 5);
	ft_bzero(mem1, 5);
	bzero(mem2, 5);

	// Compare results of ft_bzero and bzero
	if (memcmp(mem1, mem2, 5) == 0)
		printf("Test 1 Passed: ft_bzero matches bzero\n");
	else
		printf("Test 1 Failed: ft_bzero does not match bzero\n");

	// Test 2: Test with zero length
	memset(mem1, 'e', 5);
	memset(mem2, 'e', 5);
	ft_bzero(mem1, 0);
	bzero(mem2, (0));

	// Compare again for zero-length case
	if (memcmp(mem1, mem2, 5) == 0)
		printf("Test 2 Passed: Zero-length ft_bzero matches bzero\n");
	else
		printf("Test 2 Failed: Zero-length ft_bzero does not match bzero\n");

	// Cleanup
	free(mem1);
	free(mem2);

	return (0);
}

