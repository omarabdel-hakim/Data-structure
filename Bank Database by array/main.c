#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define n 100
unsigned int Id;
unsigned int counter=0;

struct customer
{
    char name[50];
    unsigned int id;
    double cash;
    char type[7];
}cust[n];
unsigned int *ptr;
int main()
{
unsigned int option;

printf("\t\t\t\tWelcome to our Bank :)\n");
S1:printf("\n**********************************************\n");
printf("1-Create a New customer\n");
printf("2-Edit customer\n");
printf("3-Delete customer\n");
printf("4-Print customer Data\n");
printf("5-cash transfer from customer to another\n");
printf("6-Exit\n");
printf("\t\t\t\tPlease Select One Of The Following Option:");
scanf("%i",&option);
printf("**********************************************\n");
fflush(stdin);
if (option==1) //New Account
{
    if (counter<n)
    {
    printf("Account Id %d:\n",counter+1);
    printf("enter the Name(%d):",counter+1);
    gets(cust[counter].name);
    printf("enter the cash(%d):",counter+1);
    scanf("%lf",&cust[counter].cash);
    fflush(stdin);
    printf("enter the type(debit/credit)(%d):",counter+1);
    gets(cust[counter].type);
    counter+=1;
    goto S1;
    }
    else
    {
        printf("Not Enough Storage\n");
        goto S1;
    }

}
else if (option==2) // EDIT
{

    printf("Please Enter the Id:");
    L1:scanf("%d",&Id);
    ptr=&cust[Id-1];
    if (*ptr!=0 && Id>0 && Id<n+1)
    {
    printf("%s(1):\n",cust[Id-1].name);
    printf("enter the New cash(1):");
    scanf("%lf",&cust[Id-1].cash);
    fflush(stdin);
    printf("enter the New type(debit/credit)(1):");
    gets(cust[Id-1].type);
    goto S1;
    }
    else
    {
        printf("Id not Found\n");
        printf("Please Reenter the Id:");
        goto L1;
    }
}

else if (option==3) //DELETE
{
    printf("Please Enter the Id:");
    L2:scanf("%d",&Id);
    ptr=&cust[Id-1];
    if (*ptr!=0 && Id>0 && Id<n+1)
    {
    strcpy(cust[Id-1].name,"0") ;
    cust[Id-1].cash=0;
    strcpy(cust[Id-1].type,"0");
    goto S1;
    }
    else
    {
        printf("Id not Found :(\n");
        printf("Please ReEnter the Id:");
        goto L2;
    }
}

else if (option==4) //PRINT
{
    printf("Please Enter the Id:");
    L3:scanf("%d",&Id);
    ptr=&cust[Id-1];
    if (*ptr!=0 && Id>0 && Id<n+1)
    {
        printf("name:%s\n",cust[Id-1].name);
        printf("cash:%lf\n",cust[Id-1].cash);
        printf("type:%s\n",cust[Id-1].type);
        goto S1;
    }
    else
    {
        printf("Id not Found :(\n");
        printf("Please ReEnter the Id:");
        goto L3;
    }
}
else if (option==5)
{
    unsigned int money;
    printf("Please Enter the Id of Sender:");
    scanf("%d",&Id);
    printf("Please Enter the Money which will be transfer:");
    scanf("%d",&money);
    cust[Id-1].cash-=money;
    printf("Please Enter the Id of Receiver:");
    scanf("%d",&Id);
    cust[Id-1].cash+=money;
    goto S1;
}
else if (option==6)
{
    printf("Thank you for choosing our Bank :)\n\n");
}
else
{
    printf("Wrong Option :(\n");
    printf("Please Try again");
    goto S1;
}

    return 0;
}
