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

const int MAX_C = 100 + 1;
const int MAX_INT = 1e9;
const int extra = 10;

int t, c, amount[MAX_C], price[MAX_C], dp[MAX_C];

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &c);
        for(int i = 1; i <= c; i++) {
            scanf("%d%d", amount + i, price + i);
        }
        for(int i = 1; i <= c; i++) {
            dp[i] = MAX_INT;
            for(int j = i - 1, total_i = amount[i]; j >= 0; total_i += amount[j], j--) {
                dp[i] = min(dp[i], dp[j] + (total_i + extra) * price[i]);
            }
        }
        printf("%d\n", dp[c]);
    }
    return 0;
}