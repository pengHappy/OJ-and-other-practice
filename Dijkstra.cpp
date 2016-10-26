#include <iostream>
#include <memory.h>
#define INF 900
#define MAX_V 200
using namespace std;

int cost[MAX_V][MAX_V];
int d[MAX_V];
bool used[MAX_V];
int V;

int myMin(int a, int b) {
    return (a < b? a : b);
}

void dijkstra(int s) {
    //memset(d, INF, sizeof(d));
    for(int i = 0; i < MAX_V; i++) {
        d[i] = INF;
    }
    memset(used, false, sizeof(used));
    d[s] = 0;

    while(true) {
        int v = -1;
        for(int i = 0; i < V; i++) {
            if((false == used[i]) && (v == -1 || d[i] < d[v]))
                v = i;
        }
        if(v == -1)
            break;
        used[v] = true;
        for(int u = 0; u < V; u++) {
            d[u] = myMin(d[u], d[v] + cost[v][u]);
        }
    }
}

int main()
{
    cin >> V;
    for(int i = 0; i < MAX_V; i++)
        for(int k = 0; k < MAX_V; k++)
            cost[i][k] = INF;

    while(true) {
        int from, to;
        cin >> from >> to;
        if(from == 0 && to == 0)
            break;
        cin >> cost[from][to];
        cost[to][from] = cost[from][to];
    }
    dijkstra(0);
    for(int i = 0; i < V; i++) {
        cout << d[i] << " ";
    }
    return 0;
}
