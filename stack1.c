#include<stdio.h>
#include <stdlib.h>

struct list{
int val;
struct list *next;

};

struct list *head=NULL;

int push(int);
int pop();
void display();

void main()
{	
	int ch,data;
	while(1)
	{
		printf("\n1.push.");
		printf("\n2.pop.");
		printf("\n3.display.");
		printf("\n4.exit.");
		printf("\n\nenter choice:");
		scanf(&ch);
		switch(ch)
		{

			case 1: 
				
				printf("\nEnter value to push:");
				scanf("%d",&data);
				push(data);
				display();
				break;

			case 2: pop();
				display();
				break;

			case 3: display();
				break;
			
			case 4: exit(1);
				break;
			default : printf("\nplease enter correct choice.");
		}
	}
		
}

int push(int val)
{
	struct list *temp;
	temp=malloc(sizeof(struct list));
        if (!temp)
        return 0;

	temp->val=val;
	temp->next=head;
	head=temp;
        return 1;

}
int pop(int val)
{
	struct list *temp;
         temp=head;
        if (!temp)
        return 0;
       head=temp->next;
	free(temp);
	printf("\npop operation successfully done.");

}
void display(void)
{
	struct list *temp;
                 temp=head;
		while(temp){
		printf(" %d-->NULL",temp->val);
                 temp=temp->next;
}
	

printf("\n");

}
