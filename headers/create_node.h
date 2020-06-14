#ifndef CREATE_NODE_H_INCLUDED
#define CREATE_NODE_H_INCLUDED

#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

Head *make_head();

Node *create_node(char **str, int id);

void add_first(Head *my_head, Node *new_node);

void print_header();

void print_list(Head *my_head);

void rebuild_id(Head* p0);

Node* ssearch(Head* p0, int index);

void insert_after(Head *head, Node *new_node, Node *current_node);

void insert_before(Head *head, Node *new_node, Node *current_node);

void copy_node(Head *p0, int index1, int index2);

Node* clone_node(Node* p);

void delete_node(Head *my_head, int index);

Head* delete_node2(Head *my_head, int index);

void FreeNode(Head *p0);

void FreeNode2(Head *p0);

#endif // CREATE_NODE_H_INCLUDED
