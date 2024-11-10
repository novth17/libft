/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:07:02 by hiennguy          #+#    #+#             */
/*   Updated: 2024/11/10 21:07:06 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*temp;
	if (!lst || !del)
		return ;
	if (lst != NULL)
	{
		temp = lst->next;
		del(lst->content);
		free(lst);
		lst = temp;
	}
}

static void del(void *content)
{
	free(content);
}

int main(void)
{
	t_list *node1 = ft_lstnew(ft_strdup("15"));
	t_list *node2 = ft_lstnew(ft_strdup("25"));
	t_list *node3 = ft_lstnew(ft_strdup("35"));
	t_list *temp;

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	
	temp = node1;
	while (temp != NULL)
	{
		printf("Before delete: %s\n", (char *)(temp->content));
		temp = temp->next;
	}
	node1->next = node2->next;  // Link node1 to node3, must do this before delete note 2
	ft_lstdelone(node2, del);   // Now safely delete node2
	
	temp = node1;
	while (temp != NULL)
	{
		printf("After delete one becomes %s\n", (char *)(temp->content));
		temp = temp->next;
	}
}