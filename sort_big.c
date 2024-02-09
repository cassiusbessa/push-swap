/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:39:21 by caqueiro          #+#    #+#             */
/*   Updated: 2024/02/08 21:30:57 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_b(t_circular_list **stack_a, t_circular_list **stack_b,
				unsigned int bits, unsigned int max_bits)
{
	unsigned int	initial_size;

	initial_size = (*stack_b)->size;
	while (initial_size-- && bits <= max_bits && !is_sorted(*stack_a))
	{
		if ((*stack_b)->head->index >> bits & 1)
			push_cl(stack_b, stack_a, 'a', 1);
		else
			rotate_cl(stack_b, 'b', 1);
	}
	if (is_sorted(*stack_a))
	{
		while ((*stack_b)->size)
			push_cl(stack_b, stack_a, 'a', 1);
	}
}

void	radix(t_circular_list **stack_a, t_circular_list **stack_b)
{
	unsigned int	bits;
	unsigned int	max_bits;
	unsigned int	initial_size;

	bits = 0;
	max_bits = node_max_bits(*stack_a);
	initial_size = (*stack_a)->size;
	while (bits <= max_bits && !is_sorted(*stack_a))
	{
		initial_size = (*stack_a)->size;
		while (initial_size-- && !is_sorted(*stack_a))
		{
			if ((*stack_a)->head->index >> bits & 1)
				rotate_cl(stack_a, 'a', 1);
			else
				push_cl(stack_a, stack_b, 'b', 1);
		}
		bits++;
		sort_b(stack_a, stack_b, bits, max_bits);
	}
	while ((*stack_b)->size)
		push_cl(stack_b, stack_a, 'a', 1);
}
