#include <iostream>
#include <stdio.h>
using namespace std;
#define ll long long

int gcd(int a, int b) {
    return b == 0? a : gcd(b, a % b);
}

ll power(ll p, ll n) {
    ll sum = 1;
    while(n) {
        if(n & 1) {
            sum = p * sum;
        }
        p *= p;
        n >>= 1;
    }
    return sum;
}

int main()
{
    int n;
    const ll m = 3;
    while(true) {
        scanf("%d", &n);
        if(n == -1)
            break;
        ll _count = 0;
        for(int i = 1; i <= n; i++) {
            _count += power(m, gcd(i, n));
        }
        if(n & 1)
            _count += n * power(m, n / 2 + 1);
        else
            _count += n / 2 * (power(m, n / 2 + 1) + power(m, n / 2));
        _count /= n * 2;
        printf("%lld\n", _count);
    }
    return 0;
}
//No. 78
