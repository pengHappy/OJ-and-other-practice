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

typedef pair<int, int> P;
const int MAX_N = 100 + 1;
int dp[MAX_N][MAX_N];
int n, k, t, x, y, x_1, y_1, x_2, y_2, leftEnd, rightEnd, res;
priority_queue<P, vector<P>, less<P>> pq;

int main() {
    scanf("%d", &t);
    while(t--) {
        x = 0;
        y = 0;
        res = 0;
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++) {
            scanf("%d%d%d%d", &y_1, &x_1, &y_2, &x_2);
            leftEnd = min(y_1, y_2);
            rightEnd = max(y_1, y_2);
            x = max(x, x_1);
            y = max(y, rightEnd);
            for(int j = leftEnd, val = rightEnd - leftEnd + 1; j <= rightEnd; j++, val--) {
                dp[x_1][j] = val;
            }
        }
        for(int j = 0; j <= y; j++) {
            while(!pq.empty()) {
                pq.pop();
            }
            int count = 0;
            for(int i = 0; i <= x; i++) {
                if(dp[i][j]) {
                    pq.push(P(dp[i][j], i));
                    count++;
                }
            }
            while(count > k) {
                P p = pq.top();
                pq.pop();
                int row = p.second;
                for(int len = p.first, col = j; len > 0; len--, col++) {
                    dp[row][col] = 0;
                }
                count--;
                res++;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}