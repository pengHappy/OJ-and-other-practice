//
//  poj1032.cpp
//  poj
//
//  Created by zp007 on 9/10/15.
//  Copyright (c) 2015 zp007. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int N, i, k, ANS, res[20];
    cin >> N;
    ANS = 0;
    for(i = 2, k = 0; N - (ANS + i) >= 0; i++, k++){
        res[k] = i;
        ANS += i;
    }

    N -= ANS;
    k--;
    i = k;
    
    while(k >= 0){
        res[k]++;
        k--;
        N--;
    }
    
    if(N > 0)
        res[i]++;
    
    for(int t = 0; t <= i; t++){
        if(t == i)
            cout << res[t] << endl;
        else
            cout << res[t] <<" ";
    }

    return 0;
}
