/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:52:20 by ohw               #+#    #+#             */
/*   Updated: 2022/03/10 14:13:13 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

int	bigger(int x, int y)
{
	if (x >= y)
		return (x);
	else
		return (y);
}

int	smaller(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		ft_putstr_fd("(null)", 1);
	else
	{
		while (s && *s)
		{
			write(fd, s, 1);
			s ++;
		}
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' | *s2 != '\0') && *s2 == *s1)
	{
		s1 ++;
		s2 ++;
	}
	return (*s1 - *s2);
}
