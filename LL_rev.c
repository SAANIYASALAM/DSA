#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node* next;
};
struct node *head=NULL ,*newnode,*temp, *prevnode, *currentnode ,*nextnode;
void main()
{
    int ch,n;
    do
    {
        printf("enter the data: ");
        scanf("%d",&n);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = n;
        if(head == NULL)
        {
            head = newnode;
            newnode->next = NULL;
        }
        else
        {
            temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = NULL;
        }
        printf("linked list: ");
        temp = head;
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("\n");
        printf("add node?(yes(1)/no(0):");
        scanf("%d",&ch);
    } 
    while(ch!=0);
    prevnode=NULL;
    currentnode=head;
    while(currentnode!=NULL)
    {
        nextnode=currentnode->next;
        currentnode->next = prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head = prevnode;
    printf("the reversed linked list: ");
    temp = head;
    if(head==NULL)
    {
        printf("the linked list is empty...\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp = temp->next;
        }
    }
}