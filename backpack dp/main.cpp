#include <iostream>
#include <memory.h>
#define MAX_N 100
using namespace std;
int v[MAX_N], w[MAX_N];
int dp[MAX_N][MAX_N];
int Num, Weight;

int myMax(int a, int b) {
    return (a > b? a : b);
}

int solve(int W, int i) {
    if(dp[W][i] >= 0)
        return dp[W][i];
    int res;
    if(w[i] > W)
        res = solve(W, i + 1);
    else if(i == Num)
        res = 0;
    else
        res = myMax(solve(W, i + 1), v[i] + solve(W - w[i], i + 1));
    return dp[W][i] = res;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> Num >> Weight;
    for(int i = 0; i < Num; i++) {
        cin >> w[i] >> v[i];
    }
    int res = solve(Weight, 0);
    cout << res << endl;
    return 0;
}
