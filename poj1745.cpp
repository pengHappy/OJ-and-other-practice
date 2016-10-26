#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX = 110;
const int MAXN = 1100;

int main()
{
    int n, k;
    int item;
    bool dp[MAXN][MAX];
    while(true) {
        scanf("%d %d", &n, &k);
        if(n == 0 && k == 0)
            break;
        for(int i = 0; i < MAXN; i++)
            for(int j = 0; j < MAX; j++)
                dp[i][j] = false;

        scanf("%d", &item);
        item = abs(item) % k;
        dp[0][item] = true;

        for(int i = 1; i < n; i++) {
            scanf("%d", &item);
            item = abs(item) % k;
            for(int j = 0; j < k; j++) {
                if(dp[i - 1][j]) {
                    dp[i][(j + item)%k] = true;
                    dp[i][(j - item + k)%k] = true; //j - item + k !!!
                }
            }
        }

        if(dp[n - 1][0])
            puts("Divisible");
        else
            puts("Indivisible");
    }
    return 0;
}
//No. 79
