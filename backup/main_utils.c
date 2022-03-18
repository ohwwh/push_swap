/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:34:48 by ohw               #+#    #+#             */
/*   Updated: 2022/03/13 11:45:41 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

int	end_return(int ret, t_list **lstA, t_list **lstB)
{
	delete_lst(lstA);
	delete_lst(lstB);
	if (ret)
		return (print_error());
	else
		return (0);
}
