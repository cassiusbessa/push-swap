/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:59:14 by caqueiro          #+#    #+#             */
/*   Updated: 2024/01/30 20:51:25 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils/libft/libft.h"

typedef struct s_node
{
	struct s_node	*prev;
	int				value;
	unsigned int	index;
	struct s_node	*next;
}	t_node;

typedef struct s_circular_list
{
	t_node			*head;
	unsigned int	size;
	t_node			*bigger;
	t_node			*smaller;
	t_node			*tail;
}	t_circular_list;

void			handle_error(t_circular_list *stack_a, void *stack_b);
int				check_repeat(t_circular_list *cl);
t_circular_list	*stack_creator(int len, char **input);
t_node			*create_node(int value);
t_circular_list	*create_circular(void);
void			print_cl(t_circular_list *cl);
void			add_tail(t_circular_list **cl, t_node *new_node);
void			add_head(t_circular_list **cl, t_node *new_head);
t_node			*remove_head(t_circular_list **cl);
t_node			*remove_tail(t_circular_list **cl);
void			destroy_circular(t_circular_list *cl);
void			rotate_cl(t_circular_list **cl, char stack);
void			reverse_rotate_cl(t_circular_list **cl, char stack);
void			push_cl(t_circular_list **cl1,
					t_circular_list **cl2, char stack);
void			swap_cl(t_circular_list **cl, char stack);
void			index_cl(t_circular_list **cl);
int				is_sorted(t_circular_list *cl);
unsigned int	node_max_bits(t_circular_list *cl);
void			radix(t_circular_list **stack_a, t_circular_list **stack_b);
void			sort_3(t_circular_list **stack_a);
void			sort_4(t_circular_list **stack_a,
					t_circular_list **stack_b, int index);
void			sort_5(t_circular_list **stack_a, t_circular_list **stack_b);

#endif
