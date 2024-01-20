/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:43:00 by caqueiro          #+#    #+#             */
/*   Updated: 2024/01/19 19:29:47 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_cl(t_circular_list **cl)
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
}

void	push_cl(t_circular_list **cl1, t_circular_list **cl2)
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
}

void	rotate_cl(t_circular_list **cl)
{
	t_node	*swp;

	if (!(*cl) || !(*cl)->head || !(*cl)->tail || (*cl)->head == (*cl)->tail)
		return ;
	swp = remove_head(cl);
	add_tail(cl, swp);
}

void	reverse_rotate_cl(t_circular_list **cl)
{
	t_node	*swp;

	if (!(*cl) || !(*cl)->head || !(*cl)->tail || (*cl)->head == (*cl)->tail)
		return ;
	swp = remove_tail(cl);
	add_head(cl, swp);
}
