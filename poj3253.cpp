//
//  poj3253.cpp
//  poj
//
//  Created by zp007 on 9/10/15.
//  Copyright (c) 2015 zp007. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

int main()
{
    int N, res, t[30];
    memset(t, 0, sizeof(t));
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> t[i];
    
    sort(t, t + N);
    res = 0;
    
    for(int i = 0; i < N - 1; i++){
        t[i + 1] += t[i];
        res += t[i + 1];
        sort(t + i + 1, t + N);
    }
    
    cout << res << endl;
    
    return 0;
}
