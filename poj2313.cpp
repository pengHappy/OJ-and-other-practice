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

//const int MAX_N = 50000 + 1;
//const int MAX_INT = 1e9;

int n, a[100], middle, res;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    if(n % 2) {
        middle = a[n / 2];
    }
    else {
        middle = (a[(n - 1) / 2] + a[n / 2]) / 2;
    }
    for(int i = 0; i < n; i++) {
        if(middle < a[i]) {
            res += a[i] - middle;
        }
        else {
            res += middle - a[i];
        }
    }
    printf("%d\n", res);
    return 0;
}