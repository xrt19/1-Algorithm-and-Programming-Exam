#include <stdio.h>

void check(int *bigData, int totalData, int find)
{
    int counter = 0;
    for (int i = 0 ; i < totalData ; i++)
    {
        if (find < bigData[i])
            counter += 1;
    }
    printf("%d\n", counter);
}

#include <stdio.h>

int main(void)
{
    // insert code here...
    printf("Hello, World!\n");
    
    int totalData; scanf("%d", &totalData);
    int bigData[totalData];
    
    for (int i = 0 ; i < totalData ; i++)
        scanf("%d", &bigData[i]);
    
    int totalQuery; scanf("%d", &totalQuery);
    int bigQuery[totalQuery];
    
    for (int i = 0 ;  i < totalQuery ; i++)
        scanf("%d", &bigQuery[i]);
    
    for (int i = 0 ;  i < totalQuery ; i++)
        check(bigData, totalData, bigQuery[i]);
    
    /*
    Sample Input
    5
    1 5 7 10 14
    2
    7
    14
    
    */
    return 0;
}
