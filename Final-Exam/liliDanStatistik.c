#include <stdio.h>

typedef struct
{
    int number;
    int frequency;
} NewData;

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int *array, int low, int high)
{
  
  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j < high; j++)
    if (array[j] <= pivot)
    {
      i++;
      swap(&array[i], &array[j]);
    }
  swap(&array[i + 1], &array[high]);
  
  return (i + 1);
}

void quickSort(int *array, int low, int high)
{
  if (low < high)
  {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

int main(void)
{
    int totalNumber; scanf("%d", &totalNumber);
    int data[totalNumber];
    
    for (int i = 0 ; i < totalNumber ; i++)
        scanf("%d", &data[i]);
    
    // step 1: sorting
    quickSort(data, 0, totalNumber - 1);
    
    // step 2: find distinct/unique number
    NewData newData[totalNumber];
    int distinct = 0;
    for (int i = 0 ; i < totalNumber - 1 ; i++)
        if (data[i] != data[i + 1])
        {
            newData[distinct].number = data[i];
            distinct += 1;
        }
    
    // step 4: count the frequency of distinct number
    for (int i = 0 ; i < distinct ; i++)
    {
        // initialize default value to 0
        newData[i].frequency = 0;
        
        for (int j = 0 ; j < totalNumber ; j++)
            if (data[j] == newData[i].number)
                newData[i].frequency += 1;
    }
    
    // step 5: find mode
    int mode = newData[0].frequency;
    for (int i = 1 ; i < distinct ; i++)
        if (newData[i].frequency > mode)
            mode = newData[i].frequency;
    
    // step 6: print the mode data
    // if there are multiple modes, print the smallest one
    for (int i = 1 ; i < distinct ; i++)
        if (newData[i].frequency == mode)
        {
            printf("%d\n", newData[i].number);
            break;
        }
            
    /*
    Sample Input
    8
    10 15 12 12 25 2 5 5
    */
    return 0;
}
