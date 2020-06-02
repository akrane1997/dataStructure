#include<stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *link;
};

struct node *head;

void insert_first(void);
int length();
void display();
void insert_last(void);
void insert_middle(void);
void delete(void);

int len;
void main()
{	
	int ch;
	while(1)
	{
		printf("\n\n1 insert first.");
	 	printf("\n2 insert last.");
		printf("\n3 insert middle.");
		printf("\n4 length.");
		printf("\n5 delete");
		printf("\n6 display.");
		printf("\n7 exit.");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : insert_first();
				 break;
				
			case 2 : insert_last();
				break;

			case 3 : insert_middle();
				break;
			case 4 : len=length();
				printf("length:-%d",len);
				break;

			case 5 : delete();
				break;
				
			case 6 : display();
				break;

			case 7 : exit(1);
			
		}

}
	/*insert_first(10);
	insert_first(20);
	insert_first(30);
	insert_first(40);
	len=length();
	printf("length:-%d",len);
	display();
	insert_last(50);
	insert_middle(60);*/
	
}

void insert_first()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data for insert first: ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		temp->link=head;
		head=temp;	
	}

}

int length()
{
	struct node *temp;
	int count=0;
	temp=head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
	}
	return count;

}

void insert_last()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data for insert last: ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		struct node *p;
		p=head;
		while(p->link != NULL)
		{
			p=p->link;
		}	
		p->link=temp;
	}

}

void display()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d -->",temp->data);
		temp=temp->link;

	}

}

void insert_middle()
{
	struct node *temp,*p;
	int loc;
	printf("\nEnter loc for insert middle:");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("\nsorry this location is not available in linked list");
		printf("\nlinked list length is: %d",len);
	}
	else
	{
		p=head;
		int i=1;
		while(i<loc-1)
		{
			p=p->link;
			i++;
		}	
		temp=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter data to insert middle:");
		scanf("%d",&temp->data);
		temp->link=NULL;
		temp->link=p->link;
		p->link=temp;
	}

}

void delete()
{
	struct node *temp,*p;
	int loc,len;
	len=length();
	printf("Enter loc for delete node: ");
	scanf("%d",&loc);
	if(loc > len)
	{
		printf("\nsorry this location is not available in linked list");
		printf("\nlinked list length is: %d",len);
	}
	else if(loc == 1)
	{
		temp=head;
		head=temp->link;
		temp->link=NULL;
		free(temp);
	}
	else
	{	
		temp=head;
		int i=1;
		while(i < loc-1)
		{	
			
			p=p->link;
			
			i++;
		}
		
		temp=p->link;
		p->link=temp->link;
		temp->link=NULL;
		free(temp);
		
	}


}





