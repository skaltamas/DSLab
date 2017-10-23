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

/*OUTPUT:
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 2

Enter the element to be inserted: 10

Element 10 is successfully Inserted
front=0	rear=0
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 2

Enter the element to be inserted: 20

Element 20 is successfully Inserted
front=0	rear=1
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 2

Enter the element to be inserted: 30

Element 30 is successfully Inserted
front=0	rear=2
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 2

Enter the element to be inserted: 40

Element 40 is successfully Inserted
front=0	rear=3
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 2

Enter the element to be inserted: 50

Element 50 is successfully Inserted
front=0	rear=4
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 2

Enter the element to be inserted: 60

Element 60 is successfully Inserted
front=0	rear=5
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 2

Enter the element to be inserted: 70

Element 70 is successfully Inserted
front=0	rear=6
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 2

Enter the element to be inserted: 80

Element 80 is successfully Inserted
front=0	rear=7
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 2

Enter the element to be inserted: 90

Element 90 is successfully Inserted
front=0	rear=8
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 2

Enter the element to be inserted: 100

Element 100 is successfully Inserted
front=0	rear=9
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 2

Enter the element to be inserted: 110

The queue is full..element cannot be inserted

Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 1

Elements of queue are
10	20	30	40	50	60	70	80	90	100	
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 3

The element deleted is 10

front=1	rear=9
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 3

The element deleted is 20

front=2	rear=9
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 3

The element deleted is 30

front=3	rear=9
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 3

The element deleted is 40

front=4	rear=9
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 3

The element deleted is 50

front=5	rear=9
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 3

The element deleted is 60

front=6	rear=9
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 3

The element deleted is 70

front=7	rear=9
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 3

The element deleted is 80

front=8	rear=9
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 3

The element deleted is 90

front=9	rear=9
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 3

The element deleted is 100

front=-1	rear=-1
Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 3

Queue is empty

Enter
1.display	2.insert	3.delete	4.exit

Enter your choice: 4


------------------
(program exited with code: 0)
Press return to continue
*/
