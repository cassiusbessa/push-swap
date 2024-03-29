/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:36:23 by caqueiro          #+#    #+#             */
/*   Updated: 2024/02/20 15:59:51 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_circular_list	*stack_a;
	t_circular_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = stack_creator(argc - 1, argv);
	if (is_sorted(stack_a))
	{
		destroy_circular(stack_a);
		return (1);
	}
	stack_b = create_circular();
	index_cl(&stack_a);
	if (stack_a->size == 3)
		sort_3(&stack_a);
	else if (stack_a->size == 4)
		sort_4(&stack_a, &stack_b, 0);
	else if (stack_a->size == 5)
		sort_5(&stack_a, &stack_b);
	else
		radix(&stack_a, &stack_b);
	destroy_circular(stack_a);
	destroy_circular(stack_b);
}
