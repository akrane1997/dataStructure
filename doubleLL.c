#include<stdio.h>
#include<stdlib.h>

struct listNode
{
	int data;
	struct listNode *next;
	struct listNode *prev;
};

struct listNode *init(int data)
{
	struct listNode *new;
	new=(struct listNode*)malloc(sizeof(struct listNode));
	if(new)
	{
		new->data=data;
		new->next=NULL;
		new->prev=NULL;	
	}
	return new;

}

void insert_first(struct listNode **head,struct listNode *new)
{
		if(*head==NULL)
			*head=new;
		else
		{
			new->next=*head;
			(*head)->prev=new;
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
		(*head)->prev=new;
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
		temp->next->prev=new;
		new->prev=temp;
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
			start->next->prev=prev;
			start->next=NULL;
			start->prev=NULL;
			free(start);
			//print_List(*head);
		}
		else
			printf("\nNode not found.");
	}



}

void print_List(struct listNode * head)
{
	
	while(head!=NULL)
	{
		printf("%d-->",head->data);
		head=head->next;	
	}
	printf("NULL\n");



}

int length(struct listNode *start)
{
        int count=1;
        while(start->next)
        {
        	           start=start->next;
                           count++;
        }
        return count;
}


int main()
{
	int a,pos;
	struct listNode *start=NULL;
	struct listNode *ptr;

	ptr=init(10);
	if(ptr==NULL)
		printf("\nfail to create Node.");
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
		insert_middle( &start,ptr,2 );
	print_List( start );
	

	delete(&start,11);
	print_List( start );
	
	printf("\n Total Number of Elements : %d\n",length(start));



}
