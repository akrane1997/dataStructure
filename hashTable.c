#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	int value;
	struct node *next;
};

struct arrayitem
{
	struct node *head;
	struct node *tail;
};

struct arrayitem *array;
int size=0;
int max=10;

int hashcode(int key)
{
	return (key%max);
}

void insert(int key,int value)
{
	float n=0.0;
	int index=hashcode(key);
	
	struct node *list=(struct node*)array[index].head;
	
	struct node *item=(struct npde*)malloc(sizeof(struct node));
	item->key=key;
	item->value=value;
	item->next=NULL;
	
	if(list==NULL)
	{
		array[index].head=item;
		array[index].tail=item;
		size++;	
	}
	else
	{
		int find_index=find(list,key);	
		if(find_index == -1)
		{
			array[index].tail->next=item;
			araay[index].tail=item;
			size++;	
		}
		else
		{
			struct node *element=get_element(list,find_index);
			element->value=value;	
		}
	}
	
	n=(1.0 * size)/max;
	if(n>=0.75)
	{
		rehashing();	
	}
	

}

void rehashing()
{
	struct arrayitem *temp=array;
	
	int i=0;m=max;
	size=0;
	max=2*max;
	array=(struct arrayitem*)malloc(max*sizeof(struct node));
	init_array();
	
	for(i=0;i<n;i++)
	{
		struct node *list=(struct node*)temp[i].head;
	
		if(list==NULL)
		{
			continue;	
		}		
		else
		{
			while(list!=NULL)
			{
				insert(list->key,list->value);
				list=list->next;
			}	
		}
	}
	temp=NULL;


}

int find(struct node *list,int key)
{
	int count=0;
	struct node *temp=list;
	while(temp != NULL)
	{
		if(temp->key==key)
			return count;

		temp=temp->next;
		count++;	
	}
	return -1;
	
}

struct node *get_element(struct node *list,int find_index)
{
	int i=0;
	struct node *temp=list;	
	while(i!=find_index)
	{	
		temp=temp->next;
		i++;	
	}	
	return temp;
	
}

void display()
{
	int i=0;
	for(i=0;i<max;i++)
	{
		struct node *temp=array[i].head;
		if(temp==NULL)
		{
			printf("array[%d] has no elements\n",i);	
		}	
		else
		{
			printf("array[%d] has elements:-",i);
			while(temp!=NULL)
			{
				printf("key=%d value=%d ",temp->key,temp->value);
				temp=temp->next;
	
			}	
			printf("\n");
		}
	}

}

init_array()
{
	int i=0;
	for(i=0;i<max;i++)
	{
		array[i].head=NULL;
		array[i].tail=NULL;	
			
	}

}
void main()
{
	int choice,key,valye,n,c;
	
	array=(struct arrayitem*)malloc(max*sizeof(struct arrayitem));
	init_array();
	do
	{
		printf("Implementation of hash chaining with single linked list\n\n");
		printf("\n1. Inserting items in hash table"
		       "\n2. check the size of hash table"
			"\n3. Display hash table"
			"\n\n please enter your choice:-");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Inserting element in hash table\n");
				printf("Enter key and value :-");
				scanf("%d %d",&key ,&value);
				insert(key,value);
				break;
	
			case 2:
				n=size_of_array();
				printf("size of hash table is :-%\n",n);
				break;
			case 3:
				display();
				break;
	
			default:
	
				printf("wrong input\n");	
				
		}
		printf("\nDo you waant to continue :-(press 1 for yes)");
		scanf("%d",&c);
	}
	while(c==1);	

}
