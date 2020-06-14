#include "../headers/swap_node.h"

void MenuSwap(Head* p0)
{
    int index1, index2;
    do
    {
        print_list(p0);
        printf("Select id's that you want to swipe (first index is lower then second):\n");
        printf("0 - exit from menu\n");
        printf("Enter first id: ");
        index1 = safe_scand();
        if(index1!=0)
        {
            printf("Enter second id: ");
            index2 = safe_scand();
            if ((index1 < index2)&&(((index1>=1)&&(index1<=p0->cnt))&&((index2>=1)&&(index2<=p0->cnt))))
            {
                swap_elem(p0,index1,index2);
                rebuild_id(p0);
            }
        }
    }while(index1!=0);
}

void swap_elem(Head* p0,int index1,int index2)
{
    Node *p1 = NULL, *p2 = NULL, *a = NULL, *b = NULL, *c = NULL , *d = NULL;
    p1 = ssearch(p0,index1);
    p2 = ssearch(p0,index2);
    a = p0->first;
    b = p0->last;
    a->prev = b;
    b->next = a;
    if(p1->next == p2)
    {
        a = p1->prev;
        b = p2->next;
        if (p1 == p0->first)
            p0->first = p2;
        if (p2 == p0->last)
            p0->last = p1;
        a->next = p2;
        b->prev = p1;
        p2->prev = a;
        p2->next = p1;
        p1->prev = p2;
        p1->next = b;
    }
    else if (p1->prev == p2)
    {
        a = p1->next;
        b = p2->prev;
        p0->first = p2;
        p0->last = p1;
        a->prev = p2;
        b->next = p1;
        p2->next = a;
        p2->prev = p1;
        p1->next = p2;
        p1->prev = b;
    }
    else
    {
        a = p1->prev;
        b = p1->next;
        c = p2->prev;
        d = p2->next;
        if (p1 == p0->first)
            p0->first = p2;
        if (p2 == p0->last)
            p0->last = p1;
        a->next = p2;
        b->prev = p2;
        p2->prev = a;
        p2->next = b;
        c->next = p1;
        d->prev = p1;
        p1->prev = c;
        p1->next = d;
    }
    a = p0->first;
    b = p0->last;
    a->prev = NULL;
    b->next = NULL;
}
