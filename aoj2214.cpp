#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 1000000007

inline int add(int a, int b) {
    return (a + b) % MOD;
}

inline int sub(int a, int b) {
    return (a - b) % MOD;
}

inline int mul(int a, int b) {
    return 1LL * a * b % MOD;
}

struct warp {
    int x1, y1, x2, y2;

    warp(int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }

    bool operator < (const warp &w) const {
        if(x1 != w.x1)
            return x1 < w.x1;
        return y1 < w.y1;
    }
};

int extgcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = extgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return r;
}

int inv(int a) {
    int x, y;
    extgcd(a, MOD, x, y);
    return (x % MOD + MOD) % MOD;
}

int fact[200010]; //阶乘数组
void init_factorial() {
    fact[0] = 1;
    for(int i = 1; i < 200000; i++)
        fact[i] = mul(fact[i - 1], i);
}

inline int nck(int n, int k) {
    return mul(mul(fact[n], inv(fact[n - k])), inv(fact[k]));
}

int N, M, K, dp[100010];
//dp[i]: 到达i号虫洞入口的方案数
vector<warp> warps;

inline int cal(int x1, int y1, int x2, int y2) {
    if(x2 < x1 || y2 < y1)
        return 0;
    return nck(x2 - x1 + y2 - y1, y2 - y1);
}

bool input() {
    warps.clear();
    scanf("%d %d %d", &N, &M, &K);
    if(N == -1 && M == -1)
        return false;

    N--;
    M--;

    int x1, y1, x2, y2;
    for(int i = 0; i < K; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        warp warpObj(--x1, --y1, --x2, --y2);
        warps.push_back(warpObj);
    }
    return true;
}

int solve() {
    for(int i = 0; i < 100010; i++)
        dp[i] = 0;
    sort(warps.begin(), warps.end());
    warp warpObj(N, M, N + 1, M + 1);
    warps.push_back(warpObj);
    for(int i = 0; i <= K; i++) {
        dp[i] = nck(warps[i].x1 + warps[i].y1, warps[i].y1);
        for(int j = 0; j < i; j++) {
            dp[i] = add(dp[i], mul(dp[j], sub(cal(warps[j].x2, warps[j].y2, warps[i].x1, warps[i].y1),
                                              cal(warps[j].x1, warps[j].y1, warps[i].x1, warps[i].y1))));
            //这里dp[i]是减少的。由于上一虫洞的存在，到达上一起点相当于到达上一终点。故dp[i]必减少
            //inline int sub()返回负值
        }
    }
    return dp[K];
}

int main()
{
    while(input()) {
        init_factorial();
        printf("%-6d\n", solve());
    }
    return 0;
}
//No. 85




