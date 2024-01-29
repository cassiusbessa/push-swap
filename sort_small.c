#include "push_swap.h"

void    sort_3(t_circular_list **stack_a)
{
    t_node  *biggest;

    biggest = (*stack_a)->bigger;

    if ((*stack_a)->head == biggest)
        rotate_cl(stack_a, 'a');
    else if ((*stack_a)->head->next == biggest)
        reverse_rotate_cl(stack_a, 'a');
    if (!is_sorted(*stack_a))
        swap_cl(stack_a, 'a');
}