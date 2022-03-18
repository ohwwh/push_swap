/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:36:29 by ohw               #+#    #+#             */
/*   Updated: 2022/03/13 14:46:36 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

int	execute(char *command, t_list **lstA, t_list **lstB)
{
	if (!command)
		return (1);
	else if (!ft_strcmp(command, "sa\n") | !ft_strcmp(command, "sb\n"))
		return (execute_non_rotate(command, lstA, lstB));
	else if (!ft_strcmp(command, "ss\n"))
		return (execute_non_rotate(command, lstA, lstB));
	else if (!ft_strcmp(command, "pa\n") | !ft_strcmp(command, "pb\n"))
		return (execute_non_rotate(command, lstA, lstB));
	else if (!ft_strcmp(command, "ra\n") | !ft_strcmp(command, "rb\n"))
		return (execute_rotate(command, lstA, lstB));
	else if (!ft_strcmp(command, "rra\n") | !ft_strcmp(command, "rrb\n"))
		return (execute_rotate(command, lstA, lstB));
	else if (!ft_strcmp(command, "rr\n") | !ft_strcmp(command, "rrr\n"))
		return (execute_rotate(command, lstA, lstB));
	else
		return (-1);
}

int	execute_non_rotate(char *command, t_list **lstA, t_list **lstB)
{
	if (!ft_strcmp(command, "sa\n"))
		swap_stack(lstA);
	else if (!ft_strcmp(command, "sb\n"))
		swap_stack(lstB);
	else if (!ft_strcmp(command, "ss\n"))
	{
		swap_stack(lstA);
		swap_stack(lstB);
	}
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
	free(command);
	return (0);
}

int	execute_rotate(char *command, t_list **lstA, t_list **lstB)
{
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
	free(command);
	return (0);
}
