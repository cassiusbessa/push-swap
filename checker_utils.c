/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 22:52:40 by caqueiro          #+#    #+#             */
/*   Updated: 2024/02/08 21:39:33 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_move(char *input, t_circular_list **stack_a,
						t_circular_list **stack_b)
{
	if (!ft_strncmp(input, "sa", 2))
		return (swap_cl(stack_a, 'a', 0));
	else if (!ft_strncmp(input, "sb", 2))
		return (swap_cl(stack_b, 'b', 0));
	else if (!ft_strncmp(input, "pa", 2))
		return (push_cl(stack_a, stack_b, 'a', 0));
	else if (!ft_strncmp(input, "pb", 2))
		return (push_cl(stack_a, stack_b, 'a', 0));
	else if (!ft_strncmp(input, "ra", 2))
		return (rotate_cl(stack_a, 'a', 0));
	else if (!ft_strncmp(input, "rb", 2))
		return (rotate_cl(stack_a, 'b', 0));
	else if (!ft_strncmp(input, "rra", 3))
		return (reverse_rotate_cl(stack_a, 'a', 0));
	else if (!ft_strncmp(input, "rrb", 3))
		return (reverse_rotate_cl(stack_a, 'b', 0));
	return (handle_checker_error(*stack_a, *stack_b, input));
}

int	main(int argc, char **argv)
{
	t_circular_list	*stack_a;
	t_circular_list	*stack_b;
	char							*input;

	stack_a = stack_creator(argc - 1, argv);
	stack_b = create_circular();
	while (input = get_next_line(1))
	{
		exec_move(input, &stack_a, &stack_b);
		free(input);
	}
	if (is_sorted(stack_a) && !stack_b->size)
	{
		destroy_circular(stack_a);
		destroy_circular(stack_b);
		free(input);
		return (ft_printf("OK\n"));
	}
	destroy_circular(stack_a);
	destroy_circular(stack_b);
	free(input);
	return (ft_printf("KO\n"));
}
