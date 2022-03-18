/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:04:10 by ohw               #+#    #+#             */
/*   Updated: 2022/03/12 01:04:05 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_non_rotate(char *command, t_list **lstA, t_list **lstB)
{
	ft_putstr_fd(command, 1);
	if (!ft_strcmp(command, "sa\n"))
		swap_stack(lstA);
	else if (!ft_strcmp(command, "sb\n"))
		swap_stack(lstB);
	else if (!ft_strcmp(command, "pa\n") && *lstB)
	{
		push((*lstB)->content, lstA, lstB);
		pop(lstB);
	}
	else if (!ft_strcmp(command, "pb\n") && *lstA)
	{
		push((*lstA)->content, lstB, lstA);
		pop(lstA);
	}
}

void	print_rotate(char *command, t_list **lstA, t_list **lstB)
{
	ft_putstr_fd(command, 1);
	if (!ft_strcmp(command, "ra\n"))
		rotate(lstA);
	else if (!ft_strcmp(command, "rb\n"))
		rotate(lstB);
	else if (!ft_strcmp(command, "rr\n"))
	{
		rotate(lstA);
		rotate(lstB);
	}
	else if (!ft_strcmp(command, "rra\n"))
		reverse_rotate(lstA);
	else if (!ft_strcmp(command, "rrb\n"))
		reverse_rotate(lstB);
	else if (!ft_strcmp(command, "rrr\n"))
	{
		reverse_rotate(lstA);
		reverse_rotate(lstB);
	}
}

int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (-1);
}
