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
    Head *(*kind[3])();
    kind[0] = GettingFile;
    //kind[1] = MenuAddFirst;
    //kind[2] = PrintHelp;
    do
    {
        printf("Chose what are you want to do :\n");
        printf("0 - exit from program\n");
        printf("1 - get list from file\n");
        printf("2 - create new node\n");
        //printf("3 - print help list\n");
        printf("Enter your choice: ");
        choise = safe_scand();
        if((choise>=0)&&(choise<=2))
        {
            switch(choise)
            {
                case 0:
                    break;
                //case 3:
                    //kind[choise - 1]();
                    //break;
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
    //kind[0] = MenuAdd;
    //kind[1] = MenuEdit;
    //kind[2] = MenuDelete;
    //kind[3] = MenuSwap;
    //kind[4] = MenuSort;
    //kind[5] = MenuSearch;
    //kind[6] = MenuCopy;
    kind[7] = SaveNode;
    int choise;
    do
    {
        print_list(p0);
        printf("Chose what are you want to do :\n");
        printf("0 - go to exit\n");
        //printf("1 - sort node\n");
        //printf("2 - search at node\n");
        //printf("3 - delete node\n");
        //printf("4 - swap node\n");
        //printf("5 - edit node\n");
        //printf("6 - add node\n");
        //printf("7 - copy node\n");
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
    Node *p = NULL,*p1 = NULL,*my_node=NULL;
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

Node *create_node(char **str, int id) // инициализация узла
{
    Node *new_node = NULL; // выделяем память под узел и заполняем его и массива строк
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
    return new_node; // возвращаем адрес узла
}

char **simple_split(char *str, int length, char sep)
{ // разделение строки на части
    char **str_array = NULL;
    int i, j, k, m;
    int key;
    for (j = 0, m = 0; j < length; j++) {
        if (str[j] == sep) m++;// считаем кол-во знаков разделителей
    }

    key = 0;
    str_array = (char **) malloc((m + 1) * sizeof(char *));// выделяем память под массив строк
    if (str_array != NULL) {
        for (i = 0; i <= m; i++) {
            str_array[i] = (char *) malloc(length * sizeof(char));
            if (str_array[i] != NULL) key = 1;// проходим по строке ища знак разделитель
            else {
                key = 0;
                i = m;
            }
        }
        if (key) {
            k = 0;
            m = 0;
            for (j = 0; j < length; j++) {// как только знак нашелся , заполняем соответствующее элемент массива строк
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
    return str_array;// возвращаем указатель на массив строк
}

int safe_scand()
{
    enum{maxlen=128};
    char *str = NULL;
    int temp, slen, n = 0, m = 0, res;
    do {
        str = malloc(maxlen* sizeof(char));
        if (str != NULL)
        {
            fflush(stdin);
            n = 0;
            m = 0;
            fgets(str, maxlen, stdin);
            slen = strlen(str);
            for (unsigned int i = 0; i < slen - 1; i++)
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
    } while (n > 0 || m > 1);
    str[strlen(str) - 1] = '\0';
    res = atoi(str);
    free(str);
    return res;
}

void FreeNode(Head *p0)
{// освобождение памяти под список
    Node *p = NULL;
    Node *p1 = NULL;
    if(p0!=NULL)
    {
        if (p0->cnt!=0)
        {
            p = p0->first;
            while (p != NULL)
            {// проходим по списку и освобождаем память пока не дойдем до конца
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
