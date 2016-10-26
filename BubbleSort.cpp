//
//  BubbleSort.cpp
//  poj
//
//  Created by zp007 on 9/11/15.
//  Copyright (c) 2015 zp007. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int N, i, j, t[30];
    cin >> N;
    
    for(i = 0; i < N; i++)
        cin >> t[i];
    
    for(i = 1; i < N; i++){
        for(j = 0; j < N - i; j++){
            if(t[j] > t[j + 1]){
                int temp = 0;
                temp = t[j + 1];
                t[j + 1] = t[j];
                t[j] = temp;
            }
        }
    }
    
    for(i = 0; i < N; i++)
        cout << t[i] << " ";
    cout << endl;
    
    return 0;
}
