//
//  poj1528.cpp
//  poj
//
//  Created by zp007 on 9/19/15.
//  Copyright (c) 2015 zp007. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int t, res;
    int co;
    vector<string> RV;
    do{
        cin >> t;
        
        if(t == 0)
            break;
        
        char ch[200];
        string rp;
        sprintf(ch, "%d", t);
        rp = ch;
        
        for(co = t - 1, res = 0; co > 0; co--){
            if(t % co == 0)
                res += co;
            if(res > t){
                RV.push_back(rp + " ABUNDANT");
                break;
            }
        }
        
        if(res < t)
            RV.push_back(rp + " DEFICIENT");
        else if(res == t)
            RV.push_back(rp + " PERFECT");
        
    }while(1);
    
    for(int i = 0; i < RV.size(); i++)
        cout << RV[i] << endl;
    
    return 0;
}
