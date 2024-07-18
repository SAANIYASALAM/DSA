#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head,*newnode,*temp,*prevnode,*nextnode;
void main()
{
    int ch,n,pos,i=1;
    printf("choices:\n1.create node\n2.delete from begining\n3.delete from end\n4.delete from a specific position\n5.display the linked list\n6.end");
    do
    {
        printf("enter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter the data need to be inserted: ");
                scanf("%d",&n);
                newnode = (struct node*)malloc(sizeof(struct node));
                newnode->data = n;
                if(head==NULL)
                {
                    head = newnode;
                    newnode->next = NULL;
                }
                else
                {
                    temp= head;
                    while(temp->next!=NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = newnode;
                    newnode->next = NULL;
                }
                break;
            case 2:
                if(head==NULL)
                {
                    printf("no data to be deleted...");
                }
                else if(head->next==NULL)
                {
                    head = NULL;
                }
                else
                {
                    temp = head;
                    head = head->next;
                    free(temp);
                }
                break;
            case 3:
                if(head == NULL)
                {
                    printf("no data to be deleted...");
                }
                else if(head->next==NULL)
                {
                    head=NULL;
                }
                else
                {
                    temp = head;
                    while(temp->next!=NULL)
                    {
                        prevnode = temp;
                        temp = temp->next;
                    }
                    prevnode->next = NULL;
                    free(temp);
                }
                break;
            case 4: 
                printf("enter the position: ");
                scanf("%d",&pos);
                temp = head;
                while(i<pos-1)
                {
                    temp = temp->next;
                    i++;
                }
                nextnode=temp->next;
                temp->next = nextnode->next;
                free(nextnode);
                break;
            case 5:
                printf("the elements in the lined list are: ");
                temp = head;
                while(temp!=NULL)
                {
                    printf("%d->",temp->data);
                    temp=temp->next;
                }
                break;
            case 6:
                printf("the program ended...");
        }
    }
    while(ch!=6);
}