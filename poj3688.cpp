#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

int A[16000];
int dp[16000][2];

int main()
{
    int N, M;
    while(true) {
        scanf("%d %d", &N, &M);
        if(N == 0 && M == 0)
            break;

        for(int i = 0; i < N; i++)
            scanf("%d", &A[i]);
        sort(A, A + N);
        for(int i = 0; i < 16000; i++) {
            dp[i][0] = false;
            dp[i][1] = false;
        }

        dp[A[0]][1] = true;
        for(int i = 1; i < N; i++) {
            for(int j = M; j > A[i]; j--) {
                if(dp[j - A[i]][0])
                    dp[j][1] = true;
                if(dp[j - A[i]][1])
                    dp[j][0] = true;
            }
            dp[A[i]][1] = true;
        }

        int ans = 0;
        for(int j = M; j >= 0; j--) {
            if(dp[j][1] && !dp[j][0])
                ans++;
        }

        printf("%-4d\n", ans);
    }
}
//No. 81
