#include <iostream>
#define MAX_W 9000
using namespace std;

class Weight {
    public:
        int s, e, w;
}edge[500];
int dis[101];
int N, M, W;
int all_e;

bool Bellman_Ford() {
    for(int i = 0; i < 101; i++)
        dis[i] = MAX_W;

    bool flag = false;
    for(int i = 1; i < N; i++) {
        for(int k = 0; k < all_e; k++) {
            if(dis[edge[k].e] > dis[edge[k].s] + edge[k].w) {
                dis[edge[k].e] = dis[edge[k].s] + edge[k].w;
                flag = true;
            }
        }
        if(flag == false)
            break;
    }
    for(int i = 0; i < all_e; i++) {
        if(dis[edge[i].e] > dis[edge[i].s] + edge[i].w)
            return false;
    }
    return true;
}

int main()
{
    int F;
    cin >> F;
    while(F--) {

        int S, E, T;
        all_e = 0;
        cin >> N >> M >> W;

        for(int i = 0; i < M; i++) {
            cin >> S >> E >> T;
            edge[all_e].s = S;
            edge[all_e].e = E;
            edge[all_e].w = T;
            edge[all_e + 1].s = E;
            edge[all_e + 1].e = S;
            edge[all_e + 1].w = T;
            all_e += 2;
        }

        for(int i = 0; i < W; i++) {
            cin >> S >> E >> T;
            edge[all_e].s = S;
            edge[all_e].e = E;
            edge[all_e].w = -T;
            all_e++;
        }

        if(Bellman_Ford() == false)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
