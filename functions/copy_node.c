#include "../headers/copy_node.h"

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
