#include "../headers/add_node.h"

void MenuAdd(Head* p0)
{
    Node *new_node = NULL, *p1 = NULL;
    int index, choise;
    do
    {
        print_list(p0);
        printf("You want to insert after or before?\n");
        printf("0 - exit from menu\n");
        printf("1 - add before node\n");
        printf("2 - add after node\n");
        printf("Enter your choice: ");
        choise = safe_scand();
        if((choise >= 1) && (choise <= 2))
        {
            if(choise == 1)
            {
                do
                {
                    print_list(p0);
                    printf("Select id that you want to insert before:\n");
                    printf("0 - exit from menu\n");
                    printf("Enter your choice: ");
                    index = safe_scand();
                    if((index >= 1) && (index <= p0->cnt))
                    {
                        p1 = ssearch(p0,index);
                        new_node = add_node();
                        insert_before(p0,new_node,p1);
                        rebuild_id(p0);
                    }
                }while(index!=0);
            }
            else
            {
                do
                {
                    print_list(p0);
                    printf("Select id that you want to insert after:\n");
                    printf("0 - exit from menu\n");
                    printf("Enter your choice: ");
                    index = safe_scand();
                    if((index >= 1) && (index <= p0->cnt))
                    {
                        p1 = ssearch(p0,index);
                        new_node = add_node();
                        insert_after(p0,new_node,p1);
                        rebuild_id(p0);
                    }
                }while(index!=0);
            }
        }

    }while(choise!=0);
}

Node* add_node()
{
    enum {maxlen = 80};
    char str[maxlen];
    float option1;
    int option2 , slen;
    Node *new_node=NULL;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->name = (char*)malloc(maxlen*sizeof(char));
    new_node->subject = (char*)malloc(maxlen*sizeof(char));
    printf("Enter name\n");
    fflush(stdin);
    fgets(str,maxlen,stdin);
    slen=strlen(str);
    str[slen-1]='\0';
    strcpy(new_node->name,str);
    printf("Enter subject\n");
    fflush(stdin);
    fgets(str,maxlen,stdin);
    slen=strlen(str);
    str[slen-1]='\0';
    strcpy(new_node->subject,str);
    printf("Enter age\n");
    option2 = safe_scand();
    new_node->age = option2;
    printf("Enter minutes\n");
    option2 = safe_scand();
    new_node->minutes = option2;
    printf("Enter first mark\n");
    option2 = safe_scand();
    new_node->mark[0] = option2;
    printf("Enter second mark\n");
    option2 = safe_scand();
    new_node->mark[1] = option2;
    printf("Enter third mark\n");
    option2 = safe_scand();
    new_node->mark[2] = option2;
    option1 = (new_node->mark[0]+new_node->mark[1]+new_node->mark[2])/3.;
    new_node->averenge = option1;
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->id = 1;
    return new_node;
}
