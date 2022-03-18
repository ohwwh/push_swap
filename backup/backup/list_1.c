/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:53:29 by ohw               #+#    #+#             */
/*   Updated: 2022/03/12 01:08:50 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int num, t_list **del1, t_list **del2)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
	{
		delete_lst(del1);
		delete_lst(del2);
		exit(1);
	}
	lst -> content = num;
	lst -> next = lst;
	lst -> prev = lst;
	return (lst);
}

int	push(int num, t_list **lst, t_list **del)
{
	t_list	*newnode;

	newnode = create_node(num, lst, del);
	if (*lst)
	{
		newnode -> next = *lst;
		newnode -> prev = (*lst)->prev;
		(*lst)->prev -> next = newnode;
		(*lst)->prev = newnode;
	}
	*lst = newnode;
	return (1);
}

int	pop(t_list **lst)
{
	t_list	*delnode;

	if (*lst == 0)
		return (0);
	if (get_size(*lst) == 1)
	{
		free(*lst);
		*lst = 0;
		return (1);
	}
	delnode = *lst;
	(*lst)->next -> prev = (*lst)->prev;
	(*lst)->prev -> next = (*lst)->next;
	*lst = (*lst)->next;
	free(delnode);
	delnode = 0;
	return (1);
}

void	delete_lst(t_list **lst)
{
	while (*lst)
		pop(lst);
}
