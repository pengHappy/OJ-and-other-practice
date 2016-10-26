#include <iostream>
#include <algorithm>
#define MAX_E 100
using namespace std;
int par[MAX_E];
int rank_v[MAX_E];

void init_union(int V) {
    for(int i = 0; i < V; i++) {
        rank_v[i] = 0;
        par[i] = i;
    }
}

int find_p(int x) {
    if(par[x] == x)
        return x;
    return (par[x] = find_p(par[x]));
}

void unite(int x, int y) {
    x = find_p(x);
    y = find_p(y);
    if(x == y)
        return;

    if(rank_v[x] < rank_v[y])
        par[x] = y;
    else
        par[y] = x;
    if(rank_v[x] == rank_v[y])
        rank_v[x]++;
}

bool same(int x, int y) {
    return find_p(x) == find_p(y);
}

typedef struct {
    int u;
    int v;
    int cost;
}edge;

bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}

int main()
{
    edge es[MAX_E];
    int V, E;
    int res;

    cin >> V;
    E = 0;
    while(true) {
        int from, to;
        cin >> from >> to;
        if(from == 0 && to == 0)
            break;
        es[E].u = from;
        es[E].v = to;
        cin >> es[E].cost;
        E++;
    }

    sort(es, es + E, comp);
    init_union(V);
    res = 0;

    for(int i = 0; i < E; i++) {
        edge e = es[i];
        if(same(e.u, e.v) == false) {
            unite(e.u, e.v);
            res += e.cost;
        }
    }

    cout << res << endl;
    return 0;
}

