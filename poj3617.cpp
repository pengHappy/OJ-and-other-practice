//
//  poj3617.cpp
//  poj
//
//  Created by zp007 on 9/10/15.
//  Copyright (c) 2015 zp007. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N, i, j;
    string S, T;
    do{
        cin >> N;
        
        if(N == 0)
            break;
        
        getchar();
        getline(cin, S);
        
        i = 0; j = N - 1;
        T = "";
        
        while(i <= j){
            if(S[i] < S[j]){
                T = T + S[i];
                i++;
            }
            else if(S[i] > S[j]){
                T = T + S[j];
                j--;
            }
            else{
                int fwd = i + 1;
                int bk = j - 1;
                while(fwd <= bk && S[fwd] == S[bk]){
                    fwd++;
                    bk--;
                }
                if(S[fwd] > S[bk]){
                    T = T + S[j];
                    j--;
                }
                else /*if(S[fwd] < S[bk])*/{
                    T = T + S[i];
                    i++;
                }
            }
        }
        
        cout << T << endl;
        
    }while(1);
    
    return 0;
}
