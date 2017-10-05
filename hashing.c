/*Description:Implementation of Hashing
 * Learner:Shaikh Altamas shakeel
 * Roll no:16co11
 */

#include<stdio.h>
#define MAX_SIZE 15

int hash(int k)
{
	return k%MAX_SIZE;
}

int linear_probe(int h)
{
	return ++h%MAX_SIZE;
}

int quad_probe(int h,int i)
{
	return (h+(i*i))%MAX_SIZE;
}

int double_hash(int h,int i)
{
	return (h+i*linear_probe(h))%MAX_SIZE;
}

void display(int a[])
{
	int i;
	printf("\n----Elements of array are----\n");
	for(i=0;i<MAX_SIZE;i++)
		printf("%d\t",a[i]);
}

int main()
{
	int a[MAX_SIZE],i,h,e,count,choice;
	for(i=0;i<MAX_SIZE;i++)
		a[i]=-1;
	do{
		count=0;
		printf("\nEnter the number to be stored: ");
		scanf("%d",&e);
		h=hash(e);
		if(a[h]==-1)
		{
			a[h]=e;
			display(a);
		}
		else
		{
			while(count<MAX_SIZE)
			{
				count++;
				printf("\nCollision occured at %d\n",h);
				printf("\nEnter\n1.Linear probe\t2.Quadratic probe\t3.Double Hashing\n");
				printf("\nEnter your choice for resolution: ");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1:h=linear_probe(h);
						break;
					case 2:h=quad_probe(h,count);
						break;
					case 3:h=double_hash(h,count);
						break;
					default:printf("\nInvalid choice");
							count--;
						break;
				}
				if(a[h]==-1)
				{
					a[h]=e;
					display(a);
					break;
				}
			}
		}
		if(count==MAX_SIZE)
		{
			printf("\nArray is full/resolution not successful...Could not store more elements\n");
			return 0;
		}
	}while(1);
}

/*OUTPUT:
Enter the number to be stored: 11

----Elements of array are----
-1	-1	-1	-1	-1	-1	-1	-1	-1	-1	-1	11	-1	-1	-1	
Enter the number to be stored: 22

----Elements of array are----
-1	-1	-1	-1	-1	-1	-1	22	-1	-1	-1	11	-1	-1	-1	
Enter the number to be stored: 33

----Elements of array are----
-1	-1	-1	33	-1	-1	-1	22	-1	-1	-1	11	-1	-1	-1	
Enter the number to be stored: 44

----Elements of array are----
-1	-1	-1	33	-1	-1	-1	22	-1	-1	-1	11	-1	-1	44	
Enter the number to be stored: 55

----Elements of array are----
-1	-1	-1	33	-1	-1	-1	22	-1	-1	55	11	-1	-1	44	
Enter the number to be stored: 66

----Elements of array are----
-1	-1	-1	33	-1	-1	66	22	-1	-1	55	11	-1	-1	44	
Enter the number to be stored: 77

----Elements of array are----
-1	-1	77	33	-1	-1	66	22	-1	-1	55	11	-1	-1	44	
Enter the number to be stored: 88

----Elements of array are----
-1	-1	77	33	-1	-1	66	22	-1	-1	55	11	-1	88	44	
Enter the number to be stored: 99

----Elements of array are----
-1	-1	77	33	-1	-1	66	22	-1	99	55	11	-1	88	44	
Enter the number to be stored: 12

----Elements of array are----
-1	-1	77	33	-1	-1	66	22	-1	99	55	11	12	88	44	
Enter the number to be stored: 24

Collision occured at 9

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 1

Collision occured at 10

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 1

Collision occured at 11

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 1

Collision occured at 12

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 1

Collision occured at 13

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 1

Collision occured at 14

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 1

----Elements of array are----
24	-1	77	33	-1	-1	66	22	-1	99	55	11	12	88	44	
Enter the number to be stored: 36

Collision occured at 6

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 2

Collision occured at 7

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 2

Collision occured at 11

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 2

----Elements of array are----
24	-1	77	33	-1	36	66	22	-1	99	55	11	12	88	44	
Enter the number to be stored: 48

Collision occured at 3

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 3

Collision occured at 7

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 3

----Elements of array are----
24	-1	77	33	-1	36	66	22	48	99	55	11	12	88	44	
Enter the number to be stored: 51

Collision occured at 6

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 1

Collision occured at 7

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 1

Collision occured at 8

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 1

Collision occured at 9

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 1

Collision occured at 10

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 1

Collision occured at 11

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 1

Collision occured at 12

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 1

Collision occured at 13

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 1

Collision occured at 14

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 1

Collision occured at 0

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 1

----Elements of array are----
24	51	77	33	-1	36	66	22	48	99	55	11	12	88	44	
Enter the number to be stored: 69

Collision occured at 9

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 2

Collision occured at 10

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 2

Collision occured at 14

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 2

Collision occured at 8

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 2

Collision occured at 9

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 2

----Elements of array are----
24	51	77	33	69	36	66	22	48	99	55	11	12	88	44	
Enter the number to be stored: 74

Collision occured at 14

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 2

Collision occured at 0

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 2

Collision occured at 4

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 2

Collision occured at 13

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 2

Collision occured at 14

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 2

Collision occured at 9

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 2

Collision occured at 0

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 2

Collision occured at 4

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 2

Collision occured at 8

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 2

Collision occured at 14

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 2

Collision occured at 9

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 3

Collision occured at 14

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 3

Collision occured at 14

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 3

Collision occured at 14

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 2

Collision occured at 0

Enter
1.Linear probe	2.Quadratic probe	3.Double Hashing

Enter your choice for resolution: 3

Array is full/resolution not successful...Could not store more elements


------------------
(program exited with code: 0)
Press return to continue
*/
