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

void    push_cl(t_circular_list **cl1, t_circular_list **cl2)
{
    t_node  *node_to_push;

    if (!(*cl1) || !(*cl1)->head)
        return ;
    node_to_push = (*cl1)->head;
    // Atualiza a cabeça da lista cl1
    (*cl1)->head = node_to_push->next;
    if ((*cl1)->head == node_to_push)
    {
        (*cl1)->head = NULL;
        (*cl1)->tail = NULL;
    }
    else
    {
        // Mais de um nó na lista cl1
        (*cl1)->head->prev = (*cl1)->tail;
        (*cl1)->tail->next = (*cl1)->head;
    }
    if (!(*cl2)->head)
    {
        (*cl2)->head = node_to_push;
        (*cl2)->tail = node_to_push;
        node_to_push->next = node_to_push;
        node_to_push->prev = node_to_push;
    }
    else
    {
        if (node_to_push == (*cl2)->head)
            return;
        // Adiciona o nó à lista cl2
        node_to_push->next = (*cl2)->head;
        node_to_push->prev = (*cl2)->tail;
        (*cl2)->head->prev = node_to_push;
        (*cl2)->tail->next = node_to_push;
        (*cl2)->head = node_to_push;
    }
}