#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LNode
{
    int   id; /* unique value */
    char *name;
    char *subject;
    float averenge;
    int age;
    int minutes;
    int mark[3];
    struct LNode *prev; /* link to previous node */
    struct LNode *next; /* link to next node */
};

struct LHead {
    int cnt;
    struct LNode *first;
    struct LNode *last;
};

typedef struct LHead Head;
typedef struct LNode Node;

void MainMenu();

void Menu(Head* p0);

Head* GettingFile();

Head* MakeNode(FILE *df);

Head *make_head();

Node *create_node(char **str, int id);

char **simple_split(char *str, int length, char sep) ;

int safe_scand();

void FreeNode(Head *p0);

void SaveNode(Head* p0);

void print_header();

void print_list(Head *my_head);

void MenuCopy(Head *p0);

Node* ssearch(Head* p0, int index);

void copy_node(Head *p0, int index1, int index2);

void rebuild_id(Head* p0);

void MenuDelete(Head *p0);

void delete_node(Head *my_head, int index);

void edit_cart(Head* p0, int index, int option);

void MenuEdit(Head* p0);

float safe_scanf();

void MenuSort(Head *p0);

void _reverse_(Head *my_head);

void sort_construct(Head *my_head, int n, int (*funcName)(Node *p,int way));

int compare_id(Node *p, int way);

int compare_name(Node *p, int way);

int compare_subject(Node *p, int way);

int compare_averenge(Node *p, int way);

int compare_age(Node *p, int way);

int compare_minutes(Node *p, int way);

int compare_mark1(Node *p,int way);

int compare_mark2(Node *p,int way);

int compare_mark3(Node *p,int way);

void MenuSwap(Head* p0);

void swap_elem(Head* p0,int index1,int index2);

void insert_after(Head *head, Node *new_node, Node *current_node);

void insert_before(Head *head, Node *new_node, Node *current_node);

Node* add_node();

void MenuAdd(Head* p0);

int return_name(Node *p, char str[128]);

int return_subject(Node *p, char str[128]);

int return_averenge(Node *p,int option1, int option2);

int return_age(Node *p,int option1, int option2);

int return_minutes(Node *p,int option1, int option2);

int return_mark1(Node *p,int option1, int option2);

int return_mark2(Node *p,int option1, int option2);

int return_mark3(Node *p,int option1, int option2);

int return_all_marks(Node *p,int option1, int option2);

Node* clone_node(Node* p);

Head* search_construct1(Head *my_head, int option1, int option2 ,int (*funcName)(Node *p,int option1, int option2), int flag);

Head* search_construct2(Head *my_head, char str[128] ,int (*funcName)(Node *p, char str[128]), int flag);

Head* delete_node2(Head *my_head, int index);

void MenuSearch(Head *p0);

void add_first(Head *my_head, Node *new_node);

Head* MenuAddFirst();

void PrintHelp();

int main()
{
    MainMenu();
    printf("goodbye\n");
    getchar();
    getchar();
    return 0;
}

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
            printf("\nWrong number, try again\n\n");
        }
    }while(choise!=0);
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

Head* GettingFile()
{
    enum {maxlen = 128};
    char file_name[maxlen];
    FILE* df;
    Head *p0;
    int exit = 0, slen;
    do
    {
        printf("Enter the name of the file in which the list is stored :\n");
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
                    puts("Structure not allocated!");
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
                puts("Error at data reading!");
        }
        p0->last = p;
        p0->last->next = NULL;
        p0->first->prev = NULL;
        p0->cnt = p0->last->id;
    }
    return p0;
}

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

Node *create_node(char **str, int id) // ������������� ����
{
    Node *new_node = NULL; // �������� ������ ��� ���� � ��������� ��� � ������� �����
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
    return new_node; // ���������� ����� ����
}

char **simple_split(char *str, int length, char sep)
{ // ���������� ������ �� �����
    char **str_array = NULL;
    int i, j, k, m;
    int key;
    for (j = 0, m = 0; j < length; j++) {
        if (str[j] == sep) m++;// ������� ���-�� ������ ������������
    }

    key = 0;
    str_array = (char **) malloc((m + 1) * sizeof(char *));// �������� ������ ��� ������ �����
    if (str_array != NULL) {
        for (i = 0; i <= m; i++) {
            str_array[i] = (char *) malloc(length * sizeof(char));
            if (str_array[i] != NULL) key = 1;// �������� �� ������ ��� ���� �����������
            else {
                key = 0;
                i = m;
            }
        }
        if (key) {
            k = 0;
            m = 0;
            for (j = 0; j < length; j++) {// ��� ������ ���� ������� , ��������� ��������������� ������� ������� �����
                if (str[j] != sep) str_array[m][j - k] = str[j];
                else {
                    str_array[m][j - k] = '\0';
                    k = j + 1;
                    m++;
                }
            }

        }
    }
    str_array[m][j - k] = '\0';
    return str_array;// ���������� ��������� �� ������ �����
}

