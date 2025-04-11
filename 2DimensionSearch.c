#include <stdio.h>
#include <time.h>


int main(){
    clock_t start_time = clock(); 
    int row;
    int col;

    printf("enter number of rows and columns for multi-D array: ");
    scanf("%d %d", &row, &col);

    int arr[row][col];
    for(int i=0;i<row;i++){
        printf("enter row %d elements: ", i);
        for(int j=0;j<col;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    int num;
    printf("enter number to be found: ");
    scanf("%d",&num);

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]==num){
                printf("Element found at index (%d,%d)",i,j);
                return 0;
            }
        }
    }

    printf("Element not found");

    clock_t end_time = clock(); 
    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("The program took %f seconds to run.\n", time_spent);

    return 0;


}
