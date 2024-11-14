/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:11:38 by hiennguy          #+#    #+#             */
/*   Updated: 2024/11/13 16:39:29 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}

int main()
{
	void	*mem1;
	void	*mem2;

	mem1 = ft_calloc(3, 555555555555555555);
	mem2 = calloc(3, 555555555555555555);
	
	printf("ft_calloc pointer: %p\n", mem1);
	printf("calloc pointer: %p\n", mem2);

	if (mem1 && mem2 && memcmp(mem1, mem2, 15) == 0)
		printf("Test1 Passed: ft_calloc matches calloc\n");
	else if (!mem1 && !mem2)
	{
		printf("Test1 Passed: NULL BOTH OF THEM! \n");
	}
	else
		printf("Test1 Failed: ft_calloc does not match calloc\n");

	free(mem1);
	free(mem2);

	//TEST 2

	mem1 = ft_calloc(3, 5);
	mem2 = calloc(3, 5);
	
	printf("ft_calloc pointer: %p\n", mem1);
	printf("calloc pointer: %p\n", mem2);

	if (mem1 && mem2 && memcmp(mem1, mem2, 15) == 0)
		printf("Test2 Passed: ft_calloc matches calloc\n");
	else if (!mem1 && !mem2)
	{
		printf("Test2 Passed: NULL BOTH OF THEM! \n");
	}
	else
		printf("Test2 Failed: ft_calloc does not match calloc\n");

	free(mem1);
	free(mem2);
	//TEST 3

	mem1 = ft_calloc(0, 0);
	mem2 = calloc(0, 0);
	
	printf("ft_calloc pointer: %p\n", mem1);
	printf("calloc pointer: %p\n", mem2);

	if (mem1 && mem2 && memcmp(mem1, mem2, 15) == 0)
		printf("Test3 Passed: ft_calloc matches calloc\n");
	else if (!mem1 && !mem2)
	{
		printf("Test3 Passed: NULL BOTH OF THEM! \n");
	}
	else
		printf("Test3 Failed: ft_calloc does not match calloc\n");

	free(mem1);
	free(mem2);
}

