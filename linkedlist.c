/*Description:Implementation of Singly Linked List
 * Learner:Shaikh Altamas shakeel
 * Roll no:16co11
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct linked_list
{
	int data;
	struct linked_list *next;
}node;

void print(node *q)
{
	node *ptr;
	ptr=q;
	printf("\n");
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
}

void insbeg(node **q,int no)
{
	node *temp,*ptr;
	temp=*q;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=no;
	if(temp==NULL)
		ptr->next=NULL;
	else
		ptr->next=temp;
	*q=ptr;
	printf("\nElements of linked list after insertion\n");
	print(*q);
}

void insend(node **q,int no)
{
	node *ptr,*temp;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=no;
	ptr->next=NULL;
	temp=*q;
	if(temp==NULL)
		*q=ptr;
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
			temp->next=ptr;
	}
	printf("\nElements of Linked list after insertion\n");
	print(*q);
}

void insafter(node *q,int no)
{
	int loc,k;
	node *temp,*ptr,*old;
	temp=q;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=no;
	printf("Enter location where the no is to be inserted: ");
	scanf("%d",&loc);
	if(loc==1)
	{
		printf("\nPlease use Insert at the beginning option\n");
	    return;
	}
	for(k=1;k<loc;k++)
	{
		if(temp==NULL)
				printf("\nElements are less than provided location\n");
		else
		{
			old=temp;
			temp=temp->next;
		}
	}
	if(temp==NULL)
	{	
		printf("\nPlease use Insert at the end option\n");
		return;
	}	
	ptr->next=temp;
	old->next=ptr;
	printf("\nElements of linked list after insertion\n");
	print(q);
}

void del(node **q,int no)
{
	int f=0;
	node *old,*temp;
	temp=*q;
	while(temp!=NULL)
	{
		if(temp->data==no)
		{
			f=1;
			if(temp==*q)
				*q=temp->next;
			else
				old->next=temp->next;
			free(temp);
			break;
		}
		else
		{
			old=temp;
			temp=temp->next;
		}
	}
	if(f==0)
		printf("\nThe given no is not found\n");
	printf("\nElements of linked list after deletion\n");
	print(*q);
}

void traverse(node *q)
{
	printf("\nTraversing Linklist\n");
	print(q);
	printf("\nEnd of linked list\n");
}

int main()
{
	node *start,*ptr,*temp;
	int i,n,j,no,c;
	printf("\nEnter the no of nodes: ");
	scanf("%d",&n);
	printf("Enter node number 1: ");
	start=(node*)malloc(sizeof(node));
	scanf("%d",&start->data);
	temp=start;
	for(i=1;i<n;i++)
	{
		ptr=(node*)malloc(sizeof(node));
		printf("\nEnter node number %d: ",i+1);
		scanf("%d",&ptr->data);
		temp->next=ptr;
		temp=ptr;
	}
	temp->next=NULL;
	do
	{
		printf("\nEnter your choice\n");
		printf("\n1-Insertion\n2-Deletion\n3-Traverse\n4-Exit\n\n");
		scanf("%d",&j);
		switch(j)
		{
			case 1:
				printf("\nEnter the number to be inserted: ");
				scanf("%d",&no);
				printf("\nEnter 1 to insert at the beginning\n");
				printf("\nEnter 2 to insert at the end\n");
				printf("\nEnter 3 to insert at a specified location\n");
				scanf("%d",&c);
				switch(c)
				{
					case 1:
						insbeg(&start,no);
						break;
					case 2:
						insend(&start,no);
						break;
					case 3:
						insafter(start,no);
						break;
					default:
						printf("\nInvalid choice.");
						break;
				}
				break;
			case 2:
				printf("\nEnter the number to be deleted: ");
				scanf("%d",&no);
				del(&start,no);
				break;
			case 3:
				traverse(start);
				break;
			case 4:
				exit(0);
			default:
				printf("\nInvalid input.");
				break;
			}
		}while(1);
	return 0;
}

/*OUTPUT:
Enter the no of nodes: 5
Enter node number 1: 11

Enter node number 2: 22

Enter node number 3: 33

Enter node number 4: 44

Enter node number 5: 55

Enter your choice

1-Insertion
2-Deletion
3-Traverse
4-Exit

3

Traversing Linklist

11	22	33	44	55	
End of linked list

Enter your choice

1-Insertion
2-Deletion
3-Traverse
4-Exit

1

Enter the number to be inserted: 66

Enter 1 to insert at the beginning

Enter 2 to insert at the end

Enter 3 to insert at a specified location
2

Elements of Linked list after insertion

11	22	33	44	55	66	
Enter your choice

1-Insertion
2-Deletion
3-Traverse
4-Exit

1

Enter the number to be inserted: 9

Enter 1 to insert at the beginning

Enter 2 to insert at the end

Enter 3 to insert at a specified location
1

Elements of linked list after insertion

9	11	22	33	44	55	66	
Enter your choice

1-Insertion
2-Deletion
3-Traverse
4-Exit

1

Enter the number to be inserted: 25

Enter 1 to insert at the beginning

Enter 2 to insert at the end

Enter 3 to insert at a specified location
3
Enter location where the no is to be inserted: 4

Elements of linked list after insertion

9	11	22	25	33	44	55	66	
Enter your choice

1-Insertion
2-Deletion
3-Traverse
4-Exit

1

Enter the number to be inserted: 69

Enter 1 to insert at the beginning

Enter 2 to insert at the end

Enter 3 to insert at a specified location
3
Enter location where the no is to be inserted: 9

Please use Insert at the end option

Enter your choice

1-Insertion
2-Deletion
3-Traverse
4-Exit

1

Enter the number to be inserted: 5

Enter 1 to insert at the beginning

Enter 2 to insert at the end

Enter 3 to insert at a specified location
3
Enter location where the no is to be inserted: 1

Please use Insert at the beginning option

Enter your choice

1-Insertion
2-Deletion
3-Traverse
4-Exit

2

Enter the number to be deleted: 66

Elements of linked list after deletion

9	11	22	25	33	44	55	
Enter your choice

1-Insertion
2-Deletion
3-Traverse
4-Exit

2

Enter the number to be deleted: 22

Elements of linked list after deletion

9	11	25	33	44	55	
Enter your choice

1-Insertion
2-Deletion
3-Traverse
4-Exit

2

Enter the number to be deleted: 33

Elements of linked list after deletion

9	11	25	44	55	
Enter your choice

1-Insertion
2-Deletion
3-Traverse
4-Exit

2

Enter the number to be deleted: 9

Elements of linked list after deletion

11	25	44	55	
Enter your choice

1-Insertion
2-Deletion
3-Traverse
4-Exit

2

Enter the number to be deleted: 11

Elements of linked list after deletion

25	44	55	
Enter your choice

1-Insertion
2-Deletion
3-Traverse
4-Exit

2

Enter the number to be deleted: 44

Elements of linked list after deletion

25	55	
Enter your choice

1-Insertion
2-Deletion
3-Traverse
4-Exit

2

Enter the number to be deleted: 55

Elements of linked list after deletion

25	
Enter your choice

1-Insertion
2-Deletion
3-Traverse
4-Exit

2

Enter the number to be deleted: 25

Elements of linked list after deletion


Enter your choice

1-Insertion
2-Deletion
3-Traverse
4-Exit

2

Enter the number to be deleted: 1

The given no is not found

Elements of linked list after deletion


Enter your choice

1-Insertion
2-Deletion
3-Traverse
4-Exit

4


------------------
(program exited with code: 0)
Press return to continue
*/
