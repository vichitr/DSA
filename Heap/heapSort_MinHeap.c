/*Heap Sort using Min Heap
Coded by Vichitr
vichitrgandas@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>

void heapify(int a[], int n, int i)
{
	int min = i;
	int l = 2*i+1;
	int r = 2*i+2;
	if(l<n && a[l]<a[min])
		min = l;
	if(r<n && a[r]<a[min])
		min = r;
	if(min != i)
	{
		int t = a[i];
		a[i] = a[min];
		a[min] = t;
		
		heapify(a, n, min);
	}
}

void heapSort(int a[], int n)
{
	int i = 0;
	for(i=n/2-1; i>=0; i--)
		heapify(a, n, i);
	for(i=n-1; i>=0; i--)
	{
		int t = a[0];
		a[0] = a[i];
		a[i] = t;
		
		heapify(a, i, 0);
	}
}	

int main()
{
	int n, i;
	printf("Array size: ");
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	printf("Array before heap sort: \n");
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
	heapSort(a, n);
	printf("Array after heap sort: \n");
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
