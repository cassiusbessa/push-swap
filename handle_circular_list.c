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

static t_node	*get_min_node(t_circular_list *cl)
{
	t_node	*current;
	t_node	*next;
	t_node	*min;

	if (cl == NULL)
		return (NULL);
	min = cl->head;
	current = cl->head;
	while (current != NULL)
	{
		next = current->next;
		if (current->index == -1 && current->value < (*min).value)
			min = current;
		current = next;
		if (current == cl->head)
			break ;
	}
	return (min);
}

void	index_cl(t_circular_list **cl)
{
	t_node	*current;
	t_node	*next;
	t_node	*min;
	int		i;

	if (cl == NULL)
		return ;
	i = 0;
	min = NULL;
	current = (*cl)->head;
	while (current != NULL)
	{
		next = current->next;
		get_min_node(*cl)->index = i;
		current = next;
		i++;
		if (current == (*cl)->head)
			break ;
	}
}
