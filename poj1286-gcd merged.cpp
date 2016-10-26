#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>
using namespace std;

#define LL long long
const int m = 3;

inline LL power(LL p, LL n) {
    LL ret = 1;
    while(n > 0) {
        if(n & 1) {
            ret = ret * p;
            n--;
        }
        p = p * p;
        n >>= 1;
    }
    return ret;
}

// Qualifier: 约数枚举
// Returns:   vector<int> 约数
vector<int> divisor(const int &n) {
    vector<int> div;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            div.push_back(i);
            if(i != n / i)
                div.push_back(n / i);
        }
    }
    return div;
}

// Qualifier: 质因数分解
// Returns:   map<int, int>
map<int, int> prime_factor(int n) {
    map<int, int> primes;
    primes.clear();
    for(int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            primes[i]++;
            n /= i;
        }
    }
    if(n > 1) {
        primes[n]++;
    }
    return primes;
}

LL polya(const int& m, const int& n) {
    map<int, int> primes = prime_factor(n);
    vector<int> divs = divisor(n);
    LL res = 0;

    //对于n = m * k, 在 1-n 中有 euler(k) 个与 n 的最大公约数为 m 的数字
    for(int i = 0; i < divs.size(); i++) {
        LL euler = divs[i];
        for(map<int, int>::iterator it = primes.begin(); it != primes.end(); it++) {
            int p = it->first;
            if(divs[i] % p == 0)
                euler = euler / p * (p - 1);
        }
        res += euler * power(m, n / divs[i]);
    }

    res /= n;
    return res;
}

int main()
{
    int n;
    while(true) {
        scanf("%d", &n);
        if(n <= -1)
            break;
        if(n == 0) {
            puts("0");
            continue;
        }
        LL _count = 0;
        _count += polya(m, n) * n;
        if(n & 1)
            _count += n * power(m, n / 2 + 1);
        else
            _count += (power(m, n / 2 + 1) + power(m, n / 2)) * (n / 2);

        _count /= 2 * n;

        printf("%lld\n", _count);
    }

    return 0;
}
//No. 87




