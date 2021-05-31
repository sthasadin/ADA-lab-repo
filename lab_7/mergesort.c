#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void delay(int number_of_seconds)
{

    int milli_seconds = 1000 * number_of_seconds;

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds)
        ;
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0; 
	j = 0;
	k = l; 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r) {

		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}


int main()
{
int arr[25000],n,i;
time_t start, end;
printf("enter array size:"/n)
  scanf("%d",&n);
   for(i=0;i<n;i++)
    {
    arr[i]=rand(); 
    }
    printf("Given array is \n");
	printArray(arr, n);
	
    start = time(NULL);
    
	mergeSort(arr, 0, n-1);

    end = time(NULL);
    
    printf("Time taken is %.8f seconds",
           difftime(end, start));

	printf("\nSorted array is \n");
	printArray(arr, n);
	return 0;
}

