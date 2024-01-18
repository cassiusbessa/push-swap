/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:59:14 by caqueiro          #+#    #+#             */
/*   Updated: 2024/01/09 20:02:39 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include "utils/libft/libft.h"
# include "utils/ft_printf/ft_printf.h"

typedef struct s_node
{
	struct s_node	*prev;
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_circular_list
{
	t_node	*head;
	t_node	*current;
	t_node	*tail;
}	t_circular_list;

t_node			*create_node(int value);
t_circular_list	*create_circular(void);
void			add_node(t_circular_list **cl, t_node *new_node);
void			destroy_circular(t_circular_list *cl);
void			swap_cl(t_circular_list **cl);

#endif
