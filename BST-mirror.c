#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct bintree node;
struct bintree
{
    int data;
    node*left,*right;
};

node* insert(node*tree, int element)
{
    //CREATE ELEMENT
    node*new = (node*)malloc(sizeof(node));
    new->data = element;
    new->left=NULL;
    new->right=NULL;
    node*trav=tree,*ins=tree;
    //EMPTY TREE CASE
    if(tree==NULL)
        tree=new;
    else
    {
        //FIND INSERTION POSITION
        
        while(trav!=NULL)
        {
            if(element<=trav->data)
            {
                ins=trav;
                trav=trav->left;
            }
            else
            {
                ins=trav;
                trav=trav->right;
            }
        }
        if(element<=ins->data)
            ins->left=new;
        else
            ins->right=new;
    }
    return tree;
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
