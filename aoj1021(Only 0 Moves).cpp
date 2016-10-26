#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
const int endOfDP = 7;
const string orgSorted = "0123567";
const int downStep = 4;

map<string, int> dp;
int direction[4] = {1, -1, downStep, -downStep};

void bfs() {
    queue<string> que;
    que.push(orgSorted);
    dp[orgSorted] = 0;

    while(!que.empty()) {
        string now = que.front();
        que.pop();

        //find the location of '0'
        int p = 0;
        while(p < now.size()) {
            if(now[p] == '0')
                break;
            p++;
        }

        for(int i = 0; i < 4; i++) {
            int n = p + direction[i];
            if(0 <= n && n <= endOfDP && !(p == 3 && i == 0) && !(p == 4 && i == 1)) {
                string _next = now;
                swap(_next[p], _next[n]);
                if(dp.find(_next) == dp.end()) {
                    dp[_next] = dp[now] + 1;
                    que.push(_next);
                }
            }
        }
    }
}

int main()
{
    bfs();
    while(true) {
        string holder;
        getline(cin, holder);
        if(holder == "0")
            break;
        cout << dp[holder] << endl;
    }
    return 0;
}
//No. 77
