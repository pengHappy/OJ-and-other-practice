#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

typedef long long LL;

LL LL_mult(LL a, LL b, LL m) {
    LL ret = 0;
    LL exp = a % m;
    while(b) {
        if(b & 1) {
            ret += exp;
            if(ret > m)
                ret -= m;
        }
        exp <<= 1;
        if(exp > m)
            exp -= m;
        b >>= 1;
    }

    return ret;
}

LL LL_power(LL a, LL n, LL mod) {
    LL ret = 1;
    while(n) {
        if(n & 1) {
            ret = LL_mult(ret, a, mod);
            n--;
        }
        n >>= 1;
        a = LL_mult(a, a, mod);
    }

    return ret;
}

bool isPrime(LL n) {
    bool isP = true;
    for(int i = 2; i < sqrt(n); i++) {
        if(n % i == 0) {
            isP = false;
            break;
        }
    }
    return isP;
}

int main()
{
    LL p, a;
    while(true) {
        scanf("%lld %lld", &p, &a);
        if(a == 0 && p == 0)
            break;

        if(!isPrime(p) && LL_power(a, p, p) == a)
            puts("Yes");
        else
            puts("No");
    }

    return 0;
}
No. 91
