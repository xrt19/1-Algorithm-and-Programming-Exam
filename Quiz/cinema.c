#include <stdio.h>

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
    int totalSeat, totalGroup;
    scanf("%d %d", &totalSeat, &totalGroup);
    
    int Group[totalGroup];
    
    for (int i = 0 ; i < totalGroup ; i++)
        scanf("%d", &Group[i]);
    
    // Sorting to maximize the capacity of the cinema
    quickSort(Group, 0, totalGroup - 1);
    
    // Count maximum group
    int sum = 0, counter = 0;
    for (int i = 0 ; i < totalGroup ; i++)
    {
        if (Group[i] != 0 && sum + Group[i] <= totalSeat)
        {
            sum += Group[i];
            counter += 1;
        }
        if (sum >= totalSeat)
            break;
    }
    
    printf("%d\n", counter);
    
    /*
     Sample Input 1: 15 4 7 8 5 6
     Sample Input 2: 20 5 3 10 10 0 3
     
     */
    
    
    return 0;
}
