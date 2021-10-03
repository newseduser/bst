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
            if(element<trav->data)
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
        if(element<ins->data)
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

int main()
{
    int element;
    node*tree=NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&element);
        tree=insert(tree,element);
    }
    paren(tree);
}
