#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
typedef struct bintree node;
struct bintree
{
    int data;	// Value of the node
    node*left,*right;	// Left and right nodes or subtrees
};

// To insert a new element into the BST
node* insert(node*tree, int element)
{
    //Create a new node and populate its variables
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
        // Traversing until NULL and maintaining BST property
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
	// Correct position found, insert
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
            	// Found the element
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
        return INT_MIN;
    while(tree->left!=NULL)
        tree=tree->left;
    return tree->data;
}
int findMax(node*tree)
{
    if(tree==NULL)
        return INT_MIN;
    while(tree->right!=NULL)
        tree=tree->right;
    return tree->data;
}

node*successor(node*tree,int node)
{
	struct bintree* choice;
	if(tree==NULL)
	return NULL;
	if(node<tree->data)
	{choice= successor(tree->left,node);
	if(choice==NULL)
		{
			return tree;
		}
	else
		return choice;
	}
	else if(node>tree->data)
	{return successor(tree->right,node);
	}
	else if(tree->data==node)
	{
	if(tree->right!=NULL)
	{
		tree=tree->right;
		while(tree->left!=NULL)
			tree=tree->left;
		return tree;
	}
	else
	{
		return NULL;
	}
	}
}

node*predecessor(node*tree,int node)
{	
	struct bintree* choice;
	if(tree==NULL)
	return NULL;
	if(node<tree->data)
	{return predecessor(tree->left,node);
	}
	else if(node>tree->data)
	{choice=predecessor(tree->right,node);
	if(choice==NULL)
		{
			return tree;
		}
	else
		return choice;
	}
	else if(tree->data==node)
	{
	if(tree->left!=NULL)
	{
		tree=tree->left;
		while(tree->right!=NULL)
			tree=tree->right;
		return tree;
	}
	else
	{
		return NULL;
	}
	}
}

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

int level(node*tree, int node)
{
    if(tree==NULL)  //NOT FOUND
        return -1;
    int ret_val;
    
    if(tree->data==node)
        return 0;
    else if(node<tree->data)
        ret_val=level(tree->left,node);
    else
        ret_val=level(tree->right,node);
    
    if(ret_val!=-1)         //FOUND
        return 1+ret_val;   //Trav.thru all edge till root from node
    else                    //NOT FOUND(cascadingly returns -1)
        return ret_val;
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

int main()
{
    int element;int tmp;
    node*tree=NULL,*find;
   char sel[5];
   while(1)
   {
       scanf("%s", sel);
       if(strcmp(sel,"insr")==0)
       {
           scanf("%d",&element);
           tree=insert(tree,element);
        }
       else if(strcmp(sel,"srch")==0)
       {
           scanf("%d",&element);
           if(search(tree,element)!=NULL)
               printf("FOUND\n");
           else
               printf("NOT FOUND\n");
        }
       else if(strcmp(sel,"minm")==0)
       {
           tmp = findMin(tree);
           if(tmp==-9999)
               printf("NIL\n");
           else
               printf("%d\n",tmp);
       }
       else if(strcmp(sel,"maxm")==0)
       {
            tmp = findMax(tree);
            if(tmp==-9999)
               printf("NIL\n");
            else
               printf("%d\n",tmp);
       }
       else if(strcmp(sel,"pred")==0)
       {
           scanf("%d",&element);
           find=predecessor(tree,element);
           if(find!=NULL&&search(tree,element)!=NULL)
           printf("%d\n",find->data);
           else if(search(tree,element)==NULL)
           printf("NULL\n");
           else
           printf("-1\n");
    	}
       else if(strcmp(sel,"succ")==0)
       {
           scanf("%d",&element);
           find=successor(tree,element);
           if(find!=NULL&&search(tree,element)!=NULL)
           printf("%d\n",find->data);
           else if(search(tree,element)==NULL)
           printf("NULL\n");
           else
           printf("-1\n");
    	}
       else if(strcmp(sel,"delt")==0)
       {
            scanf("%d",&element);
            if(search(tree,element)==NULL)
                printf("NULL\n");
            else
                tree=delete(tree,element);
       }
       else if(strcmp(sel,"inor")==0)
       {
           inorder(tree);
           printf("\n");
        }
       else if(strcmp(sel,"prer")==0)
       {
           preorder(tree);
           printf("\n");
        }
       else if(strcmp(sel,"post")==0)
       {
           postorder(tree);
           printf("\n");
       }
	else if(strcmp(sel,"prep")==0)
	{
		prep(tree);
		printf("\n");
	}
       else if(strcmp(sel,"stop")==0)
       {return 0;}
       else if(strcmp(sel,"levl")==0)
       {
           scanf("%d",&element);
           printf("%d    :\n",level(tree,element));
       }
   }
}
