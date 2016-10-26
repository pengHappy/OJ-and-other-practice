//
//  poj1218.cpp
//  poj
//
//  Created by zp007 on 9/20/15.
//  Copyright (c) 2015 zp007. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int N;
    int res[50];
    memset(res, -1, sizeof(res));
    cin >> N;
    int res_step = 0;
    while(N > 0){
        int rp;
        cin >> rp;
        bool operation[rp + 1];
        memset(operation, true, sizeof(operation));
        for(int i = 2; i <= rp; i++){
            int coh = 1;
            while(coh * i <= rp){
                if(operation[coh * i] == true)
                    operation[coh * i] = false;
                else
                    operation[coh * i] = true;
                coh++;
            }
        }
        int ans = 0;
        for(int i = 1; i <= rp; i++){
            if(operation[i] == true)
                ans++;
        }
        res[res_step++] = ans;
        N--;
    }
    
    for(int i = 0; res[i] > -1; i++)
        cout << res[i] << endl;
    
    return 0;
}
