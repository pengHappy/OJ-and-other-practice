#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <functional>

using namespace std;

const int MAX_N = 100 + 1;
const int MAX_INT = 1e9;
int dp[2][MAX_N][MAX_N];
int n, contacts, from, to, timeCost;
int person, longestTime;

int main() {
    while(scanf("%d", &n) != EOF && n) {
        for(int i = 0; i < MAX_N; i++) {
            for(int j = 0; j < MAX_N; j++) {
                dp[0][i][j] = MAX_INT;
                dp[1][i][j] = MAX_INT;
            }
        }
        for(int i = 1; i <= n; i++) {
            scanf("%d", &contacts);
            from = i;
            while(contacts--) {
                scanf("%d%d", &to, &timeCost);
                dp[0][from][to] = min(dp[0][from][to], timeCost);
            }
        }
        for(int k = 1; k <= n; k++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    dp[k % 2][i][j] = min(dp[(k - 1) % 2][i][j], dp[(k - 1) % 2][i][k] + dp[(k - 1) % 2][k][j]);
                }
            }
        }
        longestTime = -1;
        for(int i = 1; i <= n; i++) {
            
        }
    }
    return 0;
}