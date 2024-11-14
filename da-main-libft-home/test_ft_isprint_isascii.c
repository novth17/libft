/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint_isascii.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:11:38 by hiennguy          #+#    #+#             */
/*   Updated: 2024/11/13 16:56:00 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}

int ft_isascii(int c)
{
    if (c >= 0 && c <= 127)
        return (1);
    return (0);
}

int ft_isprint(int c)
{
    if (c >= 32 && c <= 126)
        return (1);
    return (0);
}

// Test the functions
int main()
{
    int test_cases[] = {
        -1,         // Negative value (not ASCII)
        0,          // ASCII NUL (Non-printable)
        31,         // Non-printable ASCII control character (Unit separator)
        32,         // Space (printable)
        64,         // '@' (printable)
        126,        // '~' (printable)
        127,        // DEL (non-printable)
        128,        // Beyond ASCII range (non-ASCII)
        200,        // Beyond ASCII range (non-ASCII)
    };

    printf("Testing ft_isascii and ft_isprint:\n");

    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
        int c = test_cases[i];
        printf("Character: %d -> ft_isascii: %d, ft_isprint: %d\n",
               c, ft_isascii(c), ft_isprint(c));
    }
    return 0;
}
