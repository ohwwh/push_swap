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
	while (i < sizeA && num > lstA -> content)
	{
		lstA = lstA -> next;
		i ++;
	}
	j = sizeA - i;
	i = (i + state) % sizeA;
	j = (j + sizeA - state) % sizeA;
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

int	opt(t_list *lstA, t_list *lstB, int sizeA, int sizeb, int state)
{
	int			min;
	int			i;
	int			j;
	int			t;
	int			m;
	//const int	sizeb = get_size(lstB);

	i = 0;
	min = 99999;
	while (i ++ < sizeb)
	{
		t = count_a(lstA, lstB -> content, sizeA, state);
		lstB -> count_a = t;
		m = count_all(t, i - 1);
		if (m < min)
		{
			min = m;
			j = i - 1;
		}
		m = count_all(t, -1 * (sizeb - (i - 1)));
		if (m < min)
		{
			min = m;
			j = -1 * (sizeb - (i - 1));
		}
		lstB = lstB -> next;
	}
	return (j);
}
