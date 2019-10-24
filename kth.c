#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int arr[], int i1, int i2) {
    int temp;
    temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
   int pivot;
   int i, j;
   pivot = arr[high];

   i = low;
   for (j = low; j < high; j++) {
       if (arr[j] > pivot) {
           swap(arr, i, j);
           i ++;
       } 
   }
   swap(arr, i, high); 
   return i;
}

int quick_sort_internal(int arr[], int low, int high, int k)
{
    int pi;  /* pivot index */
    if (low < high) {
        pi = partition(arr, low, high);
        if (pi == k)
            return pi;

        if (pi > k)
            pi = quick_sort_internal(arr, low, pi -1, k);
        else 
            pi = quick_sort_internal(arr, pi + 1, high, k);
        if (pi == k)
            return pi;
    }
    return -1;
}

int findKthLargest(int* nums, int numsSize, int k)
{
    quick_sort_internal(nums, 0, numsSize-1, k-1);
    return nums[k-1];
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
    int k, kth_val;
 /* Intializes random number generator */
   srand((unsigned) time(&t));

    gen_rand_array(arr, 20);
    print_array(arr, 20);
    k = 5;
    kth_val = findKthLargest(arr, 20, 5);
    print_array(arr, 20);
    printf("%dth value: %d\n", k, kth_val);
    return 0;
}
