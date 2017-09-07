/*Description:Array implementation of stack
 * Learner:Shaikh Altamas shakeel
 * Roll no:16co11
 */
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

int stack[MAX_SIZE],top=-1;
int isFull(){
//returns 1 if stack is full else returns -1
	return top==MAX_SIZE-1;
}

int isEmpty(){
//returns 1 if stack is empty else returns -1
	return top==-1;
}

int peek(){
	return stack[top];
//return element at the top of stack
}

void  push(int e){
	if(!isFull())
	{
		top++;//increment at the top
		stack[top]=e;
		printf("Element %d is successfully inserted\n",e);
	}
	else{
		printf("Element cannot be inserted..Stack overflow !\n");
	}
//inserts an element into stack
}

void pop(){
//deletes an element from top of stack
	int d;
	if(!isEmpty())
	{
		d=stack[top];
		top--;
		printf("Element %d is successively deleted\n",d);
	}
	else{
		printf("Stack underflow !\n");
	}
}

int main(){
	int choice,e;
	do
	{
		printf("Enter\n1.peek\t2.push\t3.pop\t4.exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:e=peek();
				printf("Element at the top of the stack= %d",e);
				break;
			case 2:printf("Enter the element to be inserted :");
				scanf("%d",&e);
				push(e);
				break;
			case 3:pop();
				break;
			case 4:
					exit(0);
				break;
			default:printf("Wrong choice");
				break;
		}
	}while(1);
	return 0;
}
			
		
