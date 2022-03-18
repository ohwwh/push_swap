/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:07:11 by ohw               #+#    #+#             */
/*   Updated: 2022/03/14 20:21:23 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_a(t_list *lstA, int num, int sizeA, int state)
{
	int		i;
	int		j;
	t_list	*temp;

	lstA = search(lstA, state);
	temp = lstA -> prev;
	i = 0;
	j = 0;
	while (i ++ < sizeA && num > lstA -> content)
		lstA = lstA -> next;
	lstA = temp;
	while (j ++ < sizeA && num < lstA -> content)
		lstA = lstA -> prev;
	i = (i - 1 + state) % sizeA;
	j = (j - 1 + sizeA - state) % sizeA;
	if (i <= j)
		return (i);
	else
		return (-j);
}

int	count_all(int count_a, int count_b)
{
	int	ret;

	if (count_b >= 0)
	{
		if (count_a >= 0)
			ret = bigger(count_a, count_b) + 1;
		else
			ret = abs(count_a) + count_b + 1;
	}
	else
	{
		if (count_a < 0)
			ret = bigger(abs(count_a), abs(count_b)) + 1;
		else
			ret = count_a + abs(count_b) + 1;
	}
	return (ret);
}

int	opt_front(t_list *lstA, t_list *lstB, int sizeA, int state)
{
	int			min;
	int			i;
	int			j;
	int			m;
	const int	sizeb = get_size(lstB);

	i = 0;
	min = 99999;
	while (i ++ < sizeb)
	{
		m = count_all(count_a(lstA, lstB -> content, sizeA, state), i - 1);
		if (m < min)
		{
			min = m;
			j = i - 1;
		}
		lstB = lstB -> next;
	}
	return (j);
}

int	opt_reverse(t_list *lstA, t_list *lstB, int sizeA, int state)
{
	int			min;
	int			i;
	int			j;
	int			m;
	const int	sizeb = get_size(lstB);

	i = 1;
	min = 99999;
	while (i ++ <= sizeb)
	{
		m = count_all(count_a(lstA, lstB -> content, sizeA, state), -(i - 1));
		if (m < min)
		{
			min = m;
			j = -(i - 1);
		}
		lstB = lstB -> prev;
	}
	return (j);
}

int	opt(t_list *lstA, t_list *lstB, int sizeA, int state)
{
	const int	f = opt_front(lstA, lstB, sizeA, state);
	const int	r = opt_reverse(lstA, lstB -> prev, sizeA, state);
	const int	af = count_a(lstA, search(lstB, f)->content, sizeA, state);
	const int	ar = count_a(lstA, search(lstB, r)->content, sizeA, state);

	if (count_all(af, f) <= count_all(ar, r))
		return (f);
	else
		return (r);
}
