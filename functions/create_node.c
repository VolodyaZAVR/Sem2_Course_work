#include "../headers/create_node.h"

Head *make_head()
{
    Head *ph=NULL;
    ph=(Head*)malloc(sizeof(Head));
    if(ph)
    {
        ph->cnt=0;
        ph->first=NULL;
        ph->last=NULL;
    }
    return ph;
}

Node *create_node(char **str, int id)
{
    Node *new_node = NULL;
    new_node = (Node *) malloc(sizeof(Node));
    new_node->id = id;
    new_node->name = str[0];
    new_node->subject = str[1];
    new_node->averenge = atof(str[2]);
    new_node->age = atoi(str[3]);
    new_node->minutes = atoi(str[4]);
    new_node->mark[0] = atoi(str[5]);
    new_node->mark[1] = atoi(str[6]);
    new_node->mark[2] = atoi(str[7]);
    new_node->next = NULL;
    new_node->prev = NULL;
    free(str[2]);
    free(str[3]);
    free(str[4]);
    free(str[5]);
    free(str[6]);
    free(str[7]);
    free(str);
    return new_node;
}

void add_first(Head *my_head, Node *new_node)
{
    my_head->first = new_node;
    my_head->last = new_node;;
    my_head->cnt++;
}

void print_header()
{
    printf("|%3s|%15s |%8s |%5s |%3s |%4s |%4s|%4s|%4s|\n","id","fullname","subject","averenge","age","min","ball 1","ball 2","ball 3");
    printf("+---+----------------+---------+---------+----+-----+------+------+------+\n");
}

void print_list(Head *my_head)
{
    Node *p = my_head -> first;
    print_header();
    while(p!=NULL)
    {
        printf("|%3d|%15s |%8s | %3.2f   |%3d |%4d |%5d |%5d |%5d |\n",
            p->id,p->name,p->subject,p->averenge,p->age,p->minutes,p->mark[0],p->mark[1],p->mark[2]);
        p = p->next;
    }
}

void rebuild_id(Head* p0)
{
    Node *p = p0->first;
    int i=1;
    while(p!=NULL)
    {
        p->id = i;
        p = p->next;
        i++;
    }
}

Node* ssearch(Head* p0, int index)
{
    Node *p = p0 -> first;
    int i = 1;
    while(i < index)
    {
        p = p -> next;
        i++;
    }
    return p;
}

void insert_after(Head *my_head, Node *new_node, Node *current_node)
{
    if (current_node == my_head->last)
    {
        current_node->next = new_node;
        new_node->prev = current_node;
        new_node->next = NULL;
        my_head->last=new_node;
    }
    else
    {
        new_node->next = current_node->next;
        new_node->prev = current_node;
        current_node->next = new_node;
    }
    my_head->cnt++;
}

void insert_before(Head *my_head, Node *new_node, Node *current_node)
{
    if (current_node == my_head->first)
    {
        my_head->first = new_node;
        new_node->next = current_node;
        new_node->prev = NULL;
        current_node->prev = new_node;
    }
    else
    {
        current_node->prev->next = new_node;
        new_node->prev = current_node->prev;
        new_node->next = current_node;
        current_node->prev = new_node;
    }
    my_head->cnt++;
}

void copy_node(Head *p0, int index1, int index2)
{
    Node* p1 = NULL, *p2 = NULL;
    p1 = ssearch(p0,index1);
    p2 = ssearch(p0,index2);
    strcpy(p2->name,p1->name);
    strcpy(p2->subject,p1->subject);
    p2->averenge = p1->averenge;
    p2->age = p1->age;
    p2->minutes=p1->minutes;
    p2->mark[0]=p1->mark[0];
    p2->mark[1]=p1->mark[1];
    p2->mark[2]=p1->mark[2];
}

Node* clone_node(Node* p)
{
    Node *new_node=NULL;
    new_node = (Node*)malloc(sizeof(Node));
    if(new_node)
    {
        new_node->id = p->id;
        new_node->name = p->name;
        new_node->subject = p->subject;
        new_node->averenge=p->averenge;
        new_node->age=p->age;
        new_node->minutes=p->minutes;
        new_node->mark[0]=p->mark[0];
        new_node->mark[1]=p->mark[1];
        new_node->mark[2]=p->mark[2];
        new_node->prev = NULL;
        new_node->next = NULL;
    }
    return new_node;
}

void delete_node(Head *my_head, int index)
{
    Node *p = NULL;
    p = ssearch(my_head,index);
    if(p == my_head->first)
    {
        my_head->first = p->next;
        p->next->prev = NULL;
    }
    else if(p == my_head->last)
    {
        my_head->last = p->prev;
        p->prev->next = NULL;
    }
    else
    {
        p->next->prev = p->prev;
        p->prev->next = p->next;
    }
    free(p->name);
    free(p->subject);
    free(p);
    my_head->cnt -= 1;
}

Head* delete_node2(Head *my_head, int index)
{
    Node *p = NULL;
    if(my_head != NULL)
    {
        if(my_head->cnt>1)
        {
            p = ssearch(my_head,index);
            if(p == my_head->first)
            {
                my_head->first = p->next;
                p->next->prev = NULL;
            }
            else if(p == my_head->last)
            {
                my_head->last = p->prev;
                p->prev->next = NULL;
            }
            else
            {
                p->next->prev = p->prev;
                p->prev->next = p->next;
            }
            free(p);
            my_head->cnt --;
        }
        else if(my_head->cnt ==1)
        {
            p = my_head ->first;
            free(p);
            my_head ->cnt = 0;
            free(my_head);
            return NULL;
        }
        else if(my_head ->cnt ==0)
        {
            free(my_head);
            return NULL;
        }
    }
    return my_head;
}

void FreeNode(Head *p0)
{
    Node *p = NULL;
    Node *p1 = NULL;
    if(p0!=NULL)
    {
        if (p0->cnt!=0)
        {
            p = p0->first;
            while (p != NULL)
            {
                free(p->name);
                free(p->subject);
                p1 = p->next;
                free(p);
                p = p1;
            }
            free(p0);
        }
    }
}

void FreeNode2(Head *p0)
{
    Node *p = NULL;
    Node *p1 = NULL;
    p = p0->first;
    while (p != NULL)
    {
        p1 = p->next;
        free(p);
        p = p1;
    }
    free(p0);
}
