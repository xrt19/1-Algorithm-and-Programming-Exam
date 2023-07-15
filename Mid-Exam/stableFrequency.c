#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char chr;
    int quantity;
} Variation;

void mergeString(char *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    char L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortString(char* arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSortString(arr, l, m);
        mergeSortString(arr, m + 1, r);

        mergeString(arr, l, m, r);
    }
}

void mergeInt(Variation* arr, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Variation L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i].quantity <= R[j].quantity)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortInt(Variation* arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSortInt(arr, left, mid);
        mergeSortInt(arr, mid + 1, right);

        mergeInt(arr, left, mid, right);
    }
}

void stabilize(char* str1)
{
    // 1. Calculate the length of the string
    int lenStr = strlen(str1);
    
    // 2. Sort the string using merge sort
    mergeSortString(str1, 0, lenStr - 1);
    
    // 3. Check how many variations of the substance
    Variation data[lenStr];
    
    int distinct = 0;
    for(int i = 0 ; i < lenStr ; i++)
        if (str1[i] != str1[i + 1])
        {
            data[distinct].chr = str1[i];
            distinct++;
        }
    
    // 4. Initialize the 'quantity' in the 'data' to zero
    for(int i = 0 ; i < distinct ; i++)
        data[i].quantity = 0;
    
    // 5. Count the frequency of each variation.
    for(int i = 0 ; i < distinct ; i++)
        for (int j = 0 ; j < lenStr ; j++)
            if (data[i].chr == str1[j])
                data[i].quantity += 1;
    
    // 6. Sorting with merge sort based on quantity
    mergeSortInt(data, 0, distinct - 1);
    
     // 7. Check how many substances have the same quantity
    int uniqueQuantity = 0;
    for(int i = 0 ; i < distinct - 1 ; i++)
        if (data[i].quantity != data[i + 1].quantity)
            uniqueQuantity++;
    
    // 8. If the condition is impossible to stabilize
    if (uniqueQuantity > 1)
    {
        puts("N/A");
        return;
    }
    
    // 9. If the condition has the probability to be stabilized
    // 10. Limit to a maximum of two types of substance and assign them in finalData
    Variation finalData[2];
    for(int i = 0 ; i < distinct - 1 ; i++)
        if (data[i].quantity != data[i + 1].quantity)
        {
            finalData[0] = data[i];
            finalData[1] = data[i + 1];
        }
    
    // 11. Find how many finalData have the same quantity
    int totalFinalData1 = 0, totalFinalData2 = 0;
    for(int i = 0 ; i < distinct ; i++)
    {
        if (data[i].quantity == finalData[0].quantity)
            totalFinalData1++;
        else if (data[i].quantity == finalData[1].quantity)
            totalFinalData2++;
    }
    
    // 12. If one of the finalData that has the same quantity is only one, it can be stabilized
    if (totalFinalData1 == 1 || totalFinalData2 == 1)
    {
        int finalDel;
        if (totalFinalData1 == 1)
            finalDel = finalData[0].quantity;
        else
            finalDel = finalData[1].quantity;
        
        for(int i = 0 ; i < distinct ; i++)
            if (data[i].quantity == finalDel)
            {
                printf("%c\n", data[i].chr);
                return;
            }
    }
    
    // 13. If the finalData quantity is more than one, it can't be stabilized.
    puts("N/A");
}

int main(void)
{
    char str1[101][50];
    // From sample input in the case
    strcpy(str1[0], "a");
    strcpy(str1[1], "bc");
    strcpy(str1[2], "deeffdfdd");
    strcpy(str1[3], "xyxxyzy");
    strcpy(str1[4], "ggghhhhiiijjj");
    strcpy(str1[5], "cddczzdd");
    strcpy(str1[6], "ababbaccc");
    strcpy(str1[7], "veeavaeaveev");
    strcpy(str1[8], "cecdcddexe");
    
    puts("Test With Sample Input One");
    for (int i = 0 ;  i < 6 ; i++)
    {
        printf("%d. ", i + 1);
        stabilize(str1[i]);
    }
    
    puts("\nTest With Sample Input Two");
    for (int i = 6 ;  i < 9 ; i++)
    {
        printf("%d. ", i - 5);
        stabilize(str1[i]);
    }
    return 0;
}
