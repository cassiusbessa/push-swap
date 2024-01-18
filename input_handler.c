/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:55:22 by caqueiro          #+#    #+#             */
/*   Updated: 2024/01/15 18:18:11 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_atoi_error(t_circular_list *stack)
{
	write(1, "Input not valid", 15);
	destroy_circular(stack);
	exit (0);
}

static int	find_separator(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static	void	build_list(t_circular_list **stack_a, char *s, char c)
{
	int			ex;
	int			skip;
	char		*temp;
	t_int_valid	n;

	ex = 0;
	skip = 0;
	while (*s)
	{
		if (*s != c)
		{
			skip = find_separator(s, c);
			temp = ft_substr(s, 0, skip);
			n = ft_atoi(temp);
			free(temp);
			if (n.err)
				handle_atoi_error(*stack_a);
			add_node(stack_a, create_node(n.value));
			s += skip;
			ex++;
			continue ;
		}
		s++;
	}
}

static t_circular_list	*split_num(char *s, char c)
{
	t_circular_list	*stack_a;

	stack_a = create_circular();
	if (!s)
		return (NULL);
	build_list(&stack_a, s, ' ');
	return (stack_a);
}

t_circular_list	*stack_creator(int len, char **input)
{
	t_circular_list	*stack_a;
	int				i;
	t_int_valid		n;

	stack_a = NULL;
	i = 1;
	if (len == 1)
		stack_a = split_num(input[1], ' ');
	else
	{
		stack_a = create_circular();
		while (i <= len)
		{
			n = ft_atoi(input[i]);
			if (n.err)
				handle_atoi_error(stack_a);
			add_node(&stack_a, create_node(n.value));
			i++;
		}
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_circular_list	*stack_a;

	if	(argc < 2)
	{
		write(1, "Input not valid\n", 15);
		return (0);
	}
	stack_a = stack_creator(argc - 1, argv);
	swap_cl(&stack_a);
	ft_printf("%d\n", stack_a->current->value);
	ft_printf("%d\n", stack_a->current->next->value);
	ft_printf("%d\n", stack_a->current->next->next->value);
	destroy_circular(stack_a);
}