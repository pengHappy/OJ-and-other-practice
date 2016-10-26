#include <cstdio>
#include <stdio.h>
#include <iostream>
using namespace std;

const double eps = 1e-10;

double Pow(double a, int n) {
    double ret = 1.00;
    for(int i = 1; i <= n; i++) {
        ret *= a;
    }
    return ret;
}

double _function(double x) {
    return 8*Pow(x,4)+7*Pow(x,3)+2*Pow(x,2)+3*x+6.00;
}

void solve(double y) {
    double left = 0.00;
    double right = 100.00;
    double middle;
    double sum = _function(100.00);

    if(y < 6 || y > sum) {
        printf("No solution!\n");
        return;
    }

    //注意判断小数大小，设定eps即可。直接判断可能陷入死循环
    while(right - left > eps) {
        middle = (right + left) / 2.00;
        sum = _function(middle);
        if(sum - y > eps) {
            right = middle;
        }
        else {
            left = middle;
        }
    }

    printf("%0.4lf\n", left);
}

int main()
{
    int cases;
    while(true) {
        scanf("%d", &cases);
        if(cases == 0)
            break;

        while(cases--) {
            double y;
            scanf("%lf", &y);
            solve(y);
        }
    }

    return 0;
}
//No. 89
