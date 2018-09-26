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

int t, m, n;
vector<int> card(50 + 1);

int main() {
    while(scanf("%d%d", &m, &n) != EOF && (m || n)) {
        for(int i = 0; i < n; i++) {
            cin >> card[i];
        }
        card[n] = m * n + 1;
        sort(card.begin(), card.begin() + n + 1);
        int larger = 0;
        int res = 0;
        for(int i = n; i >= 1; i--) {
            larger += card[i] - card[i - 1] - 1;
            if(larger == 0) {
                res++;
            }
            else {
                larger--;
            }
        }
        printf("Case %d: %d\n", ++t, res);
    }
    return 0;
}