/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:43:31 by ohw               #+#    #+#             */
/*   Updated: 2022/03/12 03:04:53 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_node	*find_create_node(int fd, t_node **lst)
{
	t_node	*newnode;
	t_node	*target;

	target = *lst;
	while (target && target -> fd != fd && target -> next)
		target = target -> next;
	if (!target || (target -> fd != fd && !(target -> next)))
	{
		newnode = (t_node *)malloc(sizeof(t_node));
		if (!newnode)
			return (0);
		ft_bzero(newnode, sizeof(t_node));
		newnode -> fd = fd;
		if (target && !(target -> next))
			target -> next = newnode;
		else
			*lst = newnode;
		target = newnode;
	}
	return (target);
}

void	delete_node(t_node **lst, int fd)
{
	t_node	*prev;
	t_node	*target;

	prev = *lst;
	target = *lst;
	if (!target)
		return ;
	else if (target -> fd == fd)
	{
		prev = *lst;
		*lst = (*lst)-> next;
		free(prev);
		prev = 0;
		return ;
	}
	while (target -> fd != fd)
	{
		prev = target;
		target = target -> next;
	}
	prev -> next = target -> next;
	free(target);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;

	if (!s1 && !s2)
		return (0);
	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ret)
	{
		while (s1 && s1[i])
		{
			ret[i] = s1[i];
			i ++;
		}
		while (s2 && *s2)
		{
			ret[i] = *s2;
			i ++;
			s2 ++;
		}
		ret[i] = 0;
		free(s1);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_node	*lst;
	t_node			*start;
	char			temp[BUFFER_SIZE + 1];
	char			*ret;
	int				i;

	start = find_create_node(fd, &lst);
	if ((BUFFER_SIZE <= -1) | !start)
		return (0);
	ret = ft_strndup(start -> chunk, ft_strlen(start -> chunk), 1);
	ft_bzero(temp, sizeof(char) * (BUFFER_SIZE + 1));
	while (ret && !ft_strchr(ret, '\n') && read(fd, temp, BUFFER_SIZE) > 0)
	{
		ret = ft_strjoin(ret, temp);
		ft_bzero(temp, sizeof(char) * (BUFFER_SIZE + 1));
	}
	if (ret)
	{
		i = ft_strnlen(ret);
		start -> chunk = ft_strndup(&ret[i], ft_strlen(&ret[i]), 0);
		ret = ft_strndup(ret, i, 1);
	}
	if (!ret)
		delete_node(&lst, fd);
	return (ret);
}
