/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:11:38 by hiennguy          #+#    #+#             */
/*   Updated: 2024/11/08 21:42:23 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *temp;
	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	(*lst) = NULL;
}

static void del(void *content)
{
    free(content);
}
int main ()
{
    // Dynamically allocate content for each node to ensure it can be freed
    t_list *node1 = ft_lstnew(ft_strdup("15"));
    t_list *node2 = ft_lstnew(ft_strdup("20"));
    t_list *node3 = ft_lstnew(ft_strdup("25"));
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	ft_lstclear(&node1, del);
	if (node1 == NULL)
		printf("List cleared!\n");
	return 0;
}