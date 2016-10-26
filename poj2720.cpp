#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_PRIME 2777
#define MAX_N 100 + 1
int prime[MAX_PRIME], size;     // 素数表
int ten_power[8];               // 十的n次方
int cache[MAX_N][MAX_N];        // 答案表，ans=cache[b][i]
int fbx[MAX_N][MAX_N];          // fb(x)表，fb(x)=fbx[b][x]，如果为-1则超出10e7

typedef long long LL;

int power_of(const int &a, const int &n) {
    if(n < 0)
        return -1;
    int ret = 1;
    for(int i = 1; i <= n; i++) {
        ret *= a;
        if(ret > ten_power[7])
            return -1;
    }
    return ret;
}

void prepare() {
    //筛选素数
    bool isPrime[MAX_PRIME] = {true};
    int pos = 0;
    for(int i = 2; i < MAX_PRIME; i++) {
        if(isPrime[i]) {
            prime[pos++] = i;
            for(int j = i + i; j < MAX_PRIME; j += i) {
                isPrime[j] = false;
            }
        }
    }

    //列举十位数
    ten_power[0] = 1;
    for(int i = 1; i <= 7; i++) {
        ten_power[i] = ten_power[i - 1] * 10;
    }

    //fbx()
    for(int i = 1; i < MAX_N; i++) {
        fbx[i][0] = 1;
        for(int j = 1; j < MAX_N; j++) {
            fbx[i][j] = power_of(i, fbx[i][j - 1]);
        }
    }

    //cache
    for(int i = 0; i < MAX_N; i++)
        for(int j = 0; j < MAX_N; j++)
            cache[i][j] = -1;

}

//return phi(n)， 欧拉函数 O(sqrt(n))
int phi(int x) {
    int euler = x;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            euler = euler / i * (i - 1);
            while(x % i == 0)
                x /= i;
        }
    }
    if(x > 1)
        euler = euler / x * (x - 1);

    return euler;
}

// return (a ^ n) % mod
int mod_Power(LL a, int n, int mod) {
    int ret = 1;
    while(n > 0) {
        if(n & 1) {
            ret = ret * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

// return fb(x) % mod
int solve(int b, int x, int mod) {
    if(x == 0)
        return 1;
    if(mod == 1)
        return 0;

    if(fbx[b][x] == -1) {
        int euler = phi(mod);
        return mod_Power(b,
                        solve(b, x - 1, euler) + euler,// 按照fbx()定义和欧拉公式得出
                        mod);
    }
    else {
        return fbx[b][x] % mod;
    }
}

int main()
{
    prepare();

    int b, iteration, n, ans;
    char format[] = "%00d\n";
    while (~scanf("%d", &b) && b)
    {
        scanf("%d%d", &iteration, &n);
        format[2] = char(n + '0');

        if (cache[b][iteration] == -1)
        {
            if (b == 1)
            {
                ans = 1;
            }
            else
            {
                ans = solve(b, iteration, ten_power[7]);
            }
            cache[b][iteration] = ans;
        }
        ans = cache[b][iteration] % ten_power[n];

        printf(format, ans);
    }

    return 0;
}
//No. 92
