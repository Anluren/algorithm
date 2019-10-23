#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */

void swap(int arr[], int i1, int i2) {
    int temp;
    temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}
int partition (int arr[], int low, int high)
{
   int pivot;
   int i, j;
   pivot = arr[high];

   i = low-1;
   for (j = low; j < high; j++) {
       if (arr[j] < pivot) {
           i ++;
           swap(arr, i, j);
       } 
   }
   swap(arr, i + 1, high); 
   return i + 1;
}

void quick_sort_internal(int arr[], int low, int high)
{
    int pi;  /* pivot index */
    if (low < high) {
         pi = partition(arr, low, high);
         
         /* sort data on left side of pivot */
         quick_sort_internal(arr, low, pi -1);
         quick_sort_internal(arr, pi + 1, high);
    }
}

void quick_sort(int arr[], int size)
{
    quick_sort_internal(arr, 0, size-1);
}

void gen_rand_array(int arr[], int size)
{
    int i;
    for (i=0;i<size;i++) {
       arr[i] = rand()%size;
    }
}

void print_array(int arr[], int size) 
{
    int i;
    for (i = 0; i< (size -1); i++) {
         printf("%d ", arr[i]);
    }
    printf("%d\n", arr[size-1]);
}

int main()
{
    int arr[20];
    time_t t;
 /* Intializes random number generator */
   srand((unsigned) time(&t));

    gen_rand_array(arr, 20);
    print_array(arr, 20);
    quick_sort(arr, 20);
    print_array(arr, 20);
    return 0;
}
