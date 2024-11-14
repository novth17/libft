/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:11:38 by hiennguy          #+#    #+#             */
/*   Updated: 2024/11/13 17:07:16 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	len = count_digits(n);
	num = n;
	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		num = -num;
		len++;
	}
	str = malloc((len + 1) * (sizeof(char)));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
void ft_print_result(char *result)
{
    if (result)
        printf("Result: %s\n", result);
    else
        printf("Error: Null result\n");
}

int main()
{
    // Test cases
    char *res;

    // Test 1: Zero case
    res = ft_itoa(0);
    ft_print_result(res);
    free(res);

    // Test 2: Positive number
    res = ft_itoa(9);
    ft_print_result(res);
    free(res);

    // Test 3: Negative number
    res = ft_itoa(-9);
    ft_print_result(res);
    free(res);

    // Test 4: Larger positive number
    res = ft_itoa(10);
    ft_print_result(res);
    free(res);

    // Test 5: Larger negative number
    res = ft_itoa(-10);
    ft_print_result(res);
    free(res);

    // Test 6: Larger number
    res = ft_itoa(8124);
    ft_print_result(res);
    free(res);

    // Test 7: Larger negative number
    res = ft_itoa(-9874);
    ft_print_result(res);
    free(res);

    // Test 8: Large positive number
    res = ft_itoa(543000);
    ft_print_result(res);
    free(res);

    // Test 9: Edge case for int min value
    res = ft_itoa(-2147483648LL);
    ft_print_result(res);
    free(res);

    // Test 10: Edge case for int max value
    res = ft_itoa(2147483647);
    ft_print_result(res);
    free(res);

    return 0;
}
