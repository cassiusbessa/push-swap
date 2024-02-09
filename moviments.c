/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:43:00 by caqueiro          #+#    #+#             */
/*   Updated: 2024/02/08 21:23:13 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_cl(t_circular_list **cl, char stack, int print)
{
	t_node	*first;
	t_node	*second;

	if (!(*cl) || !(*cl)->head || !(*cl)->tail
		|| (*cl)->head == (*cl)->tail || !(*cl)->head->next)
		return ;
	first = remove_head(cl);
	second = remove_head(cl);
	add_head(cl, first);
	add_head(cl, second);
	if (print)
		ft_printf("s%c\n", stack);
}

void	push_cl(t_circular_list **cl1, t_circular_list **cl2,
				char stack, int print)
{
	t_node	*node_to_push;

	node_to_push = remove_head(cl1);
	if (!node_to_push)
		return ;
	if (!(*cl2)->head)
		add_head(cl2, node_to_push);
	else
	{
		if (node_to_push != (*cl2)->head)
			add_head(cl2, node_to_push);
	}
	if (print)
		ft_printf("p%c\n", stack);
}

void	rotate_cl(t_circular_list **cl, char stack,
					int print)
{
	t_node	*swp;

	if (!(*cl) || !(*cl)->head || !(*cl)->tail || (*cl)->head == (*cl)->tail)
		return ;
	swp = remove_head(cl);
	add_tail(cl, swp);
	if (print)
		ft_printf("r%c\n", stack);
}

void	reverse_rotate_cl(t_circular_list **cl, char stack, int print)
{
	t_node	*swp;

	if (!(*cl) || !(*cl)->head || !(*cl)->tail || (*cl)->head == (*cl)->tail)
		return ;
	swp = remove_tail(cl);
	add_head(cl, swp);
	if (print)
		ft_printf("rr%c\n", stack);
}
