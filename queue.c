/*Description:Array implementation of Queue
 * Learner:Shaikh Altamas shakeel
 * Roll no:16co11
 */
#include<stdio.h>
#define MAX_SIZE 10

int queue[MAX_SIZE],front=-1,rear=-1;

int isFull()
{
//check if queue is full
	return rear==MAX_SIZE-1;
}

int isEmpty(){
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
		printf("\nElement %d is successfully Inserted\n",d);
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
		printf("\nThe element deleted is %d\n",d);
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
		printf("Enter your choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					display();
					break;
			case 2:
					printf("\nEnter the element to be inserted :");
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
Enter your choice :2

Enter the element to be inserted :10

Element 10 is successfully Inserted

Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :2

Enter the element to be inserted :20

Element 20 is successfully Inserted

Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :2

Enter the element to be inserted :30

Element 30 is successfully Inserted

Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :2

Enter the element to be inserted :40

Element 40 is successfully Inserted

Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :2

Enter the element to be inserted :50

Element 50 is successfully Inserted

Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :2

Enter the element to be inserted :60

Element 60 is successfully Inserted

Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :2

Enter the element to be inserted :70

Element 70 is successfully Inserted

Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :2

Enter the element to be inserted :80

Element 80 is successfully Inserted

Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :2

Enter the element to be inserted :90

Element 90 is successfully Inserted

Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :2

Enter the element to be inserted :100

Element 100 is successfully Inserted

Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :2

Enter the element to be inserted :110

Queue is Full Element cannot be inserted.
Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :1

10	20	30	40	50	60	70	80	90	100	
Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :3

The element deleted is 10

Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :3

The element deleted is 20

Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :3

The element deleted is 30

Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :3

The element deleted is 40

Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :3

The element deleted is 50

Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :3

The element deleted is 60

Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :3

The element deleted is 70

Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :3

The element deleted is 80

Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :3

The element deleted is 90

Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :3

The element deleted is 100

Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :3

Queue is empty

Enter
1.display	2.insert	3.delete	4.exit
Enter your choice :4


------------------
(program exited with code: 0)
Press return to continue
*/
