#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

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

#endif // STRUCTURE_H_INCLUDED
