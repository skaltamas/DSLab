/*Description:Array implementation of Queue
 * Learner:Shaikh Altamas shakeel
 * Roll no:16co11
 */
#include<stdio.h>
#define MAX_SIZE 10

int queue[MAX_SIZE],front=-1,rear=-1;

void isFull()
{
//check if queue is full
	return rear==MAX_SIZE-1;
}

void isEmpty(){
//check if queue is empty
	return front==-1&&rear==-1;

}

void display()
{
	int i;
	if(!isEmpty())
		for(i=front;i<=rear;i++)
			printf("%d\t",queue[i]);
	else{
		printf("\nQueue is Empty");
	}	
			
}

void insertQueue(int d)
{
	if(!isFull())
	{
		queue[++rear]=d;
		if(front==-1)
			front++;
		printf("\nElement %d is successfully Inserted",d);
	}
	else
		printf("\nQueue is Full Element cannot be inserted.");	
}

void deleteQueue()
{
	int d;
	if(!isEmpty())
	{
		d=queue[front];
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			front++;
		}
		printf("The element deleted is %d\n",d);
	}
	else
	{
		printf("Queue is empty\n");
	}
}

int main(){
	int choice,e;
	do
	{
		printf("\nEnter\n1.display\t2.insert\t3.delete\t4.exit\n");
		printf("Enter your choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					display();
					break;
			case 2:
					printf("Enter the element to be inserted :");
					scanf("%d",&e);
					insertQueue(e);
					break;
			case 3:
					deleteQueue();
					break;
			case 4:	
					return 0;
					break;
			default:
					printf("Wrong choice\n");
					break;
		}
	}while(1);
	return 0;
}
