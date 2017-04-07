#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

bool isLeap(int y) {
    return (y % 4 == 0) && (y % 100 > 0 || y % 400 == 0);
}

int getLeap(int year) {
    int sum = 0;
    for(int y = 1; y <= year; y++) {
        if(isLeap(y)) {
            sum++;
        }
    }
    return sum;
}

int getMonthDays(int month) {
    int m[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum = 0;
    for(int i = 1; i <= month; i++) {
        sum += m[i];
    }
    return sum;
}

int calculateDays(int year, int month, int day) {
    int leapNum = getLeap(year - 1);
    int res = (year - 1) * 365 + leapNum + getMonthDays(month - 1) + day;
    if(isLeap(year) && month > 2) {
        res++;
    }
    return res;
}

int getTheDay(int year, int month) {
    int diff = abs( calculateDays(year, month, 1) - calculateDays(2017, 4, 6) );
    int day;
    if(year < 2017 || (year == 2017 && month <= 4)) {
        day = (7 + 4 - diff % 7) % 7;
    }
    else {
        day = (4 + diff % 7) % 7;
    }
    day = day == 0 ? 7 : day;
    return day;
}

void getAns(int ans[], int ys, int ms, int ye, int me) {
    int mds[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = getTheDay(ys, ms);
    int goods = 0;
    int luckys = 0;
    for(int y = ys; y <= ye; y++) {
        for(int m = y == ys ? ms : 1; y == ye ? m <= me : m <= 12; m++) {
            if(day == 1 || day >= 6) {
                goods++;
            }
            day = (day + mds[m] - 1 + ((isLeap(y) && m == 2) ? 1 : 0)) % 7;
            day = day == 0 ? 7 : day;
            if(day >= 5) {
                luckys++;
            }
            day++;
        }
    }
    ans[0] = luckys;
    ans[1] = goods;
}

int main()
{
    int w;
    int ys, ms, ye, me;
    int ans[] = {-1, -1};
    scanf("%d", &w);
    while(w-- > 0) {
        scanf("%d %d %d %d", &ys, &ms, &ye, &me);
        getAns(ans, ys, ms, ye, me);
        printf("%d %d\n", ans[0], ans[1]);
    }
}


















