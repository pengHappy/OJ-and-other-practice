#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXN 256

//高斯消元法。但求出的序列不是最短的
int main(int argc, char *argv[])
{
    int matrix[MAXN][MAXN];
    int ans[MAXN];
    int n;
    while(true) {
        scanf("%d", &n);
        if(n == 0)
            break;

        //清空容器
        for(int i = 0; i < MAXN; i++) {
            for(int j = 0; j < MAXN; j++) {
                matrix[i][j] = 0;
            }
            ans[i] = 0;
        }


        for(int i = 1; i <= n; i++) {
            int t = 0;
            while(t != -1) {
                scanf("%d", &t);
                matrix[t][i] = 1;
            }
            matrix[i][n + 1] = 1;
        }

        for(int i = 1; i <= n; i++) {
            int col = -1;
            for(int j = i; j <= n; j++) {
                if(matrix[j][i]) {
                    col = j;
                    break;
                }
            }
            if(col == -1)
                continue;

            swap(matrix[col], matrix[i]); //整行交换

            //向下消元，形成上三角矩阵
            for(int j = i + 1; j <= n; j++) {
                if(matrix[j][i]) {
                    for(int k = i; k <= n + 1; k++) //增广矩阵包括结果的一列
                        matrix[j][k] ^= matrix[i][k];
                }
            }

        }

        //向上得出结果
        for(int i = n; i >= 1; i--) {
            ans[i] = matrix[i][n + 1];
            for(int j = i - 1; j >= 1; j--) {
                matrix[j][n + 1] ^= (ans[i] & matrix[j][i]);
            }
        }

        for(int i = 1; i <= n; i++) {
            if(matrix[i][n + 1])
                printf("%d ", i);
        }
        printf("\n");

    }
    return 0;
}
//No. 88
