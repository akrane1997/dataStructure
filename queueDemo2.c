#include<stdio.h>
#include<stdlib.h>

struct queueNode
{
	char data;
	struct queueNode *nextPtr;



};

void printQueue( struct queueNode* );
int isEmpty( struct queueNode* );
void enqueue( struct queueNode**,struct queueNode**,char );
char dequeue( struct queueNode**,struct queueNode** );
void instruction( void );

int main()
{
	struct queueNode* headPtr=NULL,*tailPtr=NULL;
	int choice;
	char value;
	instruction();
	printf("Enter choice:\n");
	scanf("%d",&choice);
	while(choice!=3)
	{	
		switch( choice )
		{
			case 1: printf("Enter charater for enqueue in queue:");
				scanf("\n%c",&value);
				enqueue(&headPtr,&tailPtr,value);
				printQueue(headPtr);
				break;

			case 2: if(!isEmpty(headPtr))
				{
					value=dequeue(&headPtr,&tailPtr);
					printf("%c has been dequeue.\n",value);
					printQueue(headPtr);
					break;
				}

			default: printf("please Enter valid choice.\n ");
			         instruction();
				 break;	

		}
		printf("\nEnter choice:\n");
		scanf("%d",&choice);
	}

	printf("End of run.");
	return 0;	

}

void instruction( void )
{
	printf("Enter your choice\n"
		" 1. Enqueue value to queue.\n"
		" 2. Dequeue value from queue.\n"
		" 3. Exit from program.\n");
}


void enqueue(struct queueNode** headPtr,struct queueNode** tailPtr,char data)
{
	struct queueNode *newPtr;
	newPtr=malloc(sizeof(struct queueNode));
	
	if(newPtr != NULL)
	{
		newPtr->data=data;
		newPtr->nextPtr=NULL;
		
		if(isEmpty( *headPtr ))
		{
			*headPtr=*tailPtr=newPtr;
				
		}
		else
			(*tailPtr)->nextPtr=newPtr;
			
		*tailPtr=newPtr;
		
	}
	else
		printf("not inserted.\n");

}

char dequeue(struct queueNode** headPtr,struct queueNode** tailPtr)
{
	char value;
	struct queueNode* tempPtr;
	
	value=(*headPtr)->data;
	*headPtr=tempPtr;
	*headPtr=(*headPtr)->nextPtr;
	if(*headPtr==NULL)
		*tailPtr=NULL;

	free(tempPtr);

	return value;
	

}

void printQueue(struct queueNode *currentPtr)
{
	if(currentPtr==NULL)
		printf("queue is empty.\n\n");

	else
	{
		printf("the queue is:\n");
		
		while(currentPtr != NULL)
		{
			printf("%c-->",currentPtr->data);
			currentPtr=currentPtr->nextPtr;	
		}
		printf("NULL\n");

	}


}

int isEmpty(struct queueNode *headPtr)
{
	return headPtr==NULL;
}





























