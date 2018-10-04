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
//const int MAX_INT = 1e9;

typedef struct Node {
    int s, e, id;
} Node;

bool comp(Node a, Node b) {
    if(a.s == b.s) {
        return a.e < b.e;
    }
    return a.s < b.s;
}

typedef pair<int, int> P;

Node node[MAX_N];
int n, c, res[MAX_N];
priority_queue<P, vector<P>, greater<P> > pq;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &node[i].s, &node[i].e);
        node[i].id = i;
    }
    sort(node + 1, node + n + 1, comp);
    
    pq.push(P(node[1].e, 1));
    res[ node[1].id ] = 1;
    
    for(int i = 2; i <= n; i++) {
        if(pq.top().first < node[i].s) {
            res[ node[i].id ] = pq.top().second;
            pq.pop();
            pq.push(P(node[i].e, res[ node[i].id ]));
        }
        else {
            res[ node[i].id ] = (int) pq.size() + 1;
            pq.push(P(node[i].e, res[ node[i].id ]));
        }
    }
    printf("%d\n", (int) pq.size());
    for(int i = 1; i <= n; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}