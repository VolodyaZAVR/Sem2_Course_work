#include "../headers/save_node.h"

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
        printf("Enter the name of the file in which the list would save: ");
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
            printf("File can't be created!\n");
        }
    }while(exit==0);
}
