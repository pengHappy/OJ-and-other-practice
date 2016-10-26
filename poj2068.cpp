#include <iostream>
#include <stdio.h>
using namespace std;
const int MAX_N = 10;
const int MAX_S = 1 << 13;

int n, S;
int M[2][MAX_N];
int win[2][MAX_N][MAX_S];
//win[k][j][i] 第k支队伍在轮到第j名队员且剩余i块石头的状态

bool input() {
    scanf("%d %d", &n, &S);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &M[0][i], &M[1][i]);
    }
    return n > 0;
}

bool solve() {
    for(int i = 0; i <= S; i++) { //rest stone number
        for(int k = 0; k < 2; k++) { // group number
            for(int j = 0; j < n; j++) { // members
                if(i == 0) {
                    win[k][j][i] = true;
                    continue;
                }
                win[k][j][i] = false;
                int nxt_k = k ^ 1;
                int nxt_j = (k == 1? (j + 1) % n : j);
                for(int t = 1; i - t >= 0 && t <= M[k][j]; t++)
                    //!!! NOT M[nxt_k][nxt_j]
                    win[k][j][i] |= !win[nxt_k][nxt_j][i - t];
            }
        }
    }

    return win[0][0][S];
}

int main()
{
    while(input()) {
        puts(solve() == true? "1" : "0");
    }
    return 0;
}
//No. 76
