/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:55:22 by caqueiro          #+#    #+#             */
/*   Updated: 2024/01/30 20:52:30 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_separator(char *s, char c)
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
				handle_error(*stack_a, NULL);
			add_tail(stack_a, create_node(n.value));
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

	if (!s)
		return (NULL);
	stack_a = create_circular();
	build_list(&stack_a, s, ' ');
	return (stack_a);
}

int	check_repeat(t_circular_list *cl)
{
	t_node	*current;
	t_node	*next;

	if (cl == NULL)
		return (1);
	if (cl->size == 1)
		return (0);
	current = cl->head;
	while (current != NULL)
	{
		next = current->next;
		if (current->value == next->value)
			return (1);
		current = next;
		if (current == cl->head)
			break ;
	}
	return (0);
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
				handle_error(stack_a, NULL);
			add_tail(&stack_a, create_node(n.value));
			i++;
		}
	}
	return (stack_a);
}
