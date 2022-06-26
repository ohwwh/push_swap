/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:47:29 by ohw               #+#    #+#             */
/*   Updated: 2022/03/14 20:22:24 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# define LONG_MAX 9223372036854775807
# define LONG_MIN -9223372036854775808U
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define PA 1
# define PB 2
# define SA 3
# define SB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

typedef struct s_list
{
	int				content;
	int				state;
	int				count_a;
	struct s_list	*next;
	struct s_list	*prev;
}t_list;

t_list	*create_node(int num, t_list **del1, t_list **del2);
int		push(int num, t_list **lst, t_list **del);
int		pop(t_list **lst);
void	delete_lst(t_list **lst);
int		swap_stack(t_list **lst);
void	rotate(t_list **lst);
void	reverse_rotate(t_list **lst);
t_list	*search(t_list *lst, int index);
int		get_size(t_list *lst);
int		dup_check(t_list *lst);
int		count_state(t_list *lst, int size);
int		is_sorted(t_list *lst, int size);
int		abs(int x);
int		bigger(int x, int y);
int		smaller(int x, int y);
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);
long	ft_strtol(const char *str);
int		ft_strtol_error(const char *str);
void	print_non_rotate(int command, t_list **lstA, t_list **lstB);
void	print_rotate(int command, t_list **lstA, t_list **lstB);
int		print_error(void);
int		get_state(t_list *lstA, t_list *o, int sizeA);
int		count_a(t_list *lstA, int num, int sizeA, int state);
int		count_all(int count_a, int count_b);
int		find_optimal(t_list *lstA, t_list *lstB, int sizeA, int sizeb);
void	process_main(t_list **lstA, t_list **lstB, int sizeA, int sizeB);
void	process_final(t_list **A);
int		end_return(int ret, t_list **lstA, t_list **lstB);
void	ft_bzero(void *s, size_t n);
int		execute(char *command, t_list **lstA, t_list **lstB);
int		execute_rotate(char *command, t_list **lstA, t_list **lstB);
int		execute_non_rotate(char *command, t_list **lstA, t_list **lstB);

#endif
