//
//  main.cpp
//  poj
//
//  Created by zp007 on 9/10/15.
//  Copyright (c) 2015 zp007. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{
    int first, second;
    bool isRead;
}M_Node;

int cmp(const M_Node &a, const M_Node &b){
    if(a.first < b.first)
        return 1;
    else{
        if(a.first == b.first){
            if(a.second < b.second)
                return 1;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    M_Node Node[20];
    int n;
    do{
        cin >> n;
        if(n == 0)
            break;
        for(int i = 0 ;i < n; i++){
            cin >> Node[i].first;
            cin >> Node[i].second;
            Node[i].isRead = false;
        }
        sort(Node, Node + n, cmp);
        int res = 1, i = 0, j = 0;
        while(Node[n - 1].isRead == false){
            while(j < n && Node[j].first < Node[i].second){
                Node[j].isRead = true;
                j++;
            }
            if(j == n)
                break;
            i = j;
            res++;
        }
        cout << res << endl;
    }while(1);
    return 0;
}
