#include <stdio.h>

int compare(int x, int y) {
    if (x < y) return -1;
    else if (x == y) return 0;
    else return 1;
}

typedef struct {
    int value;
    int ogindex;
}Element;


void bubbleSort(Element arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // After each pass, the largest element bubbles to the end
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the current element is greater than the next
            if (arr[j].value > arr[j + 1].value) {
                // Swapping
                Element temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int binsearch(Element list[], int searchnum, int left, int right) {
    int middle;
    while (left <= right) {
        middle = (left + right) / 2;
        switch (compare(list[middle].value, searchnum)) {
            case -1:
                left = middle + 1;
                break;
            case 0:
                return list[middle].ogindex;
            case 1:
                right = middle - 1;
                break;
        }
    }
    return -1;
}

int main() {
    int size;
    printf("enter size of array: ");
    scanf("%d",&size);

    Element arr[size];
    printf("input array elements: ");
    for(int i =0;i<size;i++){
        scanf("%d",&arr[i].value);
        arr[i].ogindex=i;
    }

    bubbleSort(arr,size);

    int num;

    printf("Enter number to be searched: ");
    scanf("%d", &num);

    int result = binsearch(arr, num, 0, size - 1);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
    return 0;
}
