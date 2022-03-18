/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 02:07:58 by ohw               #+#    #+#             */
/*   Updated: 2022/03/12 01:26:11 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 3
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node{
	int				fd;
	char			*chunk;
	struct s_node	*next;
}t_node;

size_t	ft_strlen(char *str);
size_t	ft_strnlen(char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strndup(char *src, size_t n, int flag);
char	*ft_strchr(const char *s, int c);
t_node	*find_create_node(int fd, t_node **lst);
void	delete_node(t_node **lst, int fd);
char	*get_next_line(int fd);

#endif
