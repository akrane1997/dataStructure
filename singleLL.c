#include <stdio.h>
#include <stdlib.h>

struct listNode
{
	int data;
	struct listNode *next;

};

struct listNode *init(int data)
{
	struct listNode *new;
	new=(struct listNode*)malloc(sizeof(struct listNode));
	
	if(new)
	{
		new->data=data;
		new->next=NULL;

	}
	return new;
	
}

void insert_first(struct listNode **head,struct listNode *new)
{
	if(*head==NULL)
	{
		*head=new;
	}
	else
	{
		new->next=*head;
		*head=new;
	}

}

void insert_middle(struct listNode **head,struct listNode *new,int pos)
{
	int i=1;
	struct listNode *temp=*head;
	if(temp==NULL ||pos==1 )
	{
		new->next=*head;
		*head=new;
	}
	else
	{
		while((i<pos-1) && temp)
		{
			temp=temp->next;
			i++;	
		}
	}
	if(temp!=NULL)
	{
		new->next=temp->next;
		temp->next=new;
			
	}
	else
		printf("\nnot a valid position.");

}

void delete(struct listNode **head,int data)
{
	struct listNode *temp,*start=*head,*prev=*head;
	if(start==NULL)
	{
		printf("\nlist is empty.");
		return;
	}
	if(start->data==data)
	{
		temp=start;
		*head=start->next;	

		free(temp);
		//print_List( *head );
		return;	
	}
	else
	{
		while((start->data !=data) && start)
		{
			prev=start;
			start=start->next;	
		}	
		if(start!=NULL)
		{
			prev->next=start->next;
			free(start);
			//print_List(*head);
		}
		else
			printf("\nNode not found.");
	}



}
void print_List(struct listNode *head )
{
	struct listNode *temp;
	temp=head;
	
		while(temp!=NULL)
		{
			printf("%d-->",temp->data);
			temp=temp->next;
		}
		printf("NULL\n");
	
}

int main()
{	
	int a;
	struct listNode *start=NULL;
	struct listNode *ptr;

	ptr=init(10);
	if(ptr==NULL)
		printf("\nfail to create a node.");
	else
		insert_first( &start,ptr );
	print_List( start );

	ptr=init(11);
	if(ptr==NULL)
		printf("\nfail to create a node.");
	else
		insert_first( &start,ptr );
	print_List( start );

	ptr=init(12);
	if(ptr==NULL)
		printf("\nfail to create a node.");
	else
		insert_first( &start,ptr );
	print_List( start );

	ptr=init(40);
	if(ptr==NULL)
		printf("\nfail to create a node.");
	else
		insert_middle( &start,ptr,4 );
	print_List( start );

	delete(&start,10);
	print_List( start);
}
