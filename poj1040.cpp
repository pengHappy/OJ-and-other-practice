//
//  poj1040.cpp
//  poj
//
//  Created by zp007 on 9/11/15.
//  Copyright (c) 2015 zp007. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int n, m, cap;

class Order{
public:
    int start;
    int finish;
    int cnt;
};

Order Od[30];
int Emax;
int psg[7];

int cmp(const Order &a, const Order &b){
    return a.start == b.start
    ? (a.finish == b.finish ? b.cnt < a.cnt : b.finish < a.finish)
    : a.start < b.start;
}

void dfs(int i, int now){
    if(now > Emax)
        Emax = now;
    
    for(int t = i; t < n; t++){
        if(psg[Od[t].start] + Od[t].cnt > cap)
            continue;
        for(int j = Od[t].start; j < Od[t].finish; j++)
            psg[j] += Od[t].cnt;
        dfs(t + 1, now + Od[t].cnt * (Od[t].finish - Od[t].start));
        for(int j = Od[t].start; j < Od[t].finish; j++)
            psg[j] -= Od[t].cnt;
    }
    /* 
    注意，psg[]为当前车上乘客数量，用数组表示没有用统一变量
    该dfs没有剪枝
     */
}

int main()
{
    while(1){
        cin >> cap >> m >> n;
        if(cap == 0)
            break;
        for(int i = 0; i < n; i++){
            cin >> Od[i].start >> Od[i].finish >> Od[i].cnt;
        }
        sort(Od, Od + n, cmp);
        memset(psg, 0, sizeof(psg));
        dfs(0, 0);
        cout << Emax << endl;
    }
    return 0;
}


