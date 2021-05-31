#include <stdio.h>
#include<time.h>
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
int pp(int array[], int low, int high) {

  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void qs(int array[], int low, int high) {
  if (low < high) {
    int pi = pp(array, low, high);
    qs(array, low, pi - 1);
    qs(array, pi + 1, high);
  }
}
int main() {
  int arr[30000];
  int N;
  time_t start, end;
  printf("Enter size of array(less than 25000):\n");
  scanf("%d",&N);
  printf("Enter elements of the array:\n");
   for (int i = 0; i < N; i++)
 {
        arr[i]=rand()%25000; 
  }
  	  printf("Array before sorting: \n");
    for (int i = 0; i < N; i++) {
    printf("%d  ", arr[i]);
  }
    start = time(NULL);
    
  qs(arr, 0, N - 1);
  
    end = time(NULL);
    
    printf("Time taken is %.8f seconds",
           difftime(end, start));
  printf("Sorted array in ascending order: \n");
    for (int i = 0; i < N; i++) {
    printf("%d  ", arr[i]);
  }
  printf("\n");
}
