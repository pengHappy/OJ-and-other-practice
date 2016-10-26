#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

typedef long long LL;
const int N = 10005;
const int MOD = 9901;

bool prime[N];
int p[N];
int cnt;

//筛选素数的快速方法
void isPrime() {
    for(int i = 0; i < N; i++)
        prime[i] = true;
    cnt = 0;
    for(int i = 2; i < N; i++) {
        if(prime[i]) {
            p[cnt++] = i;
            for(int j = i + i; j < N; j += i)
                prime[j] = false;
        }
    }
}

LL power(LL a, LL b) {
    LL ans = 1;
    a %= MOD;
    while(b) {
        if(b & 1) {
            ans = ans * a;
            b--;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

//二分求等比数列和
LL sum(LL a, LL n) {
    if(n == 0)
        return 1;

    LL t = sum(a, (n - 1)/2);
    LL cur = power(a,(n+1)/2);

    if(n & 1) {
        t = (t + t % MOD * cur % MOD) % MOD;
    }
    else {
        t = (t + t % MOD * cur % MOD) % MOD;
        t = (t + power(a,n)) % MOD;
    }

    return t;
}

void Solve(LL A, LL B) {
    LL ans = 1;
    for(int i = 0; p[i] * p[i] <= A; i++) {
        if(A % p[i] == 0) {
            int num = 0;
            while(A % p[i] == 0) {
                A /= p[i];
                num++;
            }
            ans *= sum(p[i], num * B) % MOD;
            ans %= MOD;
        }
    }
    if(A > 1) {
        ans *= sum(A, B) % MOD;
        ans %= MOD;
    }
    printf("%d\n", ans);
}

int main()
{
    LL A, B;
    isPrime();
    while(true) {
        scanf("%lld %lld", &A, &B);
        if(A == 0 && B == 0)
            break;
        Solve(A, B);
    }
    return 0;
}
//No. 84
