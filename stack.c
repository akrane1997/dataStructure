#include <stdio.h>
#include <malloc.h>

/*Self Referential Structure*/

struct list{
	char val;
	struct list *next;
};

struct list *head =NULL;

//int insert_last(int);
char push(char);
char delete_last();
//int pop();
void disp();

void main()
{
      // insert_last(30);
      // insert_last(40);
      // insert_last(50);
      // disp();
       push('a');
       push('b');
       push('c');
       disp();
     // pop();
	//disp();
	//pop();
       //disp();
       delete_last();
	disp();
	delete_last();	
       disp();
       printf("\n");
       

}
char delete_last()
{

 struct list * temp;
 struct list * prev;
	temp=head;
 if(!temp)
 return 0;
 
while(temp->next){
    prev=temp;
    temp=temp->next;
}
prev->next=NULL;
free(temp);
}

int insert_last(int val)
{
	struct list  *new,*temp;
	new=malloc(sizeof(struct list));
	new->val=val;
        new->next =NULL;
	if(!head){
		head =new;
       
	}else{
             temp=head;
		/*traverse end of list*/
	
		while(temp->next)
			temp=temp->next;
		temp->next=new;
	}
	
}

char push(char val)
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
int delete_first(int val)
{
	struct list *temp;
         temp=head;
        if (!temp)
        return 0;
       head=temp->next;
	free(temp);

}
void disp(void)
{
	struct list *temp;
                 temp=head;
		while(temp){
		printf(" %c",temp->val);
                 temp=temp->next;
}
	

printf("\n");

}
