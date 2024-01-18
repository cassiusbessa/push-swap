#include "push_swap.h"

void    swap_cl(t_circular_list **cl)
{
    t_node  *swp;
    t_node  *penult;
    t_node  *second;

    if (!(*cl) || !(*cl)->head || !(*cl)->tail || (*cl)->head == (*cl)->tail)
        return ;
    penult = (*cl)->tail->prev;
    penult->next = (*cl)->head;
    second = (*cl)->head->next;
    second->prev = (*cl)->head;
    (*cl)->tail->next = (*cl)->head->next;
    (*cl)->tail->prev = (*cl)->head;
    (*cl)->head->next = (*cl)->tail;
    (*cl)->head->prev = penult;
    swp = (*cl)->head;
    (*cl)->head = (*cl)->tail;
    (*cl)->tail = swp;    
}