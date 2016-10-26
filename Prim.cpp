#include <iostream>
#define MAX_V 100
#define INF_INT 500
using namespace std;
int cost[MAX_V][MAX_V];
int V;

int myMin(int a, int b) {
    return (a < b? a : b);
}

int prim() {
    int mincost[MAX_V];
    bool used[MAX_V];
    int res;

    for(int i = 0; i < MAX_V; i++) {
        used[i] = false;
        mincost[i] = INF_INT;
    }

    //used[1] = true;
    mincost[1] = 0;
    res = 0;

    while(true) {
        int v = -1;
        int u;
        for(u = 1; u <= V; u++) {
            if((used[u] == false) && (v == -1 || mincost[u] < mincost[v]))
                v = u;
        }

        if(v == -1)
            break;
        used[v] = true;
        res += mincost[v]; //Great! mincost[v] has been changed by cost[u][v]

        for(u = 1; u <= V; u++) {
            mincost[u] = myMin(cost[u][v], mincost[u]);
        }
    }

    return res;
}

int main()
{
    int from, to, value;
    int res;

    for(int i = 0; i < MAX_V; i++)
        for(int j = 0; j < MAX_V; j++)
            cost[i][j] = INF_INT;

    cin >> V;

    while(true) {
        cin >> from >> to;
        if(from == 0 && to == 0)
            break;
        cin >> value;
        cost[from][to] = value;
        cost[to][from] = value;
    }

    res = prim();
    cout << res << endl;

    return 0;
}
