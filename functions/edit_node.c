#include "../headers/edit_node.h"

void MenuEdit(Head* p0)
{
    int option, index;
    do
    {
        print_list(p0);
        printf("Select id that you want to edit:\n");
        printf("0 - exit from menu\n");
        printf("Enter your choice: ");
        index = safe_scand();
        if(index!=0&&((index>=1)&&(index<=p0->cnt)))
        {
            do
            {
                printf("Kinds of edit:\n");
                printf("0 - exit from menu\n");
                printf("1 - by name\n");
                printf("2 - by subject\n");
                printf("3 - by averenge\n");
                printf("4 - by age\n");
                printf("5 - by minutes\n");
                printf("6 - by first mark\n");
                printf("7 - by second mark\n");
                printf("8 - by third mark\n");
                printf("Enter your choice: ");
                option = safe_scand();
                if(option!=0&&((option>=1)&&(option<=8)))
                {
                    edit_cart(p0,index,option);
                    print_list(p0);
                }
            }while(option!=0);
        }
    }while(index!=0);
}

void edit_cart(Head* p0, int index, int option)
{
    enum {maxlen = 128};
    char str[maxlen];
    Node *p1 = NULL;
    float option1;
    int option2, slen;
    p1 = ssearch(p0,index);
    switch(option)
    {
        case 1:
            printf("Enter new name\n");
            fflush(stdin);
            fgets(str,maxlen,stdin);
            slen=strlen(str);
            str[slen-1]='\0';
            strcpy(p1->name,str);
            break;
        case 2:
            printf("Enter new subject\n");
            fflush(stdin);
            fgets(str,maxlen,stdin);
            slen=strlen(str);
            str[slen-1]='\0';
            strcpy(p1->subject,str);
            break;
        case 3:
            printf("Enter new averenge\n");
            option1 = safe_scanf();
            p1->averenge = option1;
            break;
        case 4:
            printf("Enter new age\n");
            option2 = safe_scand();
            p1->age = option2;
            break;
        case 5:
            printf("Enter new minutes\n");
            option2 = safe_scand();
            p1->minutes = option2;
            break;
        case 6:
            printf("Enter new first mark\n");
            option2 = safe_scand();;
            p1->mark[0] = option2;
            break;
        case 7:
            printf("Enter new second mark\n");
            option2 = safe_scand();
            p1->mark[1] = option2;
            break;
        case 8:
            printf("Enter new third mark\n");
            option2 = safe_scand();
            p1->mark[2] = option2;
            break;
    }
}
