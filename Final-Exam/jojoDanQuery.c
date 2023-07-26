#include <stdio.h>

int binarySearch(int *data, int search, int low, int high)
{
  if (high >= low)
  {
    int mid = low + (high - low) / 2;

    // If found at middle, then return it
    if (data[mid] == search)
      return mid;
    
    // If NOT found, check two condition:
      
    // Search the left half
    if (data[mid] > search)
      return binarySearch(data, search, low, mid - 1);

    // Search the right half
    return binarySearch(data, search, mid + 1, high);
  }

  return -1;
}

int main(void)
{
    int totalNumber, totalQuery;
    scanf("%d %d", &totalNumber, &totalQuery);
    
    int bigData[totalNumber], dataQuery[totalQuery];
    
    // Input into big data
    for (int i = 0 ; i < totalNumber ; i++)
        scanf("%d", &bigData[i]);
    
    // Input into data query
    for (int i = 0 ; i < totalQuery ; i++)
        scanf("%d", &dataQuery[i]);
    
    puts("\n=====\n");
    
    // Print the index as a regular number, not using the programming term 'index'
    for (int i = 0 ; i < totalQuery ; i++)
    {
        int result = binarySearch(bigData, dataQuery[i], 0, totalNumber);
        
        if (result == -1)
            printf("-1\n");
        else
            printf("%d\n", result + 1);
    }
    puts("");
    
    /*
     Sample Input
     
     5 4
     3 5 9 11 14
     9
     7
     3
     14
     */
            
    return 0;
}
