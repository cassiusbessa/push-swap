/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:43:00 by caqueiro          #+#    #+#             */
/*   Updated: 2024/01/18 21:42:15 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*remove_head(t_circular_list **cl)
{
	t_node	*node_to_remove;

	if (!(*cl) || !(*cl)->head)
		return (NULL);
	node_to_remove = (*cl)->head;
	if ((*cl)->head == (*cl)->tail)
	{
		(*cl)->head = NULL;
		(*cl)->tail = NULL;
	}
	else
	{
		(*cl)->head = node_to_remove->next;
		(*cl)->head->prev = (*cl)->tail;
		(*cl)->tail->next = (*cl)->head;
	}
	return (node_to_remove);
}

void	add_head(t_circular_list **cl, t_node *new_head)
{
	if (!(*cl) || !new_head)
		return ;
	if (!(*cl)->head)
	{
		(*cl)->head = new_head;
		(*cl)->tail = new_head;
		new_head->next = new_head;
		new_head->prev = new_head;
	}
	else
	{
		new_head->next = (*cl)->head;
		new_head->prev = (*cl)->tail;
		(*cl)->head->prev = new_head;
		(*cl)->tail->next = new_head;
		(*cl)->head = new_head;
	}
}

t_node	*remove_tail(t_circular_list **cl)
{
	t_node	*removed_node;

	if (!(*cl) || !(*cl)->head || !(*cl)->tail || (*cl)->head == (*cl)->tail)
		return (NULL);
	removed_node = (*cl)->tail;
	if ((*cl)->head->next == (*cl)->tail)
	{
		(*cl)->head->next = (*cl)->head;
		(*cl)->tail->prev = (*cl)->tail;
	}
	else
	{
		(*cl)->tail->prev->next = (*cl)->head;
		(*cl)->head->prev = (*cl)->tail->prev;
	}
	(*cl)->tail = (*cl)->tail->prev;
	return (removed_node);
}

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
	add_node(cl, swp);
}

void	reverse_rotate_cl(t_circular_list **cl)
{
	t_node	*swp;

	if (!(*cl) || !(*cl)->head || !(*cl)->tail || (*cl)->head == (*cl)->tail)
		return ;
	swp = remove_tail(cl);
	add_head(cl, swp);
}
