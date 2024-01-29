#include "push_swap.h"

void    radix(t_circular_list **stack_a, t_circular_list **stack_b)
{
    unsigned int    bits;
    unsigned int    max_bits;
    unsigned int    initial_size;

    bits = 0;
    max_bits = node_max_bits(*stack_a);
    initial_size = (*stack_a)->size;
    while (bits <= max_bits && !is_sorted(*stack_a))
    {
        initial_size = (*stack_a)->size;
        while (initial_size-- && !is_sorted(*stack_a))
        {
            if ((*stack_a)->head->index >> bits & 1)
                    rotate_cl(stack_a, 'a');
            else
                push_cl(stack_a, stack_b, 'b');
        }
        while ((*stack_b)->size)
            push_cl(stack_b, stack_a, 'a');
        bits++;
    }
}