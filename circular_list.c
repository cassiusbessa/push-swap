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
		cl->bigger = NULL;
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
	ft_printf("list size: %u, bigger n: %d\n", cl->size, cl->bigger->value);
	return ;
}
