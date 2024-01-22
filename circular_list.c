/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:06:53 by caqueiro          #+#    #+#             */
/*   Updated: 2024/01/19 19:39:22 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_circular_list	*create_circular(void)
{
	t_circular_list	*cl;

	cl = malloc(sizeof (t_circular_list));
	if (cl != NULL)
	{
		cl->head = NULL;
		cl->tail = NULL;
		cl->size = 0;
	}
	return (cl);
}

t_node	*create_node(int value)
{
	t_node	*nd;

	nd = malloc(sizeof (t_node));
	if (nd == NULL)
		return (NULL);
	nd->prev = NULL;
	nd->value = value;
	nd->next = NULL;
	nd->index = -1;
	return (nd);
}

void	destroy_circular(t_circular_list *cl)
{
	t_node	*current;
	t_node	*next;

	if (cl == NULL)
		return ;
	current = cl->head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
		if (current == cl->head)
			break ;
	}
	free(cl);
	cl = NULL;
}

void	print_cl(t_circular_list *cl)
{
	t_node	*current;
	t_node	*next;

	if (cl == NULL)
		return ;
	current = cl->head;
	while (current != NULL)
	{
		next = current->next;
		ft_printf("value:%d, index:%d\n", current->value, current->index);
		current = next;
		if (current == cl->head)
			break ;
	}
	return ;
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
