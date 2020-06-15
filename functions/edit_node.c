#include "../headers/edit_node.h"

void MenuEdit(Head* p0)
{
    int option, index;
    do
    {
        cls();
        print_list(p0);
        printf("Select id that you want to edit:\n");
        printf("0 - exit from menu\n");
        printf("Enter your choice: ");
        index = safe_scand();
        if(index!=0&&((index>=1)&&(index<=p0->cnt)))
        {
            do
            {
                cls();
                print_list(p0);
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
                }
            }while(option!=0);
        }
    }while(index!=0);
}

void edit_cart(Head* p0, int index, int option)
{
    char *str;
    Node *p1 = NULL;
    float option1;
    int option2;
    p1 = ssearch(p0,index);
    switch(option)
    {
        case 1:
            printf("Enter new name: ");
            str = safe_scans();
            strcpy(p1->name,str);
            free(str);
            break;
        case 2:
            printf("Enter new subject: ");
            str = safe_scans();
            strcpy(p1->subject,str);
            free(str);
            break;
        case 3:
            do
            {
                printf("Enter new averenge: ");
                option1 = safe_scanf();
            }while((option1<0)||(option1>100));
            p1->averenge = option1;
            break;
        case 4:
            do
            {
                printf("Enter new age: ");
                option2 = safe_scand();
            }while((option2<0)||(option2>100));
            p1->age = option2;
            break;
        case 5:
            do
            {
                printf("Enter new minutes: ");
                option2 = safe_scand();
            }while((option2<0)||(option2>180));
            p1->minutes = option2;
            break;
        case 6:
            do
            {
                printf("Enter new first mark:");
                option2 = safe_scand();
            }while((option2<0)||(option2>100));
            p1->mark[0] = option2;
            break;
        case 7:
            do
            {
                printf("Enter new second mark: ");
                option2 = safe_scand();
            }while((option2<0)||(option2>100));
            p1->mark[1] = option2;
            break;
        case 8:
            do
            {
                printf("Enter new third mark: ");
                option2 = safe_scand();
            }while((option2<0)||(option2>100));
            p1->mark[2] = option2;
            break;
    }
}
