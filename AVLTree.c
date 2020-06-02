#include <stdio.h>
#include <stdlib.h>
struct AVLNode 
{
	int data;
	int height;
	struct AVLNode *left;
	struct AVLNode *right;
};
struct AVLNode *root=NULL;

int height(struct AVLNode *root)
{
	int heightL,heightR;
	heightL=root && root->left?root->left->height:0;
	heightR=root && root->right?root->right->height:0;
	
	return heightL > heightR?heightL+1:heightR+1;

}

int balanceFactor(struct AVLNode *root)
{
	int heightL,heightR;
	heightL=root && root->left?root->left->height:0;
	heightR=root && root->right?root->right->height:0;
	
	return heightL - heightR;

}

struct AVLNode *LLrotation(struct AVLNode *parent)
{
	struct AVLNode *pL=parent->left;
	struct AVLNode *pLR=pL->right;
	
	pL->right=parent;
	parent->left=pLR;

	parent->height=height(parent);
	pL->height=height(pL);
	
	if(root==parent)
		root=pL;

	return pL;
	
}

struct AVLNode *LRrotation(struct AVLNode *parent)
{
	struct AVLNode *pL=parent->left;
	struct AVLNode *pLR=pL->right;
	
	pL->right=pLR->left;
	parent->left=pLR->right;

	pLR->right=parent;
	pLR->left=pL;

	parent->height=height(parent);
	pL->height=height(pL);
	pLR->height=height(pLR);
	
	if(root==parent)
		root=pLR;
	
	return pLR;


}

struct AVLNode *RRrotation(struct AVLNode *parent)
{
	struct AVLNode *pR=parent->right;
	struct AVLNode *pRL=pR->left;
	
	pR->left=parent;
	pR->right=pRL;

	parent->height=height(parent);
	pR->height=height(pR);
	
	if(root==parent)
		root=pR;

	return pR;
	
}

struct AVLNode *RLrotation(struct AVLNode *parent)
{
	struct AVLNode *pR=parent->right;
	struct AVLNode *pRL=pR->left;
	
	pR->left=pRL->right;
	parent->right=pRL->left;

	pRL->left=parent;
	pRL->right=pR;

	parent->height=height(parent);
	pR->height=height(pR);
	pRL->height=height(pRL);
	
	if(root==parent)
		root=pRL;
	
	return pRL;


}


struct AVLNode *insertion(struct AVLNode *parent,int data)
{
	struct AVLNode *temp=NULL;
	if(temp == NULL)
	{
		temp=(struct AVLNode*)malloc(sizeof(struct AVLNode));
		
		temp->data=data;
		temp->height=1;
		temp->right=NULL;
		temp->left=NULL;
	
		return temp;
	}
	
	if(data < parent->data)
		parent->left=insertion(parent->left,data);
	if(data > parent->data)
		parent->right=insertion(parent->right,data);
	parent->height=height(parent);
	
	if(balanceFactor(parent)==2 && balanceFactor(parent->left)==1)
		return LLrotation(parent);
	
	if(balanceFactor(parent)==2 && balanceFactor(parent->left)==-1)
		return LRrotation(parent);

	if(balanceFactor(parent)==-2 && balanceFactor(parent->right)==-1)
		return RRrotation(parent);

	if(balanceFactor(parent)==-2 && balanceFactor(parent->right)==1)
		return RLrotation(parent);

	return parent;


}

void inorder(struct AVLNode *root)
{
	if(root->left )
	{
		inorder(root->left);	
	}
	printf("%d-->",root->data);
	if(root->right)
	{
		inorder(root->right);	
	}
	
}

void main()
{
	
	
	root=insertion(root,50);
	   root=insertion(root,10);
	    root=insertion(root,60);
	    root=insertion(root,30);
		root=insertion(root,20);
		root=insertion(root,40);
		root=insertion(root,10);
		root=insertion(root,9);
		root=insertion(root,6);
		inorder(root);

	
}
