/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:11:38 by hiennguy          #+#    #+#             */
/*   Updated: 2024/11/07 17:14:46 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int count_digits(int n)
{
	int count;

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
	return count;
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;
	int		is_negative;

	len = count_digits(n);
	num = n;
	is_negative = n < 0;

	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
    if (is_negative)
    {
		num = -num;
		len++;
	}
	str = malloc((len + 1) * (sizeof(char)));
	if (str == NULL)
		return NULL;
	str[len] = '\0';
	while (len--)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}

// int main (void)
// {
// 	int n1 = -9999;
// 	int n2 = -0;
// 	int n3 = 9999;
// 	int n4 = 9999;
// 	int n5 = -2147483648;
// 	int n6 = -1775546437;

// 	printf("%s\n", ft_itoa(n1));
// 	printf("%s\n", ft_itoa(n2));
// 	printf("%s\n", ft_itoa(n3));
// 	printf("%s\n", ft_itoa(n4));
// 	printf("%s\n", ft_itoa(n5));
// 	printf("%s\n", ft_itoa(n6));

// }