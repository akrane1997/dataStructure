#include<stdio.h>
#include<stdlib.h>

struct stackNode
{
	char data;
	struct stackNode *next; 


};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

char queue( StackNodePtr*,char );
//int pop( StackNodePtr* );
char isEmpty( StackNodePtr );
void instruction( void );
void printStack( StackNodePtr );
//void popAll( StackNodePtr );
char dequeue(StackNodePtr*);
int main()
{
	StackNodePtr StackPtr=NULL;
	int choice;
	char val;
	instruction();
	printf( "\nEnter choice Number:" );
	scanf( "%d",&choice );
	while( choice!=3 )
	{
		switch(choice)
		{
			case 1:printf("\nEnter value fot push into stack: ");
				scanf("%c",&val);
				queue(&StackPtr,val);
				printStack( StackPtr );
				break;
	
			case 2: if(!isEmpty(StackPtr))
					printf("\npoped value is: %c",dequeue( &StackPtr));
				printStack( StackPtr );
				break;
		
	
			default: printf( "invalid choice" ); 
				instruction();
				break;
		}
		printf( "\nEnter choice Number: " );
		scanf( "%d",&choice );
	
	}
	return 0;	

}

void instruction(void)
{
	printf("\n Enter choice: "
		"\n 1. to queue a value on the stack."
		"\n 2. to dequeue a value on the stack. " 
		"\n 3. Exit from program." );


}

char queue(StackNodePtr *headPtr,char data)
{
	StackNodePtr tempPtr;
	tempPtr=malloc(sizeof(StackNode));
	
	if(tempPtr!=NULL)
	{
		tempPtr->data=data;
		tempPtr->next=*headPtr;
		*headPtr=tempPtr;
	}
	else
		printf("\ndata not inserted in stack.");
}


char dequeue(StackNodePtr *topPtr)
{

 StackNodePtr tempPtr;
 StackNodePtr prevPtr;
	tempPtr=*topPtr;
 if(!tempPtr)
 return 0;
 
while(tempPtr->next){
    prevPtr=tempPtr;
    tempPtr=tempPtr->next;
}
prevPtr->next=NULL;
free(tempPtr);
}


void printStack(StackNodePtr currentPtr)
{
	
	if(currentPtr == NULL)
	{
		printf("\nStack is Empty.\n\n");
	}
	else
	{
		printf("\nThe Stack is: \n");
		while(currentPtr != NULL)
		{
			printf("%c-->",currentPtr->data);
			currentPtr=currentPtr->next;	
		}

	}

}


char isEmpty(StackNodePtr currentPtr)
{
	return currentPtr==NULL;

}


