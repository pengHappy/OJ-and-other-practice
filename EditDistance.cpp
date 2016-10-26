#include <stdio.h>
#include <string.h>
const int _size = 200;

int myMin(int a, int b, int c) {
    int ans;
    ans = a < b? a : b;
    ans = ans < c? ans : c;
    return ans;
}

int editDistance(char a[], char b[]) {
    int dp[_size][_size];
    int i;
    int j;
    int len_A = strlen(a);
    int len_B = strlen(b);
    for(i = 0; i <= len_A; i++) {
        for(j = 0; j <= len_B; j++) {
            if(i == 0 && j == 0)
                dp[i][j] = 0;
            else if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else {
                if(a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = myMin(dp[i - 1][j] + 1,
                                      dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1);
            }
        }
    }
    return dp[len_A][len_B];
}

int main()
{
    char a[_size], b[_size];
    int res;
    while(true) {
        scanf("%s", a);
        scanf("%s", b);
        if(strcmp(a, "0") == 0 && strcmp(b, "0") == 0)
            break;
        res = editDistance(a, b);
        printf("%4d\n", res);
    }
    return 0;
}
//No.70
