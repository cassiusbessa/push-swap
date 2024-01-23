/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:43:33 by caqueiro          #+#    #+#             */
/*   Updated: 2024/01/19 17:31:59 by caqueiro         ###   ########.fr       */
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
			min->index = i++;
		current = current->next;
	}
	(*cl)->bigger = min;
}

unsigned int	node_max_bits(t_circular_list *cl)
{
	unsigned int	i;
	if (!cl || !cl->head || !cl->tail || cl->head == cl->tail)
		return (0);
	i = 0;
	while (cl->bigger->value)
	{
		i++;
		cl->bigger->value >>= 1;
	}
	return (i);
}
