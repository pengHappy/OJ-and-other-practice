#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
const int MAX_N = 100;

double resistor[MAX_N][MAX_N];
double voltage[MAX_N];

template<class T>
void gaussian_elimination(vector<vector<T> > &a, vector<T> &b) {
    //前提： 线性方程一定有解
    const int N = a.size();
    const int M = a[0].size();

    for(int i = 0, p = 0; i < M; i++, p++) {
        int q;
        for(q = p; q < N && a[q][i] == 0; q++);
        if(q == N) {
            p--;
            continue;
        }
        swap(a[i], a[q]);
        swap(b[i], b[q]);

        const T r = 1.0 / a[i][i];
        for(int j = i; j < M; j++) {
            a[i][j] = a[i][j] * r;
        }
        b[i] = b[i] * r;

        for(int j = 0; j < N; j++) {
            if(j == i)
                continue;
            const T t = a[j][i];
            for(int k = i; k < M; k++)
                a[j][k] = a[j][k] - t * a[i][k];
            b[j] = b[j] - t * b[i];
        }
    }

    /*for(int k = 0; k < N; k++) {
        if(a[k][k] == 0 && b[k] != 0)
            return false;
        //a[k][k] = b[k];
    }

    return true;*/
}

int main()
{
    int N, M;
    while(true) {
        scanf("%d %d", &N, &M);
        if(N == 0 && M == 0)
            break;

        for(int i = 0; i < MAX_N; i++)
            for(int j = 0; j < MAX_N; j++)
                resistor[i][j] = 0.0;

        for(int i = 0; i < M; i++) {
            int x, y, r;
            scanf("%d %d %d", &x, &y, &r);
            resistor[x - 1][y - 1] += 1.0 / r;
            resistor[y - 1][x - 1] += 1.0 / r;
        }

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                resistor[i][j] = 1.0 / resistor[i][j];

        vector<vector<double> > matrix(N, vector<double>(N, 0));
        vector<double> voltage(N, 0);
        voltage[0] = 1.0;
        voltage[N - 1] = 0.0;
        matrix[0][0] = 1.0;
        matrix[N - 1][N - 1] = 1.0;

        for(int node = 1; node < N - 1; node++) {
            for(int other = 0; other < N; other++) {
                if(resistor[node][other] > 0) {
                    double inv = 1.0 / resistor[node][other];
                    matrix[node][node] -= inv;
                    matrix[node][other] += inv;
                }
            }
        }

        gaussian_elimination(matrix, voltage);
            double current = 0;
            for(int node = 1; node < N; node++) {
                if(resistor[0][node] > 0)
                    current += (voltage[0] - voltage[node]) / resistor[0][node];
            }
            printf("%.2f\n", 1.0 / current);
        /*}
        else
            puts("??");*/
    }

    return 0;
}
//No. 80
