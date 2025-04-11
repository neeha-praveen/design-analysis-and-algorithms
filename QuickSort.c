#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int arr[], int low, int high){
    if (low < high) {
        // Partition the array
        int pivot = arr[high]; 
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                // swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // Place pivot in the correct position
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;  // Pivot index

        // Recursively sort the two subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    clock_t start_time = clock(); 
    int size;
    printf("enter size of array: ");
    scanf("%d",&size);

    int arr[size];

    for(int i =0;i<size;i++){
        arr[i] = rand() % 10000;
    }

    printf("Unsorted array:\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr,0,size-1);

    printf("Sorted array:\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    clock_t end_time = clock(); 
    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("The program took %f seconds to run.\n", time_spent);
}