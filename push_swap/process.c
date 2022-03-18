/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:05:00 by ohw               #+#    #+#             */
/*   Updated: 2022/03/14 20:21:46 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_2(t_list **lstA)
{
	if ((*lstA)->content > (*lstA)->next -> content)
		print_non_rotate("sa\n", lstA, 0);
	else
		return ;
}

static void	process_3(t_list **lstA)
{
	const int	num1 = (*lstA)->content;
	const int	num2 = (*lstA)->next -> content;
	const int	num3 = (*lstA)->prev -> content;

	if (num1 <= num2 && num2 <= num3)
		return ;
	else if (num1 <= num3 && num3 <= num2)
	{
		print_non_rotate("sa\n", lstA, 0);
		print_rotate("ra\n", lstA, 0);
	}
	else if (num2 <= num1 && num1 <= num3)
		print_non_rotate("sa\n", lstA, 0);
	else if (num2 <= num3 && num3 <= num1)
		print_rotate("ra\n", lstA, 0);
	else if (num3 <= num1 && num1 <= num2)
		print_rotate("rra\n", lstA, 0);
	else if (num3 <= num2 && num2 <= num1)
	{
		print_non_rotate("sa\n", lstA, 0);
		print_rotate("rra\n", lstA, 0);
	}
}

static void	process_main_case_1(int i, int j, t_list **lstA, t_list **lstB)
{
	int	k;

	k = 0;
	if (j >= 0)
	{
		while (k ++ < smaller(i, j))
			print_rotate("rr\n", lstA, lstB);
		if (i <= j)
		{
			while (k ++ <= j)
				print_rotate("ra\n", lstA, lstB);
		}
		else
		{
			while (k ++ <= i)
				print_rotate("rb\n", lstA, lstB);
		}
	}
	else
	{
		while (k ++ < i)
			print_rotate("rb\n", lstA, lstB);
		while (k ++ <= abs(j) + i)
			print_rotate("rra\n", lstA, lstB);
	}
}

static void	process_main_case_2(int i, int j, t_list **lstA, t_list **lstB)
{
	int	k;

	k = 0;
	if (j < 0)
	{
		while (k ++ < abs(bigger(i, j)))
			print_rotate("rrr\n", lstA, lstB);
		if (i >= j)
		{
			while (k ++ <= abs(j))
				print_rotate("rra\n", lstA, lstB);
		}
		else
		{
			while (k ++ <= abs(i))
				print_rotate("rrb\n", lstA, lstB);
		}
	}
	else
	{
		while (k ++ < abs(i))
			print_rotate("rrb\n", lstA, lstB);
		while (k ++ <= j + abs(i))
			print_rotate("ra\n", lstA, lstB);
	}
}

void	process_main(t_list **lstA, t_list **lstB, int sizeA, int sizeB)
{
	int	i;
	int	j;

	if (sizeA == 2)
		process_2(lstA);
	else if (sizeA == 3)
		process_3(lstA);
	else
	{
		if (is_sorted((*lstA), sizeA) != -1)
			return ;
		print_non_rotate("pb\n", lstA, lstB);
		process_main(lstA, lstB, sizeA - 1, sizeB + 1);
		i = opt(*lstA, *lstB, sizeA - 1, count_state(*lstA, sizeA - 1));
		j = count_state(*lstA, sizeA - 1);
		j = count_a(*lstA, search(*lstB, i)->content, sizeA - 1, j);
		if (i >= 0)
			process_main_case_1(i, j, lstA, lstB);
		else
			process_main_case_2(i, j, lstA, lstB);
		print_non_rotate("pa\n", lstA, lstB);
	}
}
