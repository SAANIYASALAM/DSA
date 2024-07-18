#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node *head,*temp;
void main()
{
    int ch,count = 0,data;
    do
    {
        switch(ch)
        {
            case 1:
                printf("enter the data need to be inserted: ");
                scanf("%d",&data);
                struct node *newnode = (struct node*)malloc(sizeof(struct node));
                newnode->data = data;
                if(head==NULL)
                {
                    head = newnode;
                    newnode->next = NULL;
                }
                else
                {
                    temp = head;
                    while(temp->next!=NULL)
                    {
                        temp= temp->next;
                    }
                    temp->next = newnode;
                    newnode->next = NULL;
                }
        }
        printf("do you need to add nodes?(1/0): ");
        scanf("%d",&ch);
    } 
    while(ch!=0);
    printf("the elements in the linked list are : ");   
    temp = head;
    while(temp!=0)
    {
        printf("%d->",temp->data);
        count ++;
        temp = temp->next;
    } 
    printf("\n");
    printf("the number of elements in the linked list is %d",count);
}