/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 02:07:58 by ohw               #+#    #+#             */
/*   Updated: 2022/03/12 01:12:12 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define BUFFER_SIZE 3
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char *str);
size_t	ft_strnlen(char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strndup(char *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
int		execute(char *command, t_list **lstA, t_list **lstB);
int		execute_rotate(char *command, t_list **lstA, t_list **lstB);
int		execute_non_rotate(char *command, t_list **lstA, t_list **lstB);

#endif
