#include <stdio.h>
#include <malloc.h>

int insert(int);
void display();

struct node{
int data;
struct node *next;
};

struct node *head=NULL;
void main()
{	
	
	insert(10);
	insert(20);
	insert(30);
        insert(40);
	display();
}

int insert(int data)
{
	struct node *temp;
	temp=(struct node*) malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	
	 if(head==NULL)
	{
		head=temp;
		
	}
	else
	{
		struct node *temp1;
		temp1=head;
		while(temp1->next!=NULL)	
		{
			temp1=temp1->next;
		}
		temp1->next=temp;
             
	}
}
void display(void)
{
	struct node *p;
	p=head;
	while(p->next != NULL)
	{
		printf("list:%d",p->data);
		p=p->next;	
	}
	
	
}

