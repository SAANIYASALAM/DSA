#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* head=NULL,*temp,*newnode;
int count =0;
void insert_begining(struct node** hhead, int n)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    if(*hhead==NULL)
    {
       *hhead = newnode;
       newnode->next = NULL;
       count ++;
    }
    else
    {
        newnode->next = *hhead;
        *hhead = newnode;
        count ++;
    }
}
void insert_end(struct node** hhead, int n)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    if(*hhead==NULL)
    {
        *hhead = newnode;
        newnode->next = NULL;
        count ++;
    }
    else
    {
        temp = *hhead;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
        count ++;
    }
}
void insert_i(struct node** hhead, int n,int pos)
{
    int i=0;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    if(*hhead == NULL)
    {
        *hhead = newnode;
        newnode->next = NULL;
        count ++;
    }
    else
    {
        temp = *hhead;
        if(pos>count)
        {
            printf("the position is invalid...");
        }
        else
        {
            while(i<pos-1)
            {
                temp = temp->next;
                i++;
            }
            newnode->next = temp->next;
            temp->next = newnode;
            count++;
        }
    }
}
void display(struct node **hhead)
{
    temp = *hhead;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void main()
{
    int ch,n,pos;
    printf("choices:\n1.insert at begining\n2.insert at end\n3.insert at i'th position\n4.display the linked list\n5.end\n");
    do
    {
        printf("enter the choice:(1,2,3,4,5): ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter the data to insert: ");
                scanf("%d",&n);
                insert_begining(&head,n);
                break;
            case 2:
                printf("enter the data to insert: ");
                scanf("%d",&n);
                insert_end(&head,n);
                break;
            case 3:
                printf("enter the data to insert: ");
                scanf("%d",&n);
                printf("enter the position where the data need to be inserted: ");
                scanf("%d",&pos);
                insert_i(&head,n,pos);
                break;
            case 4:
                display(&head);
                break;
            case 5:
                printf("program ended...");
                break;
        }
    } 
    while (ch!=5);
}