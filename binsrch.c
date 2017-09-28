/*Description:Implementation of Binary Search
 * Learner:Shaikh Altamas shakeel
 * Roll no:16co11
 */

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int binary_search(int a[],int n,int x)
{
	int mid=n/2;
	int high=n-1;
	int low=0;
	while(high>=low)
	{
		if(a[mid]==x)
			return mid;
		if(x>a[mid])
			low=mid+1;
		else
			high=mid-1;
		mid=(low+high)/2;
	}
	return -1;
}

int main()
{
	int a[MAX],i,x,n,index;
	printf("\nEnter the no of elements in array: ");
	scanf("%d",&n);
	printf("\nEnter the elements of array in ascending order\n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter the no: ");
		scanf("%d",&a[i]);
	}
	printf("\nEnter the element to be searched: ");
	scanf("%d",&x);
	index=binary_search(a,n,x);
	if(index==-1)
		printf("\nElement %d is not found\n",x);
	else
		printf("The element %d is at index %d",x,index);
	return 0;
}

/*OUTPUT:
Enter the no of elements in array: 7

Enter the elements of array in ascending order

Enter the no: 3

Enter the no: 5

Enter the no: 7

Enter the no: 8

Enter the no: 9

Enter the no: 13

Enter the no: 17

Enter the element to be searched: 9
The element 9 is at index 4

------------------
(program exited with code: 0)
Press return to continue
*/	
