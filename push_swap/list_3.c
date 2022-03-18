/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:30:37 by ohw               #+#    #+#             */
/*   Updated: 2022/03/12 01:09:26 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

int	swap_stack(t_list **lst)
{
	t_list	*sec;

	if (*lst == 0)
		return (0);
	if ((*lst)->next == *lst)
		return (0);
	sec = (*lst)->next;
	(*lst)->next = sec -> next;
	sec -> next -> prev = *lst;
	sec -> next = *lst;
	sec -> prev = (*lst)->prev;
	(*lst)->prev -> next = sec;
	(*lst)->prev = sec;
	(*lst) = sec;
	return (1);
}

void	rotate(t_list **lst)
{
	if (*lst == 0)
		return ;
	*lst = (*lst)->next;
}

void	reverse_rotate(t_list **lst)
{
	if (*lst == 0)
		return ;
	*lst = (*lst)->prev;
}
