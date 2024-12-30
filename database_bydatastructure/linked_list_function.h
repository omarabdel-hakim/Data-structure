#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct account
{
    char name[50];
    unsigned int id;
    double cash;
    char type[10];
    struct account *next;
}node;

void print_list(node *head);
void push_head(node **head_ptr,char name[50],double cash,char type[10]);
void push_end(node *head,node **head_ptr,char name[50],double cash,char type[10]);
void pop_head(node **head_ptr);
void delete_by_id(node **head_ptr,unsigned int id);
node* print_by_id(node **head_ptr,unsigned int id);
void edit_by_id(node **head_ptr,unsigned int id,unsigned int num);
