#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <functional>

using namespace std;

const int MAX_N = 50000 + 1;
const int MAX_INT = 1e9;

typedef struct Node {
    int s, e, id, stall;
} Node;

bool comp(Node a, Node b) {
    if(a.e == b.e) {
        return a.s < b.s;
    }
    return a.e < b.e;
}

vector<Node> node(MAX_N);
int n, c, res[MAX_N];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        cin >> node[i].s >> node[i].e;
        node[i].id = i;
        node[i].stall = -1;
    }
    sort(node.begin(), node.begin() + n, comp);
    while(c < n) {
        c++;
    }
    
    
    return 0;
}