/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:41:01 by hiennguy          #+#    #+#             */
/*   Updated: 2024/11/12 19:27:57 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*substr;
// 	size_t	s_len;
// 	size_t	substr_length;

// 	s_len = ft_strlen(s);
// 	if (start >= s_len)
// 		return (ft_strdup(""));
// 	substr_length = len;
// 	if (len > s_len - start)
// 		substr_length = s_len - start;
// 	if (substr_length >= SIZE_MAX)
// 		substr_length = SIZE_MAX - 1;
// 	substr = malloc((substr_length + 1) * sizeof(char));
// 	if (substr == NULL)
// 		return (NULL);
// 	ft_strlcpy (substr, s + start, len + 1);
// 	return (substr);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substr_len;
	size_t	s_len;
	char	*substr;

	if (start >= ft_strlen(s))
	{
		substr = (char *)malloc(sizeof(char));
		if (substr != NULL)
			*substr = '\0';
		return (substr);
	}
	s_len = ft_strlen(s + start);
	if (len > s_len)
		substr_len = s_len;
	else
		substr_len = len;
	substr = (char *)malloc((substr_len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, (substr_len + 1));
	return (substr);
}
