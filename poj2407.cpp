#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXN 100001

int euler[MAXN];

//欧拉函数值的两种求法。第一种按照公式计算； 第二种筛选法，以第一种方法为基础
void eulerOne(int n) {
    int ret = n;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            ret = ret / i * (i - 1);
            while(n % i == 0)
                n /= i;
        }
    }
    if(n > 1)
        ret = ret / n * (n - 1);
    printf("1:  %d\n", ret);
}

void eulerTwo(int Num) {
    for(int i = 1; i < MAXN; i++)
        euler[i] = i;
    for(int i = 2; i < MAXN; i++) {
        if(euler[i] == i) {
            for(int j = i; j < MAXN; j += i)
                euler[j] = euler[j] / i * (i - 1);
        }
    }
    printf("2:  %d\n", euler[Num]);
}

int main()
{
    int N;
    while(true) {
        scanf("%d", &N);
        if(N == 0)
            break;
        eulerOne(N);
        eulerTwo(N);
    }
    return 0;
}
//No. 86
