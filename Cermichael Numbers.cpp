#include <iostream>
using namespace std;

typedef long long ll;

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while(n > 0) {
        if (n & 1 == 1)
            res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main()
{
    int N;
    int i;
    cin >> N;
    for(i = 2; i < N; i++) {
        ll res = mod_pow(i, N, N);
        if((int)res != i)
            break;
    }
    if(i == N)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
