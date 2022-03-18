/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:16:33 by ohw               #+#    #+#             */
/*   Updated: 2022/03/13 13:23:37 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_final(t_list **A, int size)
{
	int	i;
	int	j;

	i = 0;
	j = count_sorted(*A, size);
	if (size / 2 < j)
	{
		j = size - j;
		while (i ++ < j)
			print_rotate("rra\n", A, 0);
	}
	else
	{
		while (i ++ < j)
			print_rotate("ra\n", A, 0);
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	long	j;
	t_list	*a;
	t_list	*b;

	if (argc == 1)
		return (0);
	i = 0;
	while (i ++ < argc - 1)
	{	
		j = ft_strtol(argv[argc - i]);
		if (!ft_strtol_error(argv[argc - i]) | (j > INT_MAX | j < INT_MIN))
			return (end_return(-1, &a, &b));
		push(j, &a, &b);
	}
	if (dup_check(a))
		return (end_return(-1, &a, &b));
	b = 0;
	process_main(&a, &b, argc - 1, 0);
	process_final(&a, argc - 1);
	return (end_return(0, &a, &b));
}
