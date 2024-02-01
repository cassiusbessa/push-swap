/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:34:39 by caqueiro          #+#    #+#             */
/*   Updated: 2024/01/31 21:13:03 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	if (*cl == NULL || !(*cl)->head)
		return ;
	i = 0;
	current = (*cl)->head;
	while (i < (*cl)->size)
	{
		min = get_min_node(current);
		if (min)
		{
			if (i == 0)
				(*cl)->smaller = min;
			min->index = i++;
		}
		current = current->next;
	}
	(*cl)->bigger = min;
}

unsigned int	node_max_bits(t_circular_list *cl)
{
	unsigned int	i;
	unsigned int	index;

	if (!cl || !cl->head || !cl->tail || cl->head == cl->tail)
		return (0);
	i = 0;
	index = cl->bigger->index;
	while (index)
	{
		i++;
		index >>= 1;
	}
	return (i);
}

int	is_sorted(t_circular_list *cl)
{
	t_node	*current;
	t_node	*next;

	if (!cl || !cl->head || !cl->tail || cl->head == cl->tail)
		return (1);
	current = cl->head;
	while (current != cl->tail)
	{
		next = current->next;
		if (next->value < current->value)
			return (0);
		current = next;
	}
	return (1);
}
