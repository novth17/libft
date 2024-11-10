/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:06:51 by hiennguy          #+#    #+#             */
/*   Updated: 2024/11/10 21:40:01 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
static void f(void *content)
{
	printf("Node content: %s\n", (char*)content);
}

int main ()
{
	t_list *head;
	t_list *node1 = ft_lstnew(ft_strdup("15"));
	t_list *node2 = ft_lstnew(ft_strdup("20"));
	t_list *node3 = ft_lstnew(ft_strdup("25"));

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	ft_lstiter(node1, f);

	free(node1->content);
	free(node2->content);
	free(node3->content);
	free(node1);
	free(node2);
	free(node3);  
	
	return 0;
}