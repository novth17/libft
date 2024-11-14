/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:11:38 by hiennguy          #+#    #+#             */
/*   Updated: 2024/11/13 22:19:57 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (*src == '\0')
	{
		dst[0] = '\0';
		return (src_len);
	}
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

int main() {
    // Test 1: Normal concatenation with enough space in destination
    char dest1[20] = "Hello, ";
    char src1[] = "World!";
    size_t result1 = ft_strlcpy(dest1, src1, sizeof(dest1));

	char dest1a[20] = "Hello, ";
    char src1a[] = "World!";
    size_t result1a = strlcpy(dest1a, src1a, sizeof(dest1a));

    printf("Test 1 - Result: %zu\n", result1);
    printf("Test 1 - Destination: %s\n", dest1);  
	printf("Test 1 - Result: %zu\n", result1a);
    printf("Test 1 - Destination: %s\n", dest1a);  

    // Test 2: Concatenation where destination buffer is full
    char dest2[10] = "Hello, ";
    char src2[] = "World!";
    size_t result2 = ft_strlcpy(dest2, src2, sizeof(dest2));
    
    printf("Test 2 - Result: %zu\n", result2);  
    printf("Test 2 - Destination: %s\n", dest2);  

	char dest2a[10] = "Hello, ";
    char src2a[] = "World!";
    size_t result2a = strlcpy(dest2a, src2a, sizeof(dest2a));
    
    printf("Test 2 - Result: %zu\n", result2a); 
    printf("Test 2 - Destination: %s\n", dest2a); 

    // Test 3: Edge case where there is no space left in the destination
    char dest3[6] = "Hello";
    char src3[] = "World!";
    size_t result3 = ft_strlcpy(dest3, src3, sizeof(dest3));
    
    printf("Test 3 - Result: %zu\n", result3); 
    printf("Test 3 - Destination: %s\n", dest3); 

	char dest3a[6] = "Hello";
    char src3a[] = "World!";
    size_t result3a = strlcpy(dest3a, src3a, sizeof(dest3a));
    
    printf("Test 3 - Result: %zu\n", result3a); 
    printf("Test 3 - Destination: %s\n", dest3a); 


    // Test 4: Concatenation where source is empty
    char dest4[20] = "Hello, ";
    char src4[] = "";
    size_t result4 = ft_strlcpy(dest4, src4, sizeof(dest4));
    
    printf("Test 4 - Result: %zu\n", result4); 
    printf("Test 4 - Destination: %s\n", dest4); 

	char dest4a[20] = "Hello, ";
    char src4a[] = "";
    size_t result4a = strlcpy(dest4a, src4a, sizeof(dest4a));
    
    printf("Test 4 - Result: %zu\n", result4a); 
    printf("Test 4 - Destination: %s\n", dest4a);  

    return 0;
}
