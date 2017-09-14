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
//check if queue is full
	return((rear==MAX_SIZE-1&&front==0)||(rear+1==front));
}

int isEmpty()
{
//check if queue is empty
	return(rear==-1&&front==-1);
}

void display()
{
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
	else
	{
		printf("\nQueue is Empty.");
	}				
}

void insertQueue(int e)
{
	if(!isFull())
	{
		rear=(rear+1)%(MAX_SIZE);
		queue[rear]=e;
		if(front==-1)
			front++;
		printf("\nElement %d is successfully Inserted",e);
		printf("\nfront=%d\trear=%d",front,rear);
	}
	else
	{
		printf("\nThe queue is full..element cannot be inserted\n");
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
		printf("\nThe element deleted is %d\n",d);
		printf("\nfront=%d\trear=%d",front,rear); 
	}
	else
	{
		printf("\nQueue is empty\n");
	}
}

int main(){
	int choice,e;
	do
	{
		printf("\nEnter\n1.display\t2.insert\t3.delete\t4.exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					printf("\nElements of queue are\n");
				    display();
				    break;
			case 2:
					printf("\nEnter the element to be inserted: ");
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
					printf("\nWrong choice\n");
			        break;
		}
	}while(1);
	return 0;
}

