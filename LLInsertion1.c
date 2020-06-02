#include <stdio.h>
#include <malloc.h>

struct node{
int data;
struct node *next;
};

struct node *head=NULL;


int insert_first(int);
int insert_last(int);
void display();


void main()
{
	 insert_first(1);
	insert_first(2);
	display();
	insert_last(10);
	insert_last(20);
	display();	
}


int insert_first(int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		temp->next=head;
		head=temp;
		
	}


}

int insert_last(int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		struct node *p;
		p=head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
	}

}

void display()
{
	struct node *d;
	d=head;
	while(d!=NULL)
	{
		printf("%d-->",d->data);		
		d=d->next;	
	}	
	
}
