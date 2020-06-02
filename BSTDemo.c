#include<stdio.h>
#include<stdlib.h>

struct BTSNode
{
	int data;
	struct BTSNode *right;
	struct BTSNode *left;
};

struct BTSNode *root=NULL;

void insertion(int data)
{
	struct BTSNode *temp,*p;
	
	temp=(struct BTSNode*)malloc(sizeof(struct BTSNode));
	temp->data=data;
	temp->right=NULL;
	temp->left=NULL;

	if(root==NULL)
	{
		root=temp;	
	}
	else
	{
		struct BTSNode *curr;
		curr=root;
		while(curr)
		{
			p=curr;
			if(temp->data > curr->data)
			{
				curr=curr->right;	
			}
			else
			{	
				curr=curr->left;			
			}
		}
		if(temp->data > p->data)
		{
			p->right=temp;	
		}
		else
		{
			p->left=temp;
		}	

	}

}
void inorder(struct BTSNode *root)
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
void preorder(struct BTSNode *root)
{
	
	printf("%d-->",root->data);
	if(root->left )
	{
		preorder(root->left);	
	}
	
	if(root->right)
	{
		preorder(root->right);	
	}

}

void postorder(struct BTSNode *root)
{
	
	
	if(root->left )
	{
		postorder(root->left);	
	}
	
	if(root->right)
	{
		postorder(root->right);	
	}
	printf("%d-->",root->data);

}

void delete(int data)
{
	
		struct BTSNode *curr,*p;
		curr=root;
		while(curr)
		{
			
			if(data > curr->data)
			{
				p=curr;				
				curr=curr->right;	
			}
			else if(data < curr->data)
			{	
				p=curr;
				curr=curr->left;			
			}
			else
			{
				if(curr->left == NULL && curr->right == NULL)
				{
					if(curr == p->left)
					{
						p->left=NULL;	
					}
					else
					{
						p->right=NULL;	
					}
					free(curr);
				
				}
				else if(curr == p->right && curr->left == NULL || curr->right == NULL)
				{
					if(curr->left != NULL)
					{
						if(curr == p->right)
						{
							p->right=curr->left;	
						}
						curr->left=NULL;
						free(curr);	
					}
					else
					{
						if(curr->right != NULL)
						{
							if(curr == p->right)	
							{
								p->right=curr->right;
							}
							curr->right=NULL;
							free(curr);
						}	
					}	
				}
				else if(curr == p->left && curr->left == NULL || curr->right == NULL)
				{
					if(curr->left != NULL)
					{
						if(curr == p->left)
						{
							p->left=curr->left;	
						}
						curr->left=NULL;
						free(curr);	
					}
					else
					{
						if(curr->right != NULL)
						{
							if(curr == p->left)	
							{
								p->left=curr->right;
							}
							curr->right=NULL;
							free(curr);
						}	
					}	
				}
				else
				{
					if(curr->left != NULL && curr->right != NULL)
					{
						struct BTSNode *t1;
						t1=curr->right;
						if(t1->right != NULL && t1->left == NULL)
						{
							curr->data=t1->data;
							curr->right=t1->right;
							t1->right=NULL;
							free(t1);	
						}	
					}	
				}
			}
		}



}
// Delete by Copying method
/*void delete( struct BTSNode *root,int item) {
 struct BTSNode *curr = root, *parent = NULL, *pred;
 int predecessorData;
 // search the node to be delete
 while(curr != NULL) {
  if(curr->data == item)
   break;
  parent = curr;
  if(item < curr->data)
   curr = curr->left;
  else
   curr = curr->right;
 }
 if(curr == NULL) {
  printf("\n Item not found");
  return;
 }
 // Leaf node
 if(curr->left == NULL && curr->right == NULL) {
  if(parent == NULL)
   root = NULL;
  else if(curr->data < parent->data)
   parent->left = NULL;
  else
   parent->right = NULL;
  free(curr);
  return;
  pred = inorder(curr);
 predecessorData = pred->data;
 delete(curr, pred->data);
 curr->data = predecessorData;
}
 }*/
void main()
{
	insertion(50);
	insertion(25);
	insertion(20);
	insertion(30);
	insertion(70);
	insertion(75);
	insertion(45);
	insertion(65);
	insertion(90);
	insertion(55);
	printf("\n In order traversal:\n");
	inorder(root);
	
	printf("\n pre order traversal:\n");
	preorder(root);
	
	printf("\n post order traversal:\n");
	postorder(root);
	
	printf("\n");
	
	delete(70);
	inorder(root);
}
