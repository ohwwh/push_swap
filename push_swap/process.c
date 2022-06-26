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
		print_non_rotate(SA, lstA, 0);
	else
		return ;
	(*lstA)->state = 0;
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
		print_non_rotate(SA, lstA, 0);
		print_rotate(RA, lstA, 0);
	}
	else if (num2 <= num1 && num1 <= num3)
		print_non_rotate(SA, lstA, 0);
	else if (num2 <= num3 && num3 <= num1)
		print_rotate(RA, lstA, 0);
	else if (num3 <= num1 && num1 <= num2)
		print_rotate(RRA, lstA, 0);
	else if (num3 <= num2 && num2 <= num1)
	{
		print_non_rotate(SA, lstA, 0);
		print_rotate(RRA, lstA, 0);
	}
	(*lstA)->state = 0;
}

static void	process_main_case_1(int i, int j, t_list **lstA, t_list **lstB)
{
	int	k;

	k = 0;
	if (j >= 0)
	{
		while (k ++ < smaller(i, j))
			print_rotate(RR, lstA, lstB);
		if (i <= j)
		{
			while (k ++ <= j)
				print_rotate(RA, lstA, lstB);
		}
		else
		{
			while (k ++ <= i)
				print_rotate(RB, lstA, lstB);
		}
	}
	else
	{
		while (k ++ < i)
			print_rotate(RB, lstA, lstB);
		while (k ++ <= abs(j) + i)
			print_rotate(RRA, lstA, lstB);
	}
}

static void	process_main_case_2(int i, int j, t_list **lstA, t_list **lstB)
{
	int	k;

	k = 0;
	if (j < 0)
	{
		while (k ++ < abs(bigger(i, j)))
			print_rotate(RRR, lstA, lstB);
		if (i >= j)
		{
			while (k ++ <= abs(j))
				print_rotate(RRA, lstA, lstB);
		}
		else
		{
			while (k ++ <= abs(i))
				print_rotate(RRB, lstA, lstB);
		}
	}
	else
	{
		while (k ++ < abs(i))
			print_rotate(RRB, lstA, lstB);
		while (k ++ <= j + abs(i))
			print_rotate(RA, lstA, lstB);
	}
}

void	process_main(t_list **lstA, t_list **lstB, int sizeA, int sizeB)
{
	int		i;
	int		j;
	int		t;
	t_list *opt;

	if (sizeA == 2)
		process_2(lstA);
	else if (sizeA == 3)
		process_3(lstA);
	else
	{
		if (is_sorted((*lstA), sizeA) != -1)
			return ;
		print_non_rotate(PB, lstA, lstB);
		process_main(lstA, lstB, sizeA - 1, sizeB + 1);
		j = (*lstA)->state;
		i = find_optimal(*lstA, *lstB, sizeA - 1, sizeB + 1);
		opt = search(*lstB, i);
		j = opt -> count_a;
		t = get_state(*lstA, opt, sizeA - 1);
		if (i >= 0)
			process_main_case_1(i, j, lstA, lstB);
		else
			process_main_case_2(i, j, lstA, lstB);
		print_non_rotate(PA, lstA, lstB);
		(*lstA)->state = t;
	}
}
