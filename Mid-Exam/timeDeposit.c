//
//  main.c
//  Mid-Exam Deposito
//
//  Created by Irfan Hera Nurrohman on 15/07/23.
//

#include <stdio.h>

void process(long long capital, int period, int interestRate)
{
    for (int i = 0 ; i < period ; i++)
    {
        long long profit = capital * interestRate * 80 / (12 * 100 * 100);
        
        capital += profit;
        printf("%d %lld\n", i + 1, capital);
    }
}

int main(void)
{
    // 1. Initialize testcase, capital, interest rate, and period
    int testcase; scanf("%d", &testcase);
    long long capital[testcase];
    int interestRate[testcase];
    int period[testcase];
    
    // 2. Input all requirement
    for (int i = 0 ; i < testcase ; i++)
        scanf("%lld %d %d", &capital[i], &interestRate[i], &period[i]);
    
    // 3. Output the result
    for (int i = 0 ; i < testcase ; i++)
    {
        printf("Case #%d:\n", i + 1);
        process(capital[i], period[i], interestRate[i]);
    }
    
    // Tested with sample input
    /*
    4
    1000000 5 6
    1000000 5 12
    1000000 10 12
    3629100 10 6
     */
    return 0;
}

