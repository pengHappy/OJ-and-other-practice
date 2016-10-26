#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

const int MAXN = 1010;
const int N = 25;
struct components{
     char type[N];
     char name[N];
     int price;
     int quality;
};
components c[MAXN];
int n , budget;

bool judge(int x) {
    int i = 0, j = 0;
    int sum = 0;
    while(i < n) {
        int Min = 1e9;
        int pos = -1;
        int price = 0;
        for(j = i; j < n && !strcmp(c[i].type, c[j].type); j++) {
            if(c[j].quality >= x && Min > c[j].price) {
                pos = j;
                Min = c[j].price;
            }
        }
        if(pos == -1)
            return false;
        sum += Min;
        i = j;
    }

    return sum <= budget? true : false;
}

int solve(int Min, int Max) {
    int left = Min;
    int right = Max;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(judge(mid))
            left = mid + 1;
        else
            right = mid - 1;
    }

    return right;
}

int main()
{
    int cases;
    int Min = 1e9, Max = 0;

    scanf("%d", &cases);
    while(cases--) {
        scanf("%d %d", &n, &budget);
        for(int i = 0; i < n; i++) {
            scanf("%s %s %d %d", c[i].type, c[i].name, &c[i].price, &c[i].quality);
            Min = min(Min, c[i].quality);
            Max = max(Max, c[i].quality);
        }
        int ans = solve(Min, Max);
        printf("%d\n", ans);
    }

    return 0;
}
//No. 93
