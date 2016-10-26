//
//  Bribe the Prisoners.cpp
//  poj
//
//  Created by zp007 on 9/17/15.
//  Copyright (c) 2015 zp007. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int P, Q;
    int A[50], dp[50][50];
    memset(A, 0, sizeof(A));
    
    cin >> P >> Q;
    
    for(int i = 1; i <= Q; i++)
        cin >> A[i];
    
    A[0] = 0;
    A[Q + 1] = P + 1;
    
    for(int i = 0; i <= Q; i++)
        dp[i][i + 1] = 0;
    
    for(int w = 2; w <= Q + 1; w++){
        for(int i = 0; i + w <= Q + 1; i++){
            int j = i + w;
            int t = 999;
            for(int k = i + 1; k < j; k++){
                t = min(t, dp[i][k] + dp[k][j]);
            }
            dp[i][j] = t + A[j] - A[i] - 2;
        }
    }
    
    cout << dp[0][Q + 1] << endl;
    
    return 0;
}
