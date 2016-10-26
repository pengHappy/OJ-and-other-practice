#include <iostream>
#include <math.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

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

int inv(int a, int m) {
    int x, y;
    int gcd = extgcd(a, m, x, y);
    if(gcd != 1)
        return -1;
    x /= gcd;
    if(x < 0)
        x = (x + abs(m)) % abs(m);
    return x;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int a, m;
        scanf("%d %d", &a, &m);
        int ans = inv(a, m);
        if(ans == -1)
            puts("Not Exist");
        else
            printf("%-4d\n", ans);
    }
    return 0;
}
//No. 83
