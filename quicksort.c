/*Description:Implementation of Quick Sort
 * Learner:Shaikh Altamas shakeel
 * Roll no:16co11
 */

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int split(int ar[],int lower,int upper)
{
	int pivot=lower,temp;
	int a=pivot+1;
	int b=upper;
	while(b>=a)
	{
		while(ar[a]<ar[pivot])
			a++;
		while(ar[b]>ar[pivot])
			b--;
		if(b>a)
		{
			temp=ar[a];
			ar[a]=ar[b];
			ar[b]=temp;
		}
	}
	temp=ar[b];
	ar[b]=ar[pivot];
	ar[pivot]=temp;
	return b;
}

void Quick_sort(int a[],int lower,int upper)
{
	int i;
	if(upper>lower)
	{
		i=split(a,lower,upper);
		Quick_sort(a,lower,i-1);
		Quick_sort(a,i+1,upper);
	} 
}

int main()
{
	int a[MAX],i,n;
	printf("\nEnter the no of elements in array: ");
	scanf("%d",&n);
	printf("\nEnter the elements of array\n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter the no: ");
		scanf("%d",&a[i]);
	}
	Quick_sort(a,0,n-1);
	printf("\n----The sorted array is----\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}

/*OUTPUT:
Enter the no of elements in array: 5

Enter the elements of array

Enter the no: 45

Enter the no: 78

Enter the no: 67

Enter the no: 34

Enter the no: 12

----The sorted array is----
12	34	45	67	78	

------------------
(program exited with code: 0)
Press return to continue
*/
