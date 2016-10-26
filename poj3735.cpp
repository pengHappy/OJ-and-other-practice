#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdio.h>
using namespace std;
#define ll long long
#define MAX_N 100

class Matrix {
    public:
        ll val[MAX_N][MAX_N];
        int height, weight;

        Matrix() {}
        Matrix(int height, int weight) : height(height), weight(weight) {
            zero();
        }

        void zero() {
            memset(val, 0, sizeof(val));
        }

        void unit() {
            zero();
            height = max(height, weight);
            weight = max(height, weight);
            for(int i = 0; i < height; i++)
                val[i][i] = 1;
        }

        Matrix operator * (const Matrix &m) {
            Matrix res;
            for(int i = 0; i < height; i++) {
                for(int k = 0; k < weight; k++) {
                    res.val[i][k] = 0;
                    for(int j = 0; j < height; j++) {
                        if(val[i][j] > 0)
                            res.val[i][k] += val[i][j] * m.val[j][k];
                    }
                }
            }
            return res;
        }

        static Matrix create_identity(int _size) {
            Matrix ret(_size, _size);
            for(int i = 0; i < _size; i++)
                ret.val[i][i] = 1;
            return ret;
        }

        Matrix operator ^ (const ll N) {
            Matrix ret = create_identity((*this).weight);
            for(ll e = N; e > 0; e >>= 1) {
                if(e & 1 == 1)
                    ret = ret * (*this);
                (*this) = (*this) * (*this);
            }
            return ret;
        }

};

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    Matrix A(1, n + 1);
    A.val[0][0] = 1;
    Matrix T(n + 1, n + 1);
    T.unit();

    while(k--) {
        getchar();
        char holder;
        int Num;
        scanf("%c", &holder);
        if(holder == 'g') {
            scanf("%d", &Num);
            T.val[0][Num]++;
        }
        else if(holder == 'e') {
            scanf("%d", &Num);
            for(int i = 0; i < n + 1; i++)
                T.val[i][Num] = 0;
        }
        else if(holder == 's') {
            int i;
            int j;
            scanf("%d %d", &i, &j);
            for(int k = 0; k < n + 1; k++) {
                int item = T.val[k][i];
                T.val[k][i] = T.val[k][j];
                T.val[k][j] = item;
            }
        }
    }

    Matrix R = A * (T ^ m);
    for(int i = 1; i <= n; i++)
        printf("%-4d", R.val[0][i]);

    return 0;
}
//No. 74







