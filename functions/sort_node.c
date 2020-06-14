#include "../headers/sort_node.h"

void MenuSort(Head *p0)
{
    int option, way;
    do
    {
        print_list(p0);
        printf("Kinds of sort:\n");
        printf("0 - exit from menu (id's will replace)\n");
        printf("1 - by id\n");
        printf("2 - by name\n");
        printf("3 - by subject\n");
        printf("4 - by averenge\n");
        printf("5 - by age\n");
        printf("6 - by minutes\n");
        printf("7 - by first mark\n");
        printf("8 - by second mark\n");
        printf("9 - by third mark\n");
        printf("10 - reverse list\n");
        printf("Enter your choice: ");
        option = safe_scand();
        if((option>=1) && (option<=9))
        {
            do
            {
                printf("Select sorting direction :\n");
                printf("1 - descending\n");
                printf("2 - ascending\n");
                printf("Enter your choice: ");
                way = safe_scand();
            }while((way < 1) || (way > 2));
        }
        if((((option>=1) && (option<=9)) && ((way >= 1) && (way <= 2)))||option==10)
        {
            switch(option)
            {
                case 1:
                    sort_construct(p0,way,compare_id);
                    break;
                case 2:
                    sort_construct(p0,way,compare_name);
                    break;
                case 3:
                    sort_construct(p0,way,compare_subject);
                    break;
                case 4:
                    sort_construct(p0,way,compare_averenge);
                    break;
                case 5:
                    sort_construct(p0,way,compare_age);
                    break;
                case 6:
                    sort_construct(p0,way,compare_minutes);
                    break;
                case 7:
                    sort_construct(p0,way,compare_mark1);
                    break;
                case 8:
                    sort_construct(p0,way,compare_mark2);
                    break;
                case 9:
                    sort_construct(p0,way,compare_mark3);
                    break;
                case 10:
                    _reverse_(p0);
                    break;
            }
        }
    } while(option!=0);
    rebuild_id(p0);
}

void sort_construct(Head *my_head, int n, int (*funcName)(Node *p,int way))
{
    Node *p1 = NULL, *a = NULL,*b = NULL,*c = NULL,*d = NULL;
    int flag=1,i,k=0;
    a = my_head->first;
    b = my_head->last;
    a->prev = b;
    b->next = a;
    while(flag)
    {
        flag=0;
        p1 = my_head->first;
        for(i=0 ;i < my_head->cnt && p1!=my_head->last; i++)
        {
            if(funcName(p1,n))
            {
                a = p1->prev;
                b = p1;
                c = p1->next;
                d = p1->next->next;

                if (b == my_head->first) my_head->first = c;
                if (c == my_head->last) my_head->last = b;

                a->next = c;
                b->next = d;
                c->next = b;

                b->prev = c;
                c->prev = a;
                d->prev = b;
                flag=1;
                k=1;
            }
            if(k)
            {
                k=0;
            }
            else
            {
                p1 = p1->next;
            }
        }
    }
    a = my_head->first;
    b = my_head->last;
    a->prev = NULL;
    b->next = NULL;
}

void _reverse_(Head *my_head)
{
    Node *p = NULL, *a = NULL , *b = NULL;
    p = my_head->first;
    while(p!=NULL)
    {
        a = p->next;
        b = p->prev;
        p->next = b;
        p->prev = a;
        p = a;
    }
    a = my_head->first;
    b = my_head->last;
    my_head->first = b;
    b->prev = NULL;
    my_head->last = a;
    a->next = NULL;
}

int compare_id(Node *p, int way)
{
    if(way==1)
    {
        if(p->id > p->next->id)
            return 1;
        else
            return 0;
    }
    else
    {
        if(p->id < p->next->id)
            return 1;
        else
            return 0;
    }
}

int compare_name(Node *p, int way)
{
    if(way==1)
    {
        if(strcmp(p->name,p->next->name)>0)
            return 1;
        else
            return 0;
    }
    else
    {
        if(strcmp(p->name,p->next->name)<0)
            return 1;
        else
            return 0;
    }
}

int compare_subject(Node *p, int way)
{
    if(way==1)
    {
        if(strcmp(p->subject,p->next->subject)>0)
            return 1;
        else
            return 0;
    }
    else
    {
        if(strcmp(p->subject,p->next->subject)<0)
            return 1;
        else
            return 0;
    }
}

int compare_averenge(Node *p, int way)
{
    if(way==1)
    {
        if(p->averenge > p->next->averenge)
            return 1;
        else
            return 0;
    }
    else
    {
        if(p->averenge < p->next->averenge)
            return 1;
        else
            return 0;
    }
}

int compare_age(Node *p, int way)
{
    if(way==1)
    {
        if(p->age > p->next->age)
            return 1;
        else
            return 0;
    }
    else
    {
        if(p->age < p->next->age)
            return 1;
        else
            return 0;
    }
}

int compare_minutes(Node *p, int way)
{
    if(way==1)
    {
        if(p->minutes > p->next->minutes)
            return 1;
        else
            return 0;
    }
    else
    {
        if(p->minutes < p->next->minutes)
            return 1;
        else
            return 0;
    }
}

int compare_mark1(Node *p,int way)
{
    if(way==1)
    {
        if(p->mark[0] > p->next->mark[0])
            return 1;
        else
            return 0;
    }
    else
    {
        if(p->mark[0] < p->next->mark[0])
            return 1;
        else
            return 0;
    }
}

int compare_mark2(Node *p,int way)
{
    if(way==1)
    {
        if(p->mark[1] > p->next->mark[1])
            return 1;
        else
            return 0;
    }
    else
    {
        if(p->mark[1] < p->next->mark[1])
            return 1;
        else
            return 0;
    }
}

int compare_mark3(Node *p,int way)
{
    if(way==1)
    {
        if(p->mark[2] > p->next->mark[2])
            return 1;
        else
            return 0;
    }
    else
    {
        if(p->mark[2] < p->next->mark[2])
            return 1;
        else
            return 0;
    }
}
