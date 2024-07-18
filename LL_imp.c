#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node *head=NULL,*temp,*newnode;
void main()
{
    int choice,count=0;
    do
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("enter the data to be inserted into the node: ");
        scanf("%d",&newnode->data);
        if(head == NULL)
        {
            head = temp = newnode;
            newnode->next = NULL;
        }
        else
        {
            temp->next = newnode;
            temp= newnode;
            newnode->next = NULL;
        }
        printf("enter 1 to continue and 0 to stop: ");
        scanf("%d",&choice);
    }
    while(choice);
    printf("the elements in the linked list are: ");
    temp = head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
        count ++;
    }
    printf("the number of elements in the linked list are: %d",count);
}