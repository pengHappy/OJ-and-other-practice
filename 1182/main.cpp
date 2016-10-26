#include <iostream>
#include <memory.h>
#include <BSet.h>
#define MAX_K 200
using namespace std;
int N, K;
int T[MAX_K], X[MAX_K], Y[MAX_K];
int ans;
int res[MAX_K];
BSet bset;

void initParam() {
    cin >> N >> K;
    for(int i = 0; i < K; i++) {
        cin >> T[i] >> X[i] >> Y[i];
    }
    memset(res, -1, sizeof(res));
}

void solve() {
    ans = 0;
    int step = 0;
    for(int i = 0 ;i < K; i++) {
        int t = T[i];
        int x = X[i] - 1;
        int y = Y[i] - 1;

        if(x < 0 || x >= N || y < 0 || y >= N) {
            ans++;
            res[step++] = i + 1;
            continue;
        }

        if(t == 1) {
            if(bset.same(x, y + N) || bset.same(x, y + N * 2)) {
                ans++;
                res[step++] = i + 1;
            }
            else {
                bset.unit(x, y);
                bset.unit(x + N, y + N);
                bset.unit(x + N * 2, y + N * 2);
            }
        }

        if(t == 2) {
            if(bset.same(x, y) || bset.same(x, y + N * 2)) {
                ans++;
                res[step++] = i + 1;
            }

            else {
                bset.unit(x, y + N);
                bset.unit(x + N, y + N * 2);
                bset.unit(x + N * 2, y);
            }
        }
    }
}

int main()
{
    initParam();
    bset = BSet();
    bset.init(N * 3);
    solve();
    cout << ans << endl;
    for(int i = 0; res[i] != -1; i++)
        cout << res[i] << endl;
    return 0;
}
