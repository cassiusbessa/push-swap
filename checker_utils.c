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

static void exec_move(char *input, t_circular_list **stack_a, t_circular_list **stack_b)
{
    ft_printf(input);
    if (ft_strncmp(input, "sa", 2))
        return (swap_cl(stack_a, 'a', 1));
    else if (ft_strncmp(input, "sb", 2))
        return (swap_cl(stack_b, 'b', 0));
    else if (ft_strncmp(input, "pa", 2))
        return (push_cl(stack_a, stack_b, 'a', 0));
    else if (ft_strncmp(input, "pb", 2))
        return (push_cl(stack_a, stack_b, 'a', 0));
    else if (ft_strncmp(input, "ra", 2))
        return (rotate_cl(stack_a, 'a', 0));
    else if (ft_strncmp(input, "rb", 2))
        return (rotate_cl(stack_a, 'b', 0));
    else if (ft_strncmp(input, "rra", 3))
        return (reverse_rotate_cl(stack_a, 'a', 0));
    else if (ft_strncmp(input, "rrb", 3))
        return (reverse_rotate_cl(stack_a, 'b', 0));
    else
    {
        ft_printf("isso não existe");
        return (handle_checker_error(*stack_a, *stack_b, input));
    }
    
}

int main(int argc, char **argv)
{
        char    *input;
    	t_circular_list	*stack_a;
        t_circular_list	*stack_b;

        stack_a = stack_creator(argc - 1, argv);
	    stack_b = create_circular();
    while (1)
    {
        input = get_next_line(1);
        ft_printf("entrei com: %s", input);
        exec_move(input, &stack_a, &stack_b);
        ft_printf("executei");
    }
    free(input);
    if (is_sorted(stack_a) && !stack_b->size)
    {
        destroy_circular(stack_a);
        destroy_circular(stack_b);
        return (ft_printf("OK"));
    }
        destroy_circular(stack_a);
        destroy_circular(stack_b);
    return (ft_printf("KO"));
}