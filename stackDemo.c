#include<stdio.h>
#include<stdlib.h>

struct stackNode
{
	int data;
	struct stackNode *next; 


};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

int push( StackNodePtr*,int );
int pop( StackNodePtr* );
int isEmpty( StackNodePtr );
void instruction( void );
void printStack( StackNodePtr );
void popAll( StackNodePtr );

int main()
{
	StackNodePtr StackPtr=NULL;
	int choice,val;
	instruction();
	printf( "\nEnter choice Number:" );
	scanf( "%d",&choice );
	while( choice!=4 )
	{
		switch(choice)
		{
			case 1:printf("\nEnter value fot push into stack: ");
				scanf("%d",&val);
				push(&StackPtr,val);
				printStack( StackPtr );
				break;
	
			case 2: if(!isEmpty(StackPtr))
					printf("\npoped value is: %d",pop( &StackPtr ));
				printStack( StackPtr );
				break;
			case 3: popAll( StackPtr );
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
		"\n 1. to push a value on the stack."
		"\n 2. to pop a value on the stack. " 
		"\n 3. to pop All value on stack."
		"\n 4. Exit from program." );


}

int push(StackNodePtr *headPtr,int data)
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

int pop(StackNodePtr *topPtr)
{
	StackNodePtr tempPtr;
	int popValue;
	
	tempPtr=*topPtr;
	popValue=( *topPtr )->data;
	*topPtr=( *topPtr )->next;
	free(tempPtr);
	
	return popValue;

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
			printf("%d-->",currentPtr->data);
			currentPtr=currentPtr->next;	
		}

	}

}

int isEmpty(StackNodePtr currentPtr)
{
	return currentPtr==NULL;

}

void popAll(StackNodePtr topPtr)
{
	StackNodePtr tempPtr,q;
	//int popValue;
	
	tempPtr=topPtr;
	while(tempPtr!=NULL)
	{
	//popValue=( *topPtr )->data;
		
		if(tempPtr != NULL)
		{	
			
			q=tempPtr->next;
			free(q);
				
		}
		tempPtr=tempPtr->next;
		
	}
	free(tempPtr);
	printf("\nstack is Empty.");

}
























