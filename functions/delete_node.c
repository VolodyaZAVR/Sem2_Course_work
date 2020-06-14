#include "../headers/delete_node.h"

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
