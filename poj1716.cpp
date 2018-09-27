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

typedef struct Node {
    int s, e;
    Node() {}
    Node(int s, int e) : s(s), e(e) {}
} Node;

bool comp(Node a, Node b) {
    if(a.e == b.e) {
        return a.s < b.s;
    }
    return a.e < b.e;
}

vector<Node> node(10000);
int n, first, second, res;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        cin >> node[i].s >> node[i].e;
    }
    sort(node.begin(), node.begin() + n, comp);
    res = 2;
    first = node[0].e - 1;
    second = node[0].e;
    for(int i = 1; i < n; i++) {
        if(node[i].s <= first && second <= node[i].e) {
            continue;
        }
        else if(node[i].s <= second) {
            first = second;
            second = node[i].e;
            if(second > first) {
                res++;
            }
        }
        else {
            first = node[i].e - 1;
            second = node[i].e;
            res += 2;
        }
    }
    printf("%d\n", res);
    return 0;
}