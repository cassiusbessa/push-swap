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
	(*cl)->size--;
	return (removed_node);
}

static t_node	*get_min_node(t_node *n)
{
	t_node	*current;
	t_node	*min;

	if (n == NULL)
		return (NULL);
	min = n;
	current = n->next;
	while (current != n)
	{
		if (current->index == -1 && current->value < min->value)
			min = current;
		current = current->next;
	}
	if (min && min->index == -1)
		return (min);
	else
		return (NULL);
}

void	index_cl(t_circular_list **cl)
{
	t_node			*current;
	t_node			*min;
	unsigned int	i;
	unsigned int	size;

	if (*cl == NULL || !(*cl)->head)
		return ;
	i = 0;
	size = (*cl)->size;
	current = (*cl)->head;
	while (i < size)
	{
		min = get_min_node(current);
		if (min)
			min->index = i++;
		current = current->next;
	}
}
