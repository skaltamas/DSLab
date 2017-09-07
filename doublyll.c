/*Description:Implementation of Doubly Linked List
 * Learner:Shaikh Altamas shakeel
 * Roll no:16co11
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct dlinked_list
{
	int data;
	struct dlinked_list *next;
	struct dlinked_list *prev;
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
	ptr->prev=NULL;
	if(temp==NULL)
		ptr->next=NULL;
	else
	{	
		ptr->next=temp;
		temp->prev=ptr;
	}
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
	{	
		*q=ptr;
		ptr->prev=NULL;
	}
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=ptr;
		ptr->prev=temp;
	}
	printf("\nElements of Linked list after insertion\n");
	print(*q);
}

void insafter(node *q,int no)
{
	int loc,k;
	node *temp,*ptr;
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
			temp=temp->next;
		}
	}
	if(temp==NULL)
	{	
		printf("\nPlease use Insert at the end option\n");
		return;
	}	
	temp->prev->next=ptr;
	ptr->prev=temp->prev;
	ptr->next=temp;
	temp->prev=ptr;
	printf("\nElements of linked list after insertion\n");
	print(q);
}

void del(node **q,int no)
{
	int f=0;
	node *temp;
	temp=*q;
	while(temp!=NULL)
	{
		if(temp->data==no)
		{
			f=1;
			if(temp==*q)
			{
				*q=temp->next;
				if(temp->next!=NULL)
					temp->next->prev=NULL;
			}
			else
			{
				temp->prev->next=temp->next;
				if(temp->next!=NULL)
					temp->next->prev=temp->prev;
			}
			free(temp);
			break;
		}
		else
		{
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
	if(n<1)
	{
		printf("\nInvalid number of nodes\n");
		return 0;
	}
	printf("Enter node number 1: ");
	start=(node*)malloc(sizeof(node));
	scanf("%d",&start->data);
	start->prev=NULL;
	temp=start;
	for(i=1;i<n;i++)
	{
		ptr=(node*)malloc(sizeof(node));
		printf("\nEnter node number %d: ",i+1);
		scanf("%d",&ptr->data);
		temp->next=ptr;
		ptr->prev=temp;
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

