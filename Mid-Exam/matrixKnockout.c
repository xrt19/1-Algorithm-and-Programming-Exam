#include <stdio.h>

int main(void)
{
    // 1. input size
    int size1; scanf("%d", &size1);
    
    // 2. Set the size of a two-dimensional array with the inputted size
    int data[size1][size1];
    
    // 3. Input data into the matrix
    // 4. Find the maximum number in the matrix
    // 5. Find the column and row that correspond to the maximum value in the matrix
    int max1 = 0, row = 0, column = 0;
    for (int i = 0 ; i < size1 ; i++)
        for (int j = 0 ; j < size1 ; j++)
        {
            scanf("%d", &data[i][j]);
            if (data[i][j] > max1)
            {
                max1 = data[i][j];
                row = i;
                column = j;
            }
                
        }
         
    // 6. Print the data in the matrix that are not positioned in the row or column with the maximum value in the matrix
    printf("ans: ");
    for (int i = 0 ; i < size1 ; i++)
        for (int j = 0 ; j < size1 ; j++)
            if (i != row && j != column)
                printf("%d ", data[i][j]);
    puts("");
    
    // Successfully tested with the sample input provided
    //3
    //5489 8443 5449 5929 6028 8473 7152 8580 4237
    return 0;
}

