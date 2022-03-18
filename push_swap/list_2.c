/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:00:25 by ohw               #+#    #+#             */
/*   Updated: 2022/03/14 20:22:58 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*search(t_list *lst, int index)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	if (index >= 0)
	{
		while (i < index)
		{
			lst = lst -> next;
			i ++;
		}
	}
	else
	{
		while (i < -index)
		{
			lst = lst -> prev;
			i ++;
		}
	}
	return (lst);
}

int	get_size(t_list *lst)
{
	int		size;
	t_list	*org;

	if (!lst)
		return (0);
	size = 0;
	org = lst;
	while (1)
	{
		lst = lst -> next;
		size ++;
		if (lst == org)
			break ;
	}
	return (size);
}

int	dup_check(t_list *lst)
{
	t_list	*org;
	t_list	*check;

	if (!lst)
		return (0);
	org = lst;
	lst = lst -> next;
	while (org != lst)
	{
		check = org;
		while (check != lst)
		{
			if (check -> content == lst -> content)
				return (1);
			check = check -> next;
		}
		lst = lst -> next;
	}
	return (0);
}

int	count_state(t_list *lst, int size)
{
	int	i;

	if (!lst)
		return (0);
	if (size == 1)
		return (1);
	i = 1;
	while (lst -> content <= lst -> next -> content)
	{
		lst = lst -> next;
		i ++;
	}
	if (i == size)
		i = 0;
	return (i);
}

int	is_sorted(t_list *lst, int size)
{
	if (!lst)
		return (0);
	if (size == 1)
		return (1);
	while (lst -> next -> content >= lst -> content)
	{
		lst = lst -> next;
		size --;
		if (size == 1)
			return (1);
	}
	return (-1);
}
