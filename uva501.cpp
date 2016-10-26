#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
const int _size = 300;
int num[_size];

void solve(int N) {
    int j;
    int _u;
    vector<int> vct;
    vct.clear();
    int pos = 0;
    int index = 0;
    for(j = 0; j < N; j++) {
        scanf("%d", &_u);
        vector<int>::iterator it;
        while(vct.size() < _u) {
            //!!!!!
            it = lower_bound(vct.begin(), vct.end(), num[pos]);
            vct.insert(it, num[pos]);
            pos++;
        }
        printf("%d\n", vct[index++]);
    }
    printf("\n\n");
    for(int i = 0; i < vct.size(); i++)
        printf("%d\n", vct[i]);
}

int main()
{
    int cases;
    int M, N;
    scanf("%d", &cases);
    while(cases--) {
        scanf("%d %d", &M, &N);
        for(int i = 0; i < M; i++)
            scanf("%d", &num[i]);
        solve(N);
    }
    return 0;
}
//No.73
