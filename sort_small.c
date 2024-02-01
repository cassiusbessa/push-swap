/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:34:19 by caqueiro          #+#    #+#             */
/*   Updated: 2024/01/31 20:21:53 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_circular_list **stack_a)
{
	t_node	*biggest;

	biggest = (*stack_a)->bigger;
	if ((*stack_a)->head == biggest)
		rotate_cl(stack_a, 'a');
	else if ((*stack_a)->head->next == biggest)
		reverse_rotate_cl(stack_a, 'a');
	if (!is_sorted(*stack_a))
		swap_cl(stack_a, 'a');
}

void	sort_4(t_circular_list **stack_a, t_circular_list **stack_b, int index)
{
	if ((*stack_a)->head->index == index)
	{
		push_cl(stack_a, stack_b, 'b');
		sort_3(stack_a);
		push_cl(stack_b, stack_a, 'a');
	}
	else if ((*stack_a)->head->next->index == index)
	{
		swap_cl(stack_a, 'a');
		push_cl(stack_a, stack_b, 'b');
		sort_3(stack_a);
		push_cl(stack_b, stack_a, 'a');
	}
	else
	{
		reverse_rotate_cl(stack_a, 'a');
		sort_4(stack_a, stack_b, index);
	}
}

void	sort_5(t_circular_list **stack_a, t_circular_list **stack_b)
{
	if ((*stack_a)->head->index == 0)
	{
		push_cl(stack_a, stack_b, 'b');
		sort_4(stack_a, stack_b, 1);
		push_cl(stack_b, stack_a, 'a');
	}
	else if ((*stack_a)->head->next->index == 0)
	{
		swap_cl(stack_a, 'a');
		push_cl(stack_a, stack_b, 'b');
		sort_4(stack_a, stack_b, 1);
	}
	else
	{
		if (!is_sorted(*stack_a))
		{
			reverse_rotate_cl(stack_a, 'a');
			sort_5(stack_a, stack_b);
		}
	}
	push_cl(stack_b, stack_a, 'a');
}
