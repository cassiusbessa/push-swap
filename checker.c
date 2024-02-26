/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 22:52:40 by caqueiro          #+#    #+#             */
/*   Updated: 2024/02/26 14:08:58 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_move(char *input, t_circular_list **stack_a,
						t_circular_list **stack_b)
{
	if (!ft_strncmp(input, "sa\n", ft_strlen(input)))
		return (swap_cl(stack_a, 'a', 0));
	else if (!ft_strncmp(input, "sb\n", ft_strlen(input)))
		return (swap_cl(stack_b, 'b', 0));
	else if (!ft_strncmp(input, "pa\n", ft_strlen(input)))
		return (push_cl(stack_b, stack_a, 'a', 0));
	else if (!ft_strncmp(input, "pb\n", ft_strlen(input)))
		return (push_cl(stack_a, stack_b, 'b', 0));
	else if (!ft_strncmp(input, "ra\n", ft_strlen(input)))
		return (rotate_cl(stack_a, 'a', 0));
	else if (!ft_strncmp(input, "rb\n", ft_strlen(input)))
		return (rotate_cl(stack_b, 'b', 0));
	else if (!ft_strncmp(input, "rra\n", ft_strlen(input)))
		return (reverse_rotate_cl(stack_a, 'a', 0));
	else if (!ft_strncmp(input, "rrb\n", ft_strlen(input)))
		return (reverse_rotate_cl(stack_a, 'b', 0));
	else if (!ft_strncmp(input, "rrr\n", ft_strlen(input)))
	{
		reverse_rotate_cl(stack_a, 'a', 0);
		return (reverse_rotate_cl(stack_b, 'b', 0));
	}
	return (handle_checker_error(*stack_a, *stack_b, input));
}

int	main(int argc, char **argv)
{
	t_circular_list	*stack_a;
	t_circular_list	*stack_b;
	char			*input;

	stack_a = stack_creator(argc - 1, argv);
	stack_b = create_circular();
	if (argc < 2)
		return (1);
	while (1)
	{
		input = get_next_line(1, 0);
		if (!input)
			break ;
		exec_move(input, &stack_a, &stack_b);
		free(input);
	}
	if (is_sorted(stack_a) && !stack_b->size)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	destroy_circular(stack_a);
	destroy_circular(stack_b);
	free(input);
}
