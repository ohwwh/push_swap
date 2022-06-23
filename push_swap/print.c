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

void	print_command(int command)
{
	if (command == PA)
		ft_putstr_fd("pa\n", 1);
	else if (command == PB)
		ft_putstr_fd("pb\n", 1);
	else if (command == SA)
		ft_putstr_fd("sa\n", 1);
	else if (command == SB)
		ft_putstr_fd("sb\n", 1);
	else if (command == RA)
		ft_putstr_fd("ra\n", 1);
	else if (command == RB)
		ft_putstr_fd("rb\n", 1);
	else if (command == RR)
		ft_putstr_fd("rr\n", 1);
	else if (command == RRA)
		ft_putstr_fd("rra\n", 1);
	else if (command == RRB)
		ft_putstr_fd("rrb\n", 1);
	else if (command == RRR)
		ft_putstr_fd("rrr\n", 1);
}

void	print_non_rotate(int command, t_list **lstA, t_list **lstB)
{
	print_command(command);
	if (command == SA)
		swap_stack(lstA);
	else if (command == SB)
		swap_stack(lstB);
	else if (command == PA && (*lstB) != 0)
	{
		push((*lstB)->content, lstA, lstB);
		pop(lstB);
	}
	else if (command == PB && (*lstA) != 0)
	{
		push((*lstA)->content, lstB, lstA);
		pop(lstA);
	}
}

void	print_rotate(int command, t_list **lstA, t_list **lstB)
{
	print_command(command);
	if (command == RA)
		rotate(lstA);
	else if (command == RB)
		rotate(lstB);
	else if (command == RR)
	{
		rotate(lstA);
		rotate(lstB);
	}
	else if (command == RRA)
		reverse_rotate(lstA);
	else if (command == RRB)
		reverse_rotate(lstB);
	else if (command == RRR)
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
