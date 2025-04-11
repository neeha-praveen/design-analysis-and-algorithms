#include <stdio.h>
#include <time.h>

int main() {
    clock_t start_time = clock(); 
    int size;
    printf("enter size of array: ");
    scanf("%d",&size);

    int arr[size];

    printf("enter array element: ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    int x;
    int flag=0;
    printf("element to be found: ");
    scanf("%d", &x);

    for(int j=0;j<size;j++){
        if(x==arr[j]){
            flag=1;
            break;
        }
    }

    if(flag==0){
        printf("%d not found in array",x);
    }
    else {
        printf("%d is found",x);
    }

    clock_t end_time = clock(); 
    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("The program took %f seconds to run.\n", time_spent);

}