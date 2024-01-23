/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_circular_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:47:11 by caqueiro          #+#    #+#             */
/*   Updated: 2024/01/19 20:14:54 by caqueiro         ###   ########.fr       */
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
	(*cl)->size--;
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
	(*cl)->size++;
}

t_node	*remove_tail(t_circular_list **cl)
{
	t_node	*removed_node;

	if (!(*cl) || !(*cl)->head || !(*cl)->tail || (*cl)->head == (*cl)->tail)
		return (NULL);
	removed_node = (*cl)->tail;
	if ((*cl)->head == (*cl)->tail)
	{
		(*cl)->head = NULL;
		(*cl)->tail = NULL;
	}
	else
	{
		(*cl)->tail->prev->next = (*cl)->head;
		(*cl)->head->prev = (*cl)->tail->prev;
		(*cl)->tail = (*cl)->tail->prev;
	}
	(*cl)->size--;
	return (removed_node);
}

void	add_tail(t_circular_list **cl, t_node *new_node)
{
	if (*cl == NULL)
		*cl = create_circular();
	if ((*cl)->head == NULL)
	{
		(*cl)->head = new_node;
		(*cl)->tail = new_node;
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		new_node->prev = (*cl)->tail;
		new_node->next = (*cl)->head;
		(*cl)->tail->next = new_node;
		(*cl)->tail = new_node;
		(*cl)->head->prev = new_node;
	}
	(*cl)->size++;
}
