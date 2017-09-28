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
		printf("\nElement %d is successfully inserted\n",e);
	}
	else{
		printf("\nElement cannot be inserted..Stack overflow !\n");
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
		printf("\nElement %d is successively deleted\n",d);
	}
	else{
		printf("\nStack underflow !\n");
	}
}

int main(){
	int choice,e;
	do
	{
		printf("\nEnter\n1.peek\t2.push\t3.pop\t4.exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:e=peek();
				printf("\nElement at the top of the stack= %d\n",e);
				break;
			case 2:printf("\nEnter the element to be inserted: ");
				scanf("%d",&e);
				push(e);
				break;
			case 3:pop();
				break;
			case 4:
					exit(0);
				break;
			default:printf("\nWrong choice\n");
				break;
		}
	}while(1);
	return 0;
}

/*OUTPUT:			
Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 2

Enter the element to be inserted: 10

Element 10 is successfully inserted

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 2

Enter the element to be inserted: 20

Element 20 is successfully inserted

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 2

Enter the element to be inserted: 30

Element 30 is successfully inserted

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 2

Enter the element to be inserted: 40

Element 40 is successfully inserted

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 2

Enter the element to be inserted: 50

Element 50 is successfully inserted

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 2

Enter the element to be inserted: 60

Element 60 is successfully inserted

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 2

Enter the element to be inserted: 70

Element 70 is successfully inserted

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 2

Enter the element to be inserted: 80

Element 80 is successfully inserted

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 2

Enter the element to be inserted: 90

Element 90 is successfully inserted

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 2

Enter the element to be inserted: 100

Element 100 is successfully inserted

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 2

Enter the element to be inserted: 110

Element cannot be inserted..Stack overflow !

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 1

Element at the top of the stack= 100

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 3

Element 100 is successively deleted

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 3

Element 90 is successively deleted

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 3

Element 80 is successively deleted

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 3

Element 70 is successively deleted

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 3

Element 60 is successively deleted

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 3

Element 50 is successively deleted

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 3

Element 40 is successively deleted

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 3

Element 30 is successively deleted

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 3

Element 20 is successively deleted

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 3

Element 10 is successively deleted

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 3

Stack underflow !

Enter
1.peek	2.push	3.pop	4.exit

Enter your choice: 4


------------------
(program exited with code: 0)
Press return to continue
*/
