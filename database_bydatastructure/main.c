#include <stdio.h>
#include <stdlib.h>
#include "linked_list_function.h"
node *ptr='\0';
int main()
{
    unsigned int option,ed_num;
    char name[50];
    int id;
    double cash;
    char type[10];


while(1)
{
    printf("\t\tHello\n\nplease select one of the following option\n");
    printf("1-create a new customer.\n2-edit customer.\n3-delete customer.\n4-print customer.\n5-print list.\n6-exit.\n=");
    scanf("%i",&option);
    switch(option)
    {
    case 1:
        printf("Enter the name:");
        scanf(" %[^\n]", name);
        printf("Enter the cash:");
        scanf("%lf",&cash);
        printf("Enter the card type:");
        scanf(" %[^\n]", type);
        push_end(ptr,&ptr,name,cash,type);
        break;
    case 2:
        printf("Enter the Id account:");
        scanf("%i",&id);
        printf("Enter what do you want to edit\n1-name\n2-cash\n3-card type\n=");
        scanf("%i",&ed_num);
        edit_by_id(&ptr,id,ed_num);
        break;
    case 3:
        printf("Enter the Id account:");
        scanf("%i",&id);
        delete_by_id(&ptr,id);
        break;
    case 4:
        printf("Enter the Id account:");
        scanf("%i",&id);
        print_by_id(&ptr,id);
        break;
    case 5:
        print_list(ptr);
        break;
    case 6:
        exit(0);
        break;
    default:
        printf("Wrong Option!!\n");
        break;
    }

}
    return 0;
}
