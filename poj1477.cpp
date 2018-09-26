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

vector<int> brick(50);
int t, n, average, sum, res;

int main() {
    while(scanf("%d", &n) != EOF && n) {
        sum = 0;
        res = 0;
        for(int i = 0; i < n; i++) {
            cin >> brick[i];
            sum += brick[i];
        }
        average = sum / n;
        for(int i = 0; i < n; i++) {
            if(brick[i] > average) {
                res += brick[i] - average;
            }
        }
        printf("Set #%d\n", ++t);
        printf("The minimum number of moves is %d.\n\n", res);
    }
    return 0;
}