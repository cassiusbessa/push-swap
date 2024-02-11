/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:52:45 by caqueiro          #+#    #+#             */
/*   Updated: 2024/02/08 17:51:49 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void handle_error(t_circular_list *stack_a, void *stack_b)
{
  write(2, "Error\n", 6);
  destroy_circular(stack_a);
  if (stack_b)
    destroy_circular((t_circular_list *)stack_b);
  exit(0);
}

void handle_checker_error(t_circular_list *stack_a, void *stack_b, char *i)
{
  write(2, "Error\n", 6);
  destroy_circular(stack_a);
  stack_a = NULL;
  if (stack_b)
  {
    destroy_circular((t_circular_list *)stack_b);
    stack_b = NULL;
  }
  if (i)
    free(i);
  i = NULL;
  exit(0);
}
