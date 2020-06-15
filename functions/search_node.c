#include "../headers/search_node.h"

void MenuSearch(Head *p0)
{
    enum {maxlen = 128};
    int option, option1, option2, option3, slen,count = 0;
    float option4, option5;
    char input[maxlen];
    Head* p1 = NULL;
    do
    {
        if(count == 0)
        {
            cls();
            print_list(p0);
            count++;
        }
        printf("Kinds of search:\n");
        printf("0 - exit from menu\n");
        printf("1 - by name\n");
        printf("2 - by subject\n");
        printf("3 - by averenge\n");
        printf("4 - by age\n");
        printf("5 - by minutes\n");
        printf("6 - by first mark\n");
        printf("7 - by second mark\n");
        printf("8 - by third mark\n");
        printf("9 - by all marks\n");
        printf("Enter your choice: ");
        option = safe_scand();

        if((option>=1) && (option<=9))
        {
            switch(option)
            {
                case 1:
                    printf("Enter the name that you want to search: ");
                    fflush(stdin);
                    fgets(input,maxlen,stdin);
                    slen=strlen(input);
                    input[slen-1]='\0';
                    if(p1 == NULL)
                    {
                        p1 = search_construct2(p0,input,return_name,1);
                    }
                    else
                    {
                        p1 = search_construct2(p1,input,return_name,2);
                    }
                    if(p1==NULL)
                    {
                        printf("Searched list is empty\n");
                        option = 0;
                    }
                    else
                    {
                        cls();
                        printf("Searched list\n");
                        print_list(p1);
                    }
                    break;
                case 2:
                    printf("Enter the subject that you want to search: ");
                    fflush(stdin);
                    fgets(input,maxlen,stdin);
                    slen=strlen(input);
                    input[slen-1]='\0';
                    if(p1 == NULL)
                    {
                        p1 = search_construct2(p0,input,return_subject,1);
                    }
                    else
                    {
                        p1 = search_construct2(p1,input,return_subject,2);
                    }
                    if(p1==NULL)
                    {
                        printf("Searched list is empty\n");
                        option = 0;
                    }
                    else
                    {
                        cls();
                        printf("Searched list\n");
                        print_list(p1);
                    }
                    break;
                case 3:
                    do
                    {
                        printf("Enter two numbers (first number is lower then second)\n");
                        printf("Enter first float number: ");
                        option4 = safe_scanf();
                        printf("Enter second float number: ");
                        option5 = safe_scanf();
                        if(option4 > option5)
                        {
                            option4=-1;
                            option5=-1;
                        }
                    } while(((option4<0)||(option4>100))||((option5<0)||(option5>100)));
                    if(p1 == NULL)
                    {
                        p1 = search_construct3(p0,option4,option5,return_averenge,1);
                    }
                    else
                    {
                        p1 = search_construct3(p1,option4,option5,return_averenge,2);
                    }
                    if(p1==NULL)
                    {
                        printf("Searched list is empty\n");
                        option = 0;
                    }
                    else
                    {
                        cls();
                        printf("Searched list\n");
                        print_list(p1);
                    }
                    break;
                case 4:
                    do
                    {
                        printf("Enter two numbers (first number is lower then second)\n");
                        printf("Enter first number: ");
                        option1 = safe_scand();
                        printf("Enter second number: ");
                        option2 = safe_scand();
                        if(option1>option2)
                        {
                            option1=-1;
                            option2=-1;
                        }
                    } while(((option1<0)||(option1>100))||((option2<0)||(option2>100)));
                    if(p1 == NULL)
                    {
                        p1 = search_construct1(p0,option1,option2,return_age,1);
                    }
                    else
                    {
                        p1 = search_construct1(p1,option1,option2,return_age,2);
                    }
                    if(p1==NULL)
                    {
                        printf("Searched list is empty\n");
                        option = 0;
                    }
                    else
                    {
                        cls();
                        printf("Searched list\n");
                        print_list(p1);
                    }
                    break;
                case 5:
                    do
                    {
                        printf("Enter two numbers (first number is lower then second)\n");
                        printf("Enter first number: ");
                        option1 = safe_scand();
                        printf("Enter second number: ");
                        option2 = safe_scand();
                        if(option1>=option2)
                        {
                            option1=-1;
                            option2=-1;
                        }
                    } while(((option1<0)||(option1>180))||((option2<0)||(option2>180)));
                    if(p1 == NULL)
                    {
                        p1 = search_construct1(p0,option1,option2,return_minutes,1);
                    }
                    else
                    {
                        p1 = search_construct1(p1,option1,option2,return_minutes,2);
                    }
                    if(p1==NULL)
                    {
                        printf("Searched list is empty\n");
                        option = 0;
                    }
                    else
                    {
                        cls();
                        printf("Searched list\n");
                        print_list(p1);
                    }
                    break;
                case 6:
                    do
                    {
                        printf("Enter two numbers (first number is lower then second)\n");
                        printf("Enter first number: ");
                        option1 = safe_scand();
                        printf("Enter second number: ");
                        option2 = safe_scand();
                        if(option1>=option2)
                        {
                            option1=-1;
                            option2=-1;
                        }
                    } while(((option1<0)||(option1>100))||((option2<0)||(option2>100)));
                    if(p1 == NULL)
                    {
                        p1 = search_construct1(p0,option1,option2,return_mark1,1);
                    }
                    else
                    {
                        p1 = search_construct1(p1,option1,option2,return_mark1,2);
                    }
                    if(p1==NULL)
                    {
                        printf("Searched list is empty\n");
                        option = 0;
                    }
                    else
                    {
                        cls();
                        printf("Searched list\n");
                        print_list(p1);
                    }
                    break;
                case 7:
                    do
                    {
                        printf("Enter two numbers (first number is lower then second)\n");
                        printf("Enter first number: ");
                        option1 = safe_scand();
                        printf("Enter second number: ");
                        option2 = safe_scand();
                        if(option1>=option2)
                        {
                            option1=-1;
                            option2=-1;
                        }
                    } while(((option1<0)||(option1>100))||((option2<0)||(option2>100)));
                    if(p1 == NULL)
                    {
                        p1 = search_construct1(p0,option1,option2,return_mark2,1);
                    }
                    else
                    {
                        p1 = search_construct1(p1,option1,option2,return_mark2,2);
                    }
                    if(p1==NULL)
                    {
                        printf("Searched list is empty\n");
                        option = 0;
                    }
                    else
                    {
                        cls();
                        printf("Searched list\n");
                        print_list(p1);
                    }
                    break;
                case 8:
                    do
                    {
                        printf("Enter two numbers (first number is lower then second)\n");
                        printf("Enter first number: ");
                        option1 = safe_scand();
                        printf("Enter second number: ");
                        option2 = safe_scand();
                        if(option1>=option2)
                        {
                            option1=-1;
                            option2=-1;
                        }
                    } while(((option1<0)||(option1>100))||((option2<0)||(option2>100)));
                    if(p1 == NULL)
                    {
                        p1 = search_construct1(p0,option1, option2, return_mark3,1);
                    }
                    else
                    {
                        p1 = search_construct1(p1,option1, option2, return_mark3,2);
                    }
                    if(p1==NULL)
                    {
                        printf("Searched list is empty\n");
                        option = 0;
                    }
                    else
                    {
                        cls();
                        printf("Searched list\n");
                        print_list(p1);
                    }
                    break;
                case 9:
                    do
                    {
                        printf("Enter two numbers (first number is lower then second)\n");
                        printf("Enter first number: ");
                        option1 = safe_scand();
                        printf("Enter second number: ");
                        option2 = safe_scand();
                        if(option1>=option2)
                        {
                            option1=-1;
                            option2=-1;
                        }
                    } while(((option1<0)||(option1>100))||((option2<0)||(option2>100)));
                    if(p1 == NULL)
                    {
                        p1 = search_construct1(p0,option1,option2,return_all_marks,1);
                    }
                    else
                    {
                        p1 = search_construct1(p1,option1,option2,return_all_marks,2);
                    }
                    if(p1==NULL)
                    {
                        printf("Searched list is empty\n");
                        option = 0;
                    }
                    else
                    {
                        cls();
                        printf("Searched list\n");
                        print_list(p1);
                    }
                    break;
            }
        }
    } while(option != 0);
    if(p1!=NULL)
    {
        do
        {
            printf("Do you want to save this list in a separate file?\n");
            printf("0 - NO\n");
            printf("1 - YES\n");
            printf("Enter your choice: ");
            option3 = safe_scand();
        }while((option3<0)||(option3>1));
        if(option3 == 1)
        {
            SaveNode(p1);
        }
        FreeNode2(p1);
    }
}

