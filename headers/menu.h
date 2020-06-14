#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "io.h"
#include "structure.h"
#include "create_node.h"
#include "add_node.h"
#include "edit_node.h"
#include "delete_node.h"
#include "swap_node.h"
#include "sort_node.h"
#include "search_node.h"
#include "copy_node.h"
#include "save_node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void MainMenu();

Head* GettingFile();

Head* MenuAddFirst();

void PrintHelp();

Head* MakeNode(FILE *df);

void Menu(Head* p0);

#endif // MENU_H_INCLUDED
