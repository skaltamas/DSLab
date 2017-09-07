/*Description:Array implementation of Circular Queue
 * Learner:Shaikh Altamas shakeel
 * Roll no:16co11
 */
#include<stdio.h>
#include<math.h>
#define MAX_SIZE 10

int queue[MAX_SIZE],rear=-1,front=-1;
int isFull()
{
//returns 1 if queue is full else returns -1
	if((rear==MAX_SIZE-1&&front==0)||(rear+1==front))
		return 1;
	else 
		return 0;
}

int isEmpty(){
//returns 1 if queue is empty else returns -1
	if(rear==-1&&front==-1)
		return 1;
	else
		return 0;
}

int display(){
	int i=front;
	if(!isEmpty())
	{
		while(i!=rear)
		{
			printf("%d\t",queue[i]);
			i=(i+1)%MAX_SIZE;
		}
		printf("%d\t",queue[i]);
	}
	else{
		printf("\nQueue is Empty.");
	}	
			
}
//return element at the front of queue
}

void insertQueue(int d)
{
	if(!isFull())
	{
		if(isEmpty())
		{
			front++;
		}
		rear=(rear+1)%(MAX_SIZE);
		queue[rear]=d;
		printf("%d element is successfully inserted\n",d);
	}
	else
	{
		printf("The queue is full..element cannot be inserted\n");
	}
}

void deleteQueue()
{
	if(!isEmpty())
	{
		int d=queue[front];
		if(front==rear)
		{
		front=rear=-1;
		}
		else
		{
		front=(front+1)%(MAX_SIZE);
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
			case 1:if(isEmpty())
					{
					printf("Queue is empty\n");
					}
					else
					{
					e=display();
					printf("Element at the front of the queue= %d\n",e);
					}
			break;
			case 2:printf("Enter the element to be inserted :");
				scanf("%d",&e);
				insertQueue(e);
			break;
			case 3:deleteQueue();
			break;
			case 4:
					return 0;
			break;
			default:printf("Wrong choice\n");
			break;
		}
	}while(1);
	return 0;
}

