#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*head;
void creation(int n)
{
    head=(struct node *)malloc(sizeof(struct node));
    struct node *temp;
    struct node *newnode;
    printf("Enter data =");
    scanf("%d",&head->data);
    head->prev=NULL;
    head->next=NULL;
    temp=head;
    for(int z=2;z<=n;z++)
    {
       newnode=(struct node *)malloc(sizeof(struct node));
       printf("Enter data=");
       scanf("%d",&newnode->data);
       newnode->prev=temp;
       newnode->next=NULL;
       temp->next=newnode;
       temp=temp->next;
    }
}
void traverse()
{
    struct node *temp=head;
    while(temp)
    {
        printf("Entered data=%d\n",temp->data);
        temp=temp->next;
    }
}
/*
void at_begin()
{
    struct node *begin=(struct node *)malloc(sizeof(struct node));
    printf("Enter data to add at begin=");
    scanf("%d",&begin->data);
    begin->next=head;
    begin->prev=NULL;
    head->prev=begin;
    head=begin;
}
void at_end()
{
    struct node *temp=head;
    if(temp->next==NULL)
    {

    }
}
*/
void delete()
{
    int del;
    printf("Enter Which Node you want to delete=");
    scanf("%d",&del);
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp=head;
    while(temp)
    {
        if(head->data==del)
        {
            head=temp->next;
            break;
        }
        else if(temp->next->data==del)
        {
            temp->next=temp->next->next;
            temp->next->next->prev=temp;
            break;
        }
        temp=temp->next;
    }
}
void main()
{
    int n;
    printf("Enter number of doubly list=");
    scanf("%d",&n);
    creation(n);
    traverse();
    delete();
    traverse();
}
