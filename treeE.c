#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
int create()
{
    struct node*newnode=(struct node *)malloc(sizeof(struct node));
    int x;
    printf("Enter data of node(-1 for return)=");
    scanf("%d",&x);
    if(x==-1)
        return NULL;
    newnode->data=x;
    printf("Enter value for adding at left node of %d\n",newnode->data);
    newnode->left=create();
    printf("Enter value for adding at right node of %d\n",newnode->data);
    newnode->right=create();
    return newnode;
}
void inorder(struct node *node)
{
    if(node)
    {
     inorder(node->left);
     printf("%c\n",node->data);
     inorder(node->right);
    }
    else
    {
     return 0;
    }
}
void preorder(struct node *node)
{
     if(node)
    {
     printf("%c\n",node->data);
     preorder(node->left);
     preorder(node->right);
    }
    else
    {
     return 0;
    }
}
void postorder(struct node *node)
{
     if(node)
    {
     postorder(node->left);
     postorder(node->right);
     printf("%c\n",node->data);
    }
    else
    {
     return 0;
    }
}
int main()
{
    struct node *root=create();
struct node *t=root;
printf("Root child is %d\n ",t->data);
printf("the inorder is:\n");
inorder(t);
printf("the preorder is:\n");
preorder(t);
printf("the postorder is:\n");
postorder(t);
return 0;
}


