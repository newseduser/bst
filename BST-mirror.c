#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct bintree node;
struct bintree
{
    int data;
    node*left,*right;
};


node* pareninsert(node*tree)
{
    //CREATE CHILD
    int el;char ch=getchar();
    if(ch=='(')
    {
        if(scanf("%d ",&el)==1)
        {
            node*new = (node*)malloc(sizeof(node));
            new->data = el;
            new->left=pareninsert(new);
            new->right=pareninsert(new);
            getchar();getchar();
            return new;
        }
        else
        {
            getchar();getchar();
            return NULL;
        }
    }
}


void inorder(node*tree) //Left,print,right
{
    if(tree==NULL)
        return;
    inorder(tree->left);
    printf("%d ",tree->data);
    inorder(tree->right);
}
void postorder(node*tree)   //Left,right,print
{
    if(tree==NULL)
        return;
    postorder(tree->left);
    postorder(tree->right);
    printf("%d ",tree->data);
}
void preorder(node*tree)    //Print,left,right
{
    if(tree==NULL)
        return;
    printf("%d ",tree->data);
    preorder(tree->left);
    preorder(tree->right);
}

//****************************************************************
node* search(node*tree,int element)
{
    while(tree!=NULL)
    {
        if(tree->data==element)
        {
            return tree;
        }
        else if(element<tree->data)
            tree=tree->left;
        else
            tree=tree->right;
    }
    return NULL;
}

int findMin(node*tree)
{
    if(tree==NULL)
        return -9999;
    while(tree->left!=NULL)
        tree=tree->left;
    return tree->data;
}
int findMax(node*tree)
{
    if(tree==NULL)
        return -9999;
    while(tree->right!=NULL)
        tree=tree->right;
    return tree->data;
}

node*delete(node*tree,int element)
{
    node*x=tree;
    if(x==NULL)
        return x;
    if(element<x->data)
        x->left=delete(x->left,element);
    else if(element>x->data)
        x->right=delete(x->right,element);
    else
    {
        node*temp=x;
        if(x->left==NULL)
        {
            x=x->right;
            return x;
        }
        if(x->right==NULL)
        {
            x=x->left;
            return x;
        }
        node*y=x->right;
        while(y->left!=NULL)
            y=y->left;
        x->right=delete(x->right,y->data);
        x=y;
        x->right=temp->right;
        x->left=temp->left;
        free(temp);
    }
    return x;
}

//*********************** Q2 **************************************
void paren(node*tree)
{
    printf("( ");
    if(tree!=NULL)
    {
        printf("%d ",tree->data);
        paren(tree->left);
        paren(tree->right);
        printf(") ");
    }
    else
        printf(") ");
}
//************************ Q2 ************************************

//*********************** Q3 **************************************

node*mirror(node*tree)
{
    if(tree==NULL)
        return NULL;
    node*new = (node*)malloc(sizeof(node));
    new->data = tree->data;
    new->left=mirror(tree->right);
    new->right=mirror(tree->left);
    return new;
}
    
//*********************** Q3 **************************************

int main()
{
    int element;int tmp;
    node*tree=NULL;
    tree=pareninsert(tree);
    //paren(tree);
    node*mirrortree=mirror(tree);
    paren(mirrortree);
}
