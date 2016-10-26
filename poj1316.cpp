//
//  poj1316.cpp
//  poj
//
//  Created by zp007 on 9/19/15.
//  Copyright (c) 2015 zp007. All rights reserved.
//

#include <iostream>
using namespace std;

int N[10001];

int main()
{
    int i;
    int ans;
    memset(N, -1, sizeof(N));
    for(i = 1; i <= 10000; i++){
        ans = 0;
        ans += i;
        int rp = i;
        while(rp > 0){
            ans += rp % 10;
            rp /= 10;
        }
        N[ans] = 1;
    }
    for(i = 1; i <= 10000; i++){
        if(N[i] == -1)
            cout << i << endl;
    }
    return 0;
}
