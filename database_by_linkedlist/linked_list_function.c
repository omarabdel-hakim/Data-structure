#include "linked_list_function.h"
int id_num=-1;

void print_list(node *head)
{
    if (head == '\0')
    {
        printf("The linked List is Empty.");
    }
    else
    {
        while(head != '\0')
        {
            printf("Customer name: ");
            puts(head->name);
            printf("ID: %u\n",head->id);
            printf("CASH: %0.1f\n",head->cash);
            printf("Visa type: ");
            puts(head->type);
            head=head->next;
            printf("\n");
        }

    }

}
void push_head(node **head_ptr,char name[50],double cash,char type[10])
{
    id_num++;
    node *new_node='\0';
    new_node=(node*)malloc(sizeof(node));
    strcpy(new_node->name,name);
    new_node->id=id_num;
    new_node->cash=cash;
    strcpy(new_node->type,type);
    new_node->next=*head_ptr;
    *head_ptr=new_node;

}

void push_end(node *head,node **head_ptr,char name[50],double cash,char type[10])
{
    if (*head_ptr == '\0')
    {
        push_head(head_ptr,name,cash,type);
    }
    else
    {
        while(head->next != '\0')
        {
            head=head->next;
        }
        id_num++;
        node *new_node='\n';
        new_node=(node*)malloc(sizeof(node));
        strcpy(new_node->name,name);
        new_node->id=id_num;
        new_node->cash=cash;
        strcpy(new_node->type,type);
        new_node->next='\0';
        head->next=new_node;
    }
}

void pop_head(node **head_ptr)
{
    if (*head_ptr != '\0')
    {
        printf("\t!! Customer Account removed !! \n");
        node *next_node='\0';
        next_node=*head_ptr;
        printf("Customer name: ");
        puts(next_node->name);
        printf("ID: %u\n",next_node->id);
        printf("CASH: %0.1f\n",next_node->cash);
        printf("Visa type: ");
        puts(next_node->type);
        printf("\t!! XXXXXXXXX !! \n");
        *head_ptr=next_node->next;
        free(next_node);
        //id_num--;
    }
    else
    {
        printf("The linked List is Empty.");
    }
}

void delete_by_id(node **head_ptr,unsigned int id)
{

    if (id<0 || id>id_num)
    {
    printf("Wrong ID Number.");
    }
    else if (id==0)
    {
        pop_head(head_ptr);
    }
    else
    {
        int i=0;
        node *temp='\0';
        node *current=*head_ptr;
        if (*head_ptr == '\0')
        {
            printf("The linked List is Empty.");
        }
        else
        {
            for (i=0;i<id-1;i++)
            {
                current=current->next;
            }
            temp=current->next;

            printf("\t!! Customer Account removed !! \n");
            printf("Customer name: ");
            puts(temp->name);
            printf("ID: %u\n",temp->id);
            printf("CASH: %0.1f\n",temp->cash);
            printf("Visa type: ");
            puts(temp->type);
            printf("\t!! XXXXXXXXX !! \n");
            current->next=temp->next;
            free(temp);
            //id_num--;
        }
    }
}
node* print_by_id(node **head_ptr,unsigned int id)
{
    int i=0;
    node *temp='\0';
    node *current=*head_ptr;
    node *ret=0;
    if (id<0 || id>id_num)
    {
    printf("Wrong ID Number.");
    }
    else if (id==0)
    {
        printf("Customer name: ");
        puts(current->name);
        printf("ID: %u\n",current->id);
        printf("CASH: %0.1f\n",current->cash);
        printf("Visa type: ");
        puts(current->type);
        ret=current;
    }
    else
    {
        if (*head_ptr == '\0')
        {
            printf("The linked List is Empty.");
        }
        else
        {
            for (i=0;i<id-1;i++)
            {
                current=current->next;
            }

            temp=current->next;
            ret=temp;

            printf("Customer name: ");
            puts(temp->name);
            printf("ID: %u\n",temp->id);
            printf("CASH: %0.1f\n",temp->cash);
            printf("Visa type: ");
            puts(temp->type);


        }
    }
    return ret;
}
void edit_by_id(node **head_ptr,unsigned int id,unsigned int num)
{
    node *temp='\0';
    if (id<0 || id>id_num)
    {
    printf("Wrong ID Number.");
    }
    else if (id==0)
    {
        temp=print_by_id(head_ptr,id);
    }
    else
    {
        if (*head_ptr == '\0')
        {
            printf("The linked List is Empty.");
        }
        else
        {
            temp=print_by_id(head_ptr,id);
        }
    }
switch(num)
    {
        char x[10];
        case 1:
            printf("Enter the new name:");
            scanf(" %[^\n]", x);
            strcpy(temp->name,x);
        break;
        case 2:
            printf("Enter the new cash:");
            scanf("%lf",&temp->cash);
        break;
        case 3:
            printf("Enter the new card:");
            scanf(" %[^\n]", x);
            strcpy(temp->type,x);
        break;
    }
}
