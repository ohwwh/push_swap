/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 01:18:31 by ohw               #+#    #+#             */
/*   Updated: 2022/03/14 20:36:59 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

static int	process_parse(t_list **a, t_list **b, int argc)
{
	int		j;

	while (1)
	{
		j = execute(get_next_line(0), a, b);
		if (j == -1)
			return (-1);
		else if (j == 1)
			break ;
	}
	if (is_sorted(*a, argc - 1) == 1 && *b == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (0);
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
	//return (end_return(process_parse(&a, &b, argc), &a, &b));
	end_return(process_parse(&a, &b, argc), &a, &b);
	while (1);
}
