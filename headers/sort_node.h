#ifndef SORT_NODE_H_INCLUDED
#define SORT_NODE_H_INCLUDED

#include "io.h"
#include "structure.h"
#include "create_node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void MenuSort(Head *p0);

void sort_construct(Head *my_head, int n, int (*funcName)(Node *p,int way));

void _reverse_(Head *my_head);

int compare_id(Node *p, int way);

int compare_name(Node *p, int way);

int compare_subject(Node *p, int way);

int compare_averenge(Node *p, int way);

int compare_age(Node *p, int way);

int compare_minutes(Node *p, int way);

int compare_mark1(Node *p,int way);

int compare_mark2(Node *p,int way);

int compare_mark3(Node *p,int way);

#endif // SORT_NODE_H_INCLUDED
