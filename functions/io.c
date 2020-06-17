#include "../headers/io.h"

void cls()
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

char **simple_split(char *str, int length, char sep)
{
    char **str_array = NULL;
    int i, j, k, m;
    int key;
    for (j = 0, m = 0; j < length; j++) {
        if (str[j] == sep) m++;
    }

    key = 0;
    str_array = (char **) malloc((m + 1) * sizeof(char *));
    if (str_array != NULL) {
        for (i = 0; i <= m; i++) {
            str_array[i] = (char *) malloc(length * sizeof(char));
            if (str_array[i] != NULL) key = 1;
            else {
                key = 0;
                i = m;
            }
        }
        if (key) {
            k = 0;
            m = 0;
            for (j = 0; j < length; j++) {
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
    return str_array;
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
    }
    else
    str[strlen(str) - 1] = '\0';
    res = atof(str);
    free(str);
    return res;
}

char *safe_scans()
{
    enum {maxlen = 128};
    char *str = NULL;
    int temp, slen , n=0;
    do
    {
        str = malloc(maxlen * sizeof(char));
        if (str != NULL)
        {
            fflush(stdin);
            n = 0;
            fgets(str, maxlen, stdin);
            slen = strlen(str);
            for (int i = 0; i < slen; i++)
            {
                temp = str[i];
                if (temp >= 48 && temp <= 57)
                    n++;
            }
            if (str[0] == ' ')
                n++;
            if (str[strlen(str) - 2] == ' ')
                n++;
            if (n > 0)
            {
                free(str);
                printf("Incorrect string\n");
                printf("Your string:");
            }
        }
    } while (n > 0);
    str[strlen(str) - 1] = '\0';
    return (str);
}