Head* search_construct1(Head *my_head, int option1, int option2 ,int (*funcName)(Node *p,int option1, int option2), int flag)
{
    Node *p = NULL,*temp = NULL, *p1 = NULL;
    Head *p0 = NULL;
    int i=0;
    if(flag == 1)
    {
        p0 = make_head();
        p = my_head->first;
        while(p!=NULL)
        {
            if(funcName(p,option1,option2))
            {
                temp = clone_node(p);
                if(i==0)
                {
                    p0->first = temp;
                    p0->cnt++;
                }
                else
                {
                    p1->next = temp;
                    temp->prev = p1;
                }
                p1 = temp;
                i++;
            }
            p = p->next;
        }
        if(p0->cnt == 0)
        {
            free(p0);
            p0 = NULL;
        }
        else
        {
            p0->last = p1;
            p0->last->next = NULL;
            p0->first->prev = NULL;
            p0->cnt = i;
        }
    }
    else
    {
        p = my_head->first;
        while((p!=NULL)&&(my_head!=NULL))
        {
            if(!funcName(p,option1,option2))
            {
                my_head = delete_node2(my_head,i+1);
                if(my_head!=NULL)
                {
                    p = my_head->first;
                    i = 0;
                }
            }
            else
            {
                p = p->next;
                i++;
            }
        }
        p0 = my_head;
    }
    return p0;
}

