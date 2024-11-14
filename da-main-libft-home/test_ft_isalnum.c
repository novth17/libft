/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:11:38 by hiennguy          #+#    #+#             */
/*   Updated: 2024/11/13 16:49:14 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}

int main() {
    // Test cases
    int test_cases[] = {
        'a',  // lowercase letter
        'Z',  // uppercase letter
        '1',  // digit
        '!',  // special character
        ' ',  // whitespace
        0,    // NULL character (edge case)
        255,  // edge case for extended ASCII (non-printable)
        127,  // edge case for DEL (non-printable)
        '0',  // '0' as a digit (edge case)
        'z'   // 'z' as a lowercase letter (edge case)
    };

    // Testing ft_isalnum
    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
        int c = test_cases[i];
        printf("Character: %c (ASCII: %d) -> ft_isalnum: %d, isalnum: %d\n",
               c, c, ft_isalnum(c), isalnum(c));
    }

    return 0;
}
