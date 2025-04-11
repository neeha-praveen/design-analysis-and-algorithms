#include <stdio.h>

int compare(int x, int y) {
    if (x < y) return -1;
    else if (x == y) return 0;
    else return 1;
}

int binsearch(int list[], int searchnum, int left, int right) {
    int middle;
    while (left <= right) {
        middle = (left + right) / 2;
        switch (compare(list[middle], searchnum)) {
            case -1:
                return binsearch(list, searchnum, middle+1,right);
            case 0:
                return middle;
            case 1:
                return binsearch(list, searchnum, left, middle-1);
                break;
        }
    }
    return -1;
}

int main() {
    int size;
    printf("enter size of array: ");
    scanf("%d",&size);

    int arr[size];
    printf("input array elements in sorted manner: ");
    for(int i =0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    //int list[] = {1, 3, 5, 7, 8, 9, 11, 13};
    //int n = sizeof(list) / sizeof(list[0]); 
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