Head* search_construct2(Head *my_head, char str[128] ,int (*funcName)(Node *p, char str[128]), int flag)
{
    Node *p = NULL,*temp = NULL, *p1 = NULL;
    Head *p0 = NULL;
    int i=0;
    if(flag == 1)
    {
        p0 = make_head();
        p = my_head->first;
        while(p!=NULL)
        {
            if(funcName(p,str))
            {
                temp = clone_node(p);
                if(i==0)
                {
                    p0->first = temp;
                    p0->cnt++;
                }
                else
                {
                    p1->next = temp;
                    temp->prev = p1;
                }
                p1 = temp;
                i++;
            }
            p = p->next;
        }
        if(p0->cnt == 0)
        {
            free(p0);
            p0 = NULL;
        }
        else
        {
            p0->last = p1;
            p0->last->next = NULL;
            p0->first->prev = NULL;
            p0->cnt = i;
        }
    }
    else
    {
        p = my_head->first;
        while((p!=NULL)&&(my_head!=NULL))
        {
            if(!funcName(p,str))
            {
                my_head = delete_node2(my_head,i+1);
                if(my_head!=NULL)
                {
                    p = my_head->first;
                    i=0;
                }
            }
            else
            {
                p = p->next;
                i++;
            }
        }
        p0 = my_head;
    }
    return p0;
}

Head* search_construct3(Head *my_head, float option1, float option2 ,int (*funcName)(Node *p,float option1, float option2), int flag)
{
    Node *p = NULL,*temp = NULL, *p1 = NULL;
    Head *p0 = NULL;
    int i=0;
    if(flag == 1)
    {
        p0 = make_head();
        p = my_head->first;
        while(p!=NULL)
        {
            if(funcName(p,option1,option2))
            {
                temp = clone_node(p);
                if(i==0)
                {
                    p0->first = temp;
                    p0->cnt++;
                }
                else
                {
                    p1->next = temp;
                    temp->prev = p1;
                }
                p1 = temp;
                i++;
            }
            p = p->next;
        }
        if(p0->cnt == 0)
        {
            free(p0);
            p0 = NULL;
        }
        else
        {
            p0->last = p1;
            p0->last->next = NULL;
            p0->first->prev = NULL;
            p0->cnt = i;
        }
    }
    else
    {
        p = my_head->first;
        while((p!=NULL)&&(my_head!=NULL))
        {
            if(!funcName(p,option1,option2))
            {
                my_head = delete_node2(my_head,i+1);
                if(my_head!=NULL)
                {
                    p = my_head->first;
                    i = 0;
                }
            }
            else
            {
                p = p->next;
                i++;
            }
        }
        p0 = my_head;
    }
    return p0;
}

int return_name(Node *p, char str[128])
{
    if(strcmp(p->name,str)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int return_subject(Node *p, char str[128])
{
    if(strcmp(p->subject,str)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int return_averenge(Node *p,float option1, float option2)
{
    if((p->averenge >= option1)&&(p->averenge <= option2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int return_age(Node *p,int option1, int option2)
{
    if((p->age >= option1)&&(p->age <= option2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int return_minutes(Node *p,int option1, int option2)
{
    if((p->minutes >= option1) && (p->minutes <= option2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int return_mark1(Node *p,int option1, int option2)
{
    if((p->mark[0] >= option1) && (p->mark[0]<= option2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int return_mark2(Node *p,int option1, int option2)
{
    if((p->mark[1] >= option1) && (p->mark[1]<= option2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int return_mark3(Node *p,int option1, int option2)
{
    if((p->mark[2] >= option1) && (p->mark[2]<= option2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int return_all_marks(Node *p,int option1, int option2)
{
    int count = 0;
    for(int i=0;i<3;i++)
    {
        if((p->mark[i] >= option1)&&(p->mark[i] <= option2))
            count++;
    }
    if(count==3)
        return 1;
    else
        return 0;

}