int safe_scand()
{
    enum{maxlen=128};
    char *str = NULL;
    int temp, slen, n = 0, res;
    do {
        str = (char*)malloc(maxlen* sizeof(char));
        if (str != NULL)
        {
            fflush(stdin);
            n = 0;
            fgets(str, maxlen, stdin);
            slen = strlen(str);
            for (int i = 0; i < slen - 1; i++)
            {
                temp = str[i];
                if (temp < 48 || temp > 57)n++;
            }
            if (n > 0)
            {
                printf("Incorrect number, try again\n");
                free(str);
                printf("Enter number:");
            }
        }
    } while (n > 0);
    str[strlen(str) - 1] = '\0';
    res = atoi(str);
    free(str);
    return res;
}

void FreeNode(Head *p0)
{// ������������ ������ ��� ������
    Node *p = NULL;
    Node *p1 = NULL;
    if(p0!=NULL)
    {
        if (p0->cnt!=0)
        {
            p = p0->first;
            while (p != NULL)
            {// �������� �� ������ � ����������� ������ ���� �� ������ �� �����
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

void SaveNode(Head* p0)
{
    enum {maxlen = 128};
    Node *p = p0->first;
    FILE* df;
    char file_name[maxlen], buff[maxlen];
    char sep = ';', gonext = '\n';
    int slen, exit;
    do
    {
        printf("Enter the name of the file in which the list would save :\n");
        fflush(stdin);
        fgets(file_name,maxlen,stdin);
        slen=strlen(file_name);
        file_name[slen-1]='\0';
        df = fopen(file_name, "w");
        if(df!=NULL)
        {
            exit = 1;
            for(int i = 0; i < p0->cnt; i++)
            {
                fputs(p->name, df);
                fputc(sep,df);
                fputs(p->subject, df);
                fputc(sep,df);
                sprintf(buff,"%.2f",p->averenge);
                fputs(buff, df);
                fputc(sep,df);
                sprintf(buff,"%d",p->age);
                fputs(buff, df);
                fputc(sep,df);
                sprintf(buff,"%d",p->minutes);
                fputs(buff, df);
                fputc(sep,df);
                sprintf(buff,"%d",p->mark[0]);
                fputs(buff, df);
                fputc(sep,df);
                sprintf(buff,"%d",p->mark[1]);
                fputs(buff, df);
                fputc(sep,df);
                sprintf(buff,"%d",p->mark[2]);
                fputs(buff, df);
                fputc(gonext,df);
                p = p->next;
            }
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
        printf("|%3d|%15s |%8s |%3.2f    |%3d |%4d |%5d |%5d |%5d |\n",
            p->id,p->name,p->subject,p->averenge,p->age,p->minutes,p->mark[0],p->mark[1],p->mark[2]);
        p = p->next;
    }
}

void MenuCopy(Head *p0)
{
    int index1, index2;
    do
    {
        print_list(p0);
        printf("Select id's that you want to copy:\n");
        printf("0 - exit from menu\n");
        printf("Enter first id: ");
        index1 = safe_scand();
        if(index1!=0)
        {
            printf("Enter second id: ");
            index2 = safe_scand();
            if ((index2!=0) && (index1!=index2)&&((index1>=1)&&(index1<=p0->cnt))&&((index2>=1)&&(index2<=p0->cnt)))
            {
                copy_node(p0,index1,index2);
            }
        }
    }while(index1!=0);
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

void swap_elem(Head* p0,int index1,int index2)
{
    Node *p1 = NULL, *p2 = NULL, *a = NULL, *b = NULL, *c = NULL , *d = NULL;
    p1 = ssearch(p0,index1);
    p2 = ssearch(p0,index2);
    a = p0->first;
    b = p0->last;
    a->prev = b;
    b->next = a;
    if(p1->next == p2)
    {
        a = p1->prev;
        b = p2->next;
        if (p1 == p0->first)
            p0->first = p2;
        if (p2 == p0->last)
            p0->last = p1;
        a->next = p2;
        b->prev = p1;
        p2->prev = a;
        p2->next = p1;
        p1->prev = p2;
        p1->next = b;
    }
    else if (p1->prev == p2)
    {
        a = p1->next;
        b = p2->prev;
        p0->first = p2;
        p0->last = p1;
        a->prev = p2;
        b->next = p1;
        p2->next = a;
        p2->prev = p1;
        p1->next = p2;
        p1->prev = b;
    }
    else
    {
        a = p1->prev;
        b = p1->next;
        c = p2->prev;
        d = p2->next;
        if (p1 == p0->first)
            p0->first = p2;
        if (p2 == p0->last)
            p0->last = p1;
        a->next = p2;
        b->prev = p2;
        p2->prev = a;
        p2->next = b;
        c->next = p1;
        d->prev = p1;
        p1->prev = c;
        p1->next = d;
    }
    a = p0->first;
    b = p0->last;
    a->prev = NULL;
    b->next = NULL;
}

void MenuSwap(Head* p0)
{
    int index1, index2;
    do
    {
        print_list(p0);
        printf("Select id's that you want to swipe (first index is lower then second):\n");
        printf("0 - exit from menu\n");
        printf("Enter first id: ");
        index1 = safe_scand();
        if(index1!=0)
        {
            printf("Enter second id: ");
            index2 = safe_scand();
            if ((index1 < index2)&&(((index1>=1)&&(index1<=p0->cnt))&&((index2>=1)&&(index2<=p0->cnt))))
            {
                swap_elem(p0,index1,index2);
                rebuild_id(p0);
            }
        }
    }while(index1!=0);
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

void MenuDelete(Head *p0)
{
    int index;
    if(p0->cnt>1)
    {
        do
        {
            print_list(p0);
            printf("Select id that you want to delete:\n");
            printf("0 - exit from menu\n");
            printf("Enter your choice: ");
            index = safe_scand();
            if(index!=0&&((index>=1)&&(index<=p0->cnt)))
            {
                delete_node(p0,index);
            }
            rebuild_id(p0);
        }while((index!=0)&&(p0->cnt!=1));
    }
}

void delete_node(Head *my_head, int index)
{
    Node *p = my_head -> first;
    int i = 1;
    while(i < index)
    {
        p = p -> next;
        i++;
    }
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

float safe_scanf()
{
    enum{maxlen=128};
    char *str = NULL, *search = NULL;
    int temp, slen, n = 0, m = 0;
    float res;
    do {
        str = (char*)malloc(maxlen* sizeof(char));
        if (str != NULL)
        {
            fflush(stdin);
            n = 0;
            m = 0;
            fgets(str, maxlen, stdin);
            slen = strlen(str);
            for (int i = 0; i < slen - 1; i++) {
            temp = str[i];
            if (temp < 48 || temp > 57)n++;
            if (str[i] == '.')m++;
            }
            if (str[0] == '.')m++;
            n = n - m;
            if (n > 0 || m > 1)
            {
                printf("Incorrect float number, try again\n");
                free(str);
                printf("Enter float number:");
            }
        }
    } while (n > 0 || m > 1);
    if (m == 1)
    {
        search = strchr(str, '.');
        str[search - str + 3] = '\0';
        free(search);
    }
    else
    str[strlen(str) - 1] = '\0';
    res = atof(str);
    free(str);
    return res;
}

void MenuSort(Head *p0)
{
    int option, way;
    do
    {
        print_list(p0);
        printf("Kinds of sort:\n");
        printf("0 - exit from menu (id's will replace)\n");
        printf("1 - by id\n");
        printf("2 - by name\n");
        printf("3 - by subject\n");
        printf("4 - by averenge\n");
        printf("5 - by age\n");
        printf("6 - by minutes\n");
        printf("7 - by first mark\n");
        printf("8 - by second mark\n");
        printf("9 - by third mark\n");
        printf("10 - reverse list\n");
        printf("Enter your choice: ");
        option = safe_scand();
        if((option>=1) && (option<=9))
        {
            do
            {
                printf("Select sorting direction :\n");
                printf("1 - descending\n");
                printf("2 - ascending\n");
                printf("Enter your choice: ");
                way = safe_scand();
            }while((way < 1) || (way > 2));
        }
        if((((option>=1) && (option<=9)) && ((way >= 1) && (way <= 2)))||option==10)
        {
            switch(option)
            {
                case 1:
                    sort_construct(p0,way,compare_id);
                    break;
                case 2:
                    sort_construct(p0,way,compare_name);
                    break;
                case 3:
                    sort_construct(p0,way,compare_subject);
                    break;
                case 4:
                    sort_construct(p0,way,compare_averenge);
                    break;
                case 5:
                    sort_construct(p0,way,compare_age);
                    break;
                case 6:
                    sort_construct(p0,way,compare_minutes);
                    break;
                case 7:
                    sort_construct(p0,way,compare_mark1);
                    break;
                case 8:
                    sort_construct(p0,way,compare_mark2);
                    break;
                case 9:
                    sort_construct(p0,way,compare_mark3);
                    break;
                case 10:
                    _reverse_(p0);
                    break;
            }
        }
    } while(option!=0);
    rebuild_id(p0);
}

void _reverse_(Head *my_head)
{
    Node *p = NULL, *a = NULL , *b = NULL;
    p = my_head->first;
    while(p!=NULL)
    {
        a = p->next;
        b = p->prev;
        p->next = b;
        p->prev = a;
        p = a;
    }
    a = my_head->first;
    b = my_head->last;
    my_head->first = b;
    b->prev = NULL;
    my_head->last = a;
    a->next = NULL;
}

void sort_construct(Head *my_head, int n, int (*funcName)(Node *p,int way))
{
    Node *p1 = NULL, *a = NULL,*b = NULL,*c = NULL,*d = NULL;
    int flag=1,i,k=0;
    a = my_head->first;
    b = my_head->last;
    a->prev = b;
    b->next = a;
    while(flag)
    {
        flag=0;
        p1 = my_head->first;
        for(i=0 ;i < my_head->cnt && p1!=my_head->last; i++)
        {
            if(funcName(p1,n))
            {
                a = p1->prev;
                b = p1;
                c = p1->next;
                d = p1->next->next;

                if (b == my_head->first) my_head->first = c;
                if (c == my_head->last) my_head->last = b;

                a->next = c;
                b->next = d;
                c->next = b;

                b->prev = c;
                c->prev = a;
                d->prev = b;
                flag=1;
                k=1;
            }
            if(k)
            {
                k=0;
            }
            else
            {
                p1 = p1->next;
            }
        }
    }
    a = my_head->first;
    b = my_head->last;
    a->prev = NULL;
    b->next = NULL;
}

int compare_id(Node *p, int way)
{
    if(way==1)
    {
        if(p->id > p->next->id)
            return 1;
        else
            return 0;
    }
    else
    {
        if(p->id < p->next->id)
            return 1;
        else
            return 0;
    }
}

int compare_name(Node *p, int way)
{
    if(way==1)
    {
        if(strcmp(p->name,p->next->name)>0)
            return 1;
        else
            return 0;
    }
    else
    {
        if(strcmp(p->name,p->next->name)<0)
            return 1;
        else
            return 0;
    }
}

int compare_subject(Node *p, int way)
{
    if(way==1)
    {
        if(strcmp(p->subject,p->next->subject)>0)
            return 1;
        else
            return 0;
    }
    else
    {
        if(strcmp(p->subject,p->next->subject)<0)
            return 1;
        else
            return 0;
    }
}

int compare_averenge(Node *p, int way)
{
    if(way==1)
    {
        if(p->averenge > p->next->averenge)
            return 1;
        else
            return 0;
    }
    else
    {
        if(p->averenge < p->next->averenge)
            return 1;
        else
            return 0;
    }
}

int compare_age(Node *p, int way)
{
    if(way==1)
    {
        if(p->age > p->next->age)
            return 1;
        else
            return 0;
    }
    else
    {
        if(p->age < p->next->age)
            return 1;
        else
            return 0;
    }
}

int compare_minutes(Node *p, int way)
{
    if(way==1)
    {
        if(p->minutes > p->next->minutes)
            return 1;
        else
            return 0;
    }
    else
    {
        if(p->minutes < p->next->minutes)
            return 1;
        else
            return 0;
    }
}

int compare_mark1(Node *p,int way)
{
    if(way==1)
    {
        if(p->mark[0] > p->next->mark[0])
            return 1;
        else
            return 0;
    }
    else
    {
        if(p->mark[0] < p->next->mark[0])
            return 1;
        else
            return 0;
    }
}

int compare_mark2(Node *p,int way)
{
    if(way==1)
    {
        if(p->mark[1] > p->next->mark[1])
            return 1;
        else
            return 0;
    }
    else
    {
        if(p->mark[1] < p->next->mark[1])
            return 1;
        else
            return 0;
    }
}

int compare_mark3(Node *p,int way)
{
    if(way==1)
    {
        if(p->mark[2] > p->next->mark[2])
            return 1;
        else
            return 0;
    }
    else
    {
        if(p->mark[2] < p->next->mark[2])
            return 1;
        else
            return 0;
    }
}

void insert_after(Head *head, Node *new_node, Node *current_node) {// ������� ���� ����� ��������
    if (current_node == head->last) {
        current_node->next = new_node;
        new_node->prev = current_node;
        new_node->next = NULL;
        head->last=new_node;

    } else {
        new_node->next = current_node->next;
        new_node->prev = current_node;
        current_node->next = new_node;
    }
    head->cnt++;


}


void insert_before(Head *head, Node *new_node, Node *current_node) {// ������� ���� ����� ������������ ���������
    // ��������� ��������� �� ��������� � ���������� ����� �����
    if (current_node == head->first)// ���� ��� ����� ������ ������� ��������� ������ ������
    {
        head->first = new_node;
        new_node->next = current_node;
        new_node->prev = NULL;
        current_node->prev = new_node;
    } else {
        current_node->prev->next = new_node;
        new_node->prev = current_node->prev;
        new_node->next = current_node;
        current_node->prev = new_node;
    }
    head->cnt++;


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

int return_averenge(Node *p,int option1, int option2)
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

Node* clone_node(Node* p)
{
    enum{maxlen = 128};
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

void MenuSearch(Head *p0)
{
    enum {maxlen = 128};
    int option, option1, option2, option3, slen,count = 0;
    char input[maxlen];
    Head* p1 = NULL;
    do
    {
        if(count == 0)
        {
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
                    printf("Enter the name that you want to search:\n");
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
                        printf("Searched list\n");
                        print_list(p1);
                    }
                    break;
                case 2:
                    printf("Enter the subject that you want to search:\n");
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
                        printf("Searched list\n");
                        print_list(p1);
                    }
                    break;
                case 3:
                    do
                    {
                        printf("Enter two numbers : ");
                        option1 = safe_scand();
                        option2 = safe_scand();
                        if(option1>option2)
                        {
                            option1=-1;
                            option2=-1;
                        }
                    } while(((option1<0)||(option1>100))||((option2<0)||(option2>100)));
                    if(p1 == NULL)
                    {
                        p1 = search_construct1(p0,option1,option2,return_averenge,1);
                    }
                    else
                    {
                        p1 = search_construct1(p1,option1,option2,return_averenge,2);
                    }
                    if(p1==NULL)
                    {
                        printf("Searched list is empty\n");
                        option = 0;
                    }
                    else
                    {
                        printf("Searched list\n");
                        print_list(p1);
                    }
                    break;
                case 4:
                    do
                    {
                        printf("Enter two numbers : \n");
                        option1 = safe_scand();
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
                        printf("Searched list\n");
                        print_list(p1);
                    }
                    break;
                case 5:
                    do
                    {
                        printf("Enter two numbers : ");
                        option1 = safe_scand();
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
                        printf("Searched list\n");
                        print_list(p1);
                    }
                    break;
                case 6:
                    do
                    {
                        printf("Enter two numbers : \n");
                        option1 = safe_scand();
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
                        printf("Searched list\n");
                        print_list(p1);
                    }
                    break;
                case 7:
                    do
                    {
                        printf("Enter two numbers : \n");
                        option1 = safe_scand();
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
                        printf("Searched list\n");
                        print_list(p1);
                    }
                    break;
                case 8:
                    do
                    {
                        printf("Enter two numbers : \n");
                        option1 = safe_scand();
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
                        printf("Searched list\n");
                        print_list(p1);
                    }
                    break;
                case 9:
                    do
                    {
                        printf("Enter two numbers : \n");
                        option1 = safe_scand();
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
            printf("1 - YES\n");
            printf("2 - NO\n");
            option3 = safe_scand();
        }while((option3<1)||(option3>2));
        if(option3 == 1)
        {
            SaveNode(p1);
        }
        free(p1);
    }
}

Head* delete_node2(Head *my_head, int index)
{
    Node *p = NULL;
    int i = 1;
    if(my_head != NULL)
    {
        p = my_head->first;
        if(my_head->cnt>1)
        {
            while(i < index)
            {
                p = p -> next;
                    i++;
            }
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
            my_head->cnt -= 1;
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

void add_first(Head *my_head, Node *new_node)
{
    my_head->first = new_node;
    my_head->last = new_node;;
    my_head->cnt++;
}

Head* MenuAddFirst()
{
    Head *p0 = NULL;
    Node *new_node = NULL;
    p0 = make_head();
    new_node = add_node();
    add_first(p0,new_node);
    return p0;
}

void PrintHelp()
{
    printf("\nTry me bitch\n\n");
}
