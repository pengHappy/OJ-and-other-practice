//
//  poj1089.cpp
//  poj
//
//  Created by zp007 on 9/13/15.
//  Copyright (c) 2015 zp007. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

class M_Node{
public:
    int start;
    int finish;
};

M_Node Node[20], New_Node[20];

int cmp(const M_Node &a, const M_Node &b){
    return a.start == b.start ? a.finish < b.finish : a.start < b.start;
}

int main()
{
    int N;
    int ter;
    int k, _N_num;
    cin >> N;
    memset(Node, 0, sizeof(Node));
    memset(New_Node, 0, sizeof(New_Node));
    for(int i = 0; i < N; i++){
        cin >> Node[i].start >> Node[i].finish;
    }
    sort(Node, Node + N, cmp);
    
    Node[N].start = 9999;
    ter = Node[0].finish;
    k = 0;
    _N_num = 0;
    
    for(int i = 0; i < N; i++){
        if(ter < Node[i + 1].start){
            New_Node[k].finish = ter;
            New_Node[k].start = Node[_N_num].start;
            k++;
            _N_num = i + 1;
        }
        ter = Node[i + 1].finish;
    }
    
    cout << endl;
    for(int i = 0; i < k; i++)
        cout << New_Node[i].start << " " << New_Node[i].finish << endl;
    cout << endl;
    
    return  0;
}
