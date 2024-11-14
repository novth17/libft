/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:11:38 by hiennguy          #+#    #+#             */
/*   Updated: 2024/11/13 15:43:34 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
		|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r')
	{
		nptr++;
	}
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

int main()
{
    char *ptr1 = "9999";   
    printf("%d\n", ft_atoi(ptr1));
    printf("%d\n", atoi(ptr1));

    char *ptr2 = "546:5";   
    printf("%d\n", ft_atoi(ptr2));
    printf("%d\n", atoi(ptr2));

    char *ptr3 = "-4886";   
    printf("%d\n", ft_atoi(ptr3));
    printf("%d\n", atoi(ptr3));

    char *ptr4 = "+548";   
    printf("%d\n", ft_atoi(ptr4));
    printf("%d\n", atoi(ptr4));

    char *ptr5 = "054854";   
    printf("%d\n", ft_atoi(ptr5));
    printf("%d\n", atoi(ptr5));

    
    char *ptr6 = "000074";   
    printf("%d\n", ft_atoi(ptr6));
    printf("%d\n", atoi(ptr6));

    char *ptr7 = "+-54";   
    printf("should 0%d\n", ft_atoi(ptr7));
    printf("should 0%d\n", atoi(ptr7));

    char *ptr8 = "-+48";   
    printf("should 0%d\n", ft_atoi(ptr8));
    printf("should 0%d\n", atoi(ptr8));

    char *ptr9 = "--48";   
    printf("should 0%d\n", ft_atoi(ptr9));
    printf("should 0%d\n", atoi(ptr9));

    char *ptr10 = "++48";   
    printf("should 0%d\n", ft_atoi(ptr10));
    printf("should 0%d\n", atoi(ptr10));

    char *ptr11 = "+47+5";   
    printf("%d\n", ft_atoi(ptr11));
    printf("%d\n", atoi(ptr11));

    char *ptr12 = "-47-5";   
    printf("%d\n", ft_atoi(ptr12));
    printf("%d\n", atoi(ptr12));

    char *ptr13 = "\e475";   
    printf("%d\n", ft_atoi(ptr13));
    printf("%d\n", atoi(ptr13));

    char *ptr14 = "\t\n\r\v\f  469 \n";   
    printf("%d\n", ft_atoi(ptr14));
    printf("%d\n", atoi(ptr14));

    char *ptr15 = "-2147483648";   
    printf("%d\n", ft_atoi(ptr15));
    printf("%d\n", atoi(ptr15));

    char *ptr16 = "2147483647";   
    printf("%d\n", ft_atoi(ptr16));
    printf("%d\n", atoi(ptr16));

    char *ptr17 = "\t\n\r\v\fd469 \n";   
    printf("%d\n", ft_atoi(ptr17));
    printf("%d\n", atoi(ptr17));

    char *ptr18 = "\n\n\n  -46\b9 \n5d6";   
    printf("%d\n", ft_atoi(ptr18));
    printf("%d\n", atoi(ptr18));

    char *ptr19 = "";   
    printf("%d\n", ft_atoi(ptr19));
    printf("%d\n", atoi(ptr19));

    return (0);
}
