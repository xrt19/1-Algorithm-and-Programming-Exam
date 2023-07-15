#include <stdio.h>

int main(void)
{
    /*
     
     RULES:
     
     1.The one who eats more pays, says Kenken
     2. Special for Aan:
        a. If the number of food items is even, even positions are reduced by 2 thousand.
        b. If the number of food items is odd, odd positions are reduced by 2.5 thousand
     3. Special for Kenken:
        a. Kenken wants to pay even if the price of the food eaten is the same as what Kenken ate
     
     */
    
    // 1. Initialize variable
    int totalFood; scanf("%d", &totalFood);
    int aan[totalFood], kenken[totalFood];
    
    // 2. Input price from the food they eat
    for (int i = 0 ; i < totalFood ; i++)
        scanf("%d", &aan[i]);
    for (int i = 0 ; i < totalFood ; i++)
        scanf("%d", &kenken[i]);
    
    // 3. Check whether total food is even or odd
    int i;
    if (totalFood % 2 == 1)
    {
        i = 0;
        while (i < totalFood)
        {
            aan[i] += 2500;
            i += 2;
        }
    }
    else
    {
        i = 1;
        while (i < totalFood)
        {
            aan[i] += 2000;
            i += 2;
        }
    }
    
    // 4. Sum the total price
    long long sumAan = 0, sumKenken = 0;
    
    for (int i = 0 ; i < totalFood ; i++)
        sumAan += aan[i];
    for (int i = 0 ; i < totalFood ; i++)
        sumKenken += kenken[i];
    
    // 5. Decide who will pay
    if (sumAan <= sumKenken)
        puts("kenken");
    else
        puts("aan");
    
    // Tested with sample input
    /*
     1
     1000 2000
     
     2
     5000 2000 10000 16892
     */
    return 0;
}
