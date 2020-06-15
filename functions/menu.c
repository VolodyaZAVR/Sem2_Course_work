#include "../headers/menu.h"

void MainMenu()
{
    Head *p0 = NULL;
    int choise;
    Head *(*kind[2])();
    kind[0] = GettingFile;
    kind[1] = MenuAddFirst;
    do
    {
        printf("Chose what are you want to do :\n");
        printf("0 - exit from program\n");
        printf("1 - get list from file\n");
        printf("2 - create new node\n");
        printf("3 - print help list\n");
        printf("Enter your choice: ");
        choise = safe_scand();
        if((choise>=0)&&(choise<=3))
        {
            switch(choise)
            {
                case 0:
                    break;
                case 3:
                    PrintHelp();
                    break;
                default:
                    p0 = kind[choise - 1]();
                    if (p0 != NULL)
                    {
                        Menu(p0);
                        if (p0->cnt != 0)
                            FreeNode(p0);
                    }
                    break;
            }
        }
        else
        {
            printf("Wrong number\n");
        }
    }while(choise!=0);
}

Head* GettingFile()
{
    enum {maxlen = 128};
    char file_name[maxlen];
    FILE* df;
    Head *p0;
    int exit = 0, slen;
    cls();
    do
    {
        printf("Enter the name of the file in which the list is stored : ");
        fflush(stdin);
        fgets(file_name,maxlen,stdin);
        slen=strlen(file_name);
        file_name[slen-1]='\0';
        df = fopen(file_name, "r");
        if(df!=NULL)
        {
            exit = 1;
            p0 = MakeNode(df);
            if(fclose(df)==EOF)
            {
                printf("Error closing file.\n");
            }
        }
        else
        {
            printf("File not found!\n");
        }
    }while(exit==0);
    return p0;
}

Head* MenuAddFirst()
{
    Head *p0 = NULL;
    Node *new_node = NULL;
    cls();
    p0 = make_head();
    new_node = add_node();
    add_first(p0,new_node);
    return p0;
}

void PrintHelp()
{
    cls();
    printf("This program is designed to work with a list.\n"
            "At the beginning of the program, you can open an existing list or create it\n\n"
            "In the next menu you can select one of the following functions: \n"
            "add node - add a new node to the existing list\n"
            "edit node - edit the selected node for any field\n"
            "delete node - delete an node from the list (you cannot completely delete the list with this function)\n"
            "swap_node - swap nodes\n"
            "sort node - sort the list by the selected field\n"
            "search at node - search in the list according to the specified parameters (a complex search and further saving of the list is possible)\n"
            "copy node - copy values ​​from one node to another\n"
            "save node - save the list to a file (you can save the list as an existing file or create it yourself)\n\n");
}

Head* MakeNode(FILE *df)
{
    enum{maxlen=128};
    char **s2=NULL;
    char s1[maxlen], sep = ';';
    int slen,i,n;
    Head *p0 = NULL;
    Node *p = NULL,*p1 = NULL;
    p0 = make_head();
    if(p0!=NULL)
    {
        n=0;
        while((fgets(s1,maxlen,df))!=NULL) n++;
        rewind(df);
        for(i=1;i<=n;i++)
        {
            fgets(s1,maxlen,df);
            slen=strlen(s1);
            s1[slen-1]='\0';
            slen=strlen(s1);
            s2=simple_split(s1,slen,sep);
            if(s2!=NULL)
            {
                p = create_node(s2,i);
                if(p==NULL)
                {
                    puts("Structure not allocated!\n");
                    i=n+1;
                }
                else
                {
                    if(i==1)
                    {
                        p0->first = p;
                        p0->cnt++;
                    }
                    else
                    {
                        p1->next = p;
                        p->prev = p1;
                    }
                    p1 = p;
                }
            }
            else
                puts("Error at data reading!\n");
        }
        p0->last = p;
        p0->last->next = NULL;
        p0->first->prev = NULL;
        p0->cnt = p0->last->id;
    }
    return p0;
}

void Menu(Head* p0)
{
    void (*kind[8])(Head *my_head);
    kind[0] = MenuAdd;
    kind[1] = MenuEdit;
    kind[2] = MenuDelete;
    kind[3] = MenuSwap;
    kind[4] = MenuSort;
    kind[5] = MenuSearch;
    kind[6] = MenuCopy;
    kind[7] = SaveNode;
    int choise;
    do
    {
        cls();
        print_list(p0);
        printf("Chose what are you want to do :\n");
        printf("0 - go to exit\n");
        printf("1 - add node\n");
        printf("2 - edit node\n");
        printf("3 - delete node\n");
        printf("4 - swap node\n");
        printf("5 - sort node\n");
        printf("6 - search at node\n");
        printf("7 - copy node\n");
        printf("8 - save node\n");
        printf("Enter your choice: ");
        choise = safe_scand();
        if((choise>=0)&&(choise<=8))
        {
            switch(choise)
            {
                case 0:
                    break;
                default:
                    kind[choise - 1](p0);
                    break;
            }
        }
    } while((choise !=0)&&(p0!=NULL));
}
