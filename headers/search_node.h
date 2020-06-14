#ifndef SEARCH_NODE_H_INCLUDED
#define SEARCH_NODE_H_INCLUDED

#include "io.h"
#include "structure.h"
#include "create_node.h"
#include "save_node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void MenuSearch(Head *p0);

Head* search_construct1(Head *my_head, int option1, int option2 ,int (*funcName)(Node *p,int option1, int option2), int flag);

Head* search_construct2(Head *my_head, char str[128] ,int (*funcName)(Node *p, char str[128]), int flag);

int return_name(Node *p, char str[128]);

int return_subject(Node *p, char str[128]);

int return_averenge(Node *p,int option1, int option2);

int return_age(Node *p,int option1, int option2);

int return_minutes(Node *p,int option1, int option2);

int return_mark1(Node *p,int option1, int option2);

int return_mark2(Node *p,int option1, int option2);

int return_mark3(Node *p,int option1, int option2);

int return_all_marks(Node *p,int option1, int option2);

#endif // SEARCH_NODE_H_INCLUDED
