#include <stdio.h>
#include <string.h>

typedef struct
{
    char str1[100];
    int consonant;
} Data;

int main(void)
{
    // Input string quantity and the length of string
    int totalString, lengthString;
    scanf("%d %d", &totalString, &lengthString);
    
    
    Data data[totalString];
    
    for (int i = 0 ; i < totalString ; i++)
    {
        // Initialize 'consonant' to default value 0
        data[i].consonant = 0;
        
        // Input string
        scanf("%s", data[i].str1);
        getchar();
        
        // Count the number of consonants in each string
        for (int j = 0 ; j < lengthString ; j++)
            if (data[i].str1[j] == 'a' || data[i].str1[j] == 'i' ||
                data[i].str1[j] == 'u' || data[i].str1[j] == 'e' ||
                data[i].str1[j] == 'o')
                data[i].consonant += 1;
    }
    
    // Sorting based on requirements
    // The sorting process should be done after all strings have been inputted
    
    // First priority - consonants
    for (int i = 0 ; i < totalString ; i++)
        for (int j = 0 ; j < totalString - 1 ; j++)
                if (data[j].consonant < data[j + 1].consonant)
                {
                    // Swap
                    Data temporary = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temporary;
                }
                
    // Second priority - lexicographic order.
    for (int i = 0 ; i < totalString ; i++)
        for (int j = 0 ; j < totalString - 1 ; j++)
            if (data[j].consonant == data[j + 1].consonant &&
                     strcmp(data[j].str1, data[j + 1].str1) > 0)
            {
                // Swap
                Data temporary = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temporary;
            }
    puts("\n==========\n");
    // Print the final result
    for (int i = 0 ; i < totalString ; i++)
        puts(data[i].str1);
    puts("");
    
     
    /*
     === Sample Input 1 ===
     
     5 8
     jollybee
     jojolili
     lilibibi
     bibijojo
     jollibee
     
     === Sample Input 2 ===
     
     7 5
     aaaaa
     bbbbb
     ccccc
     ddddd
     eeeee
     abcde
     edcba
     */
    
    return 0;
}
