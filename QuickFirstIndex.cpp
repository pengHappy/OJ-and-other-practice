#include <stdio.h>
#include <cmath>
using namespace std;
const int large = 10;

int QuickFindFirst(int a[], int N, int foundNum) {
    int nextIndex = abs(foundNum - a[0]);
    int res = -1;
    while(nextIndex < N) {
        if(a[nextIndex] == foundNum) {
            res = foundNum;
            break;
        }
        else
            nextIndex += abs(foundNum - a[nextIndex]);
    }
    return nextIndex;
}

void PrintArray(int a[], int N) {
    for(int i = 0; i < N; i++)
        printf("%4d ", a[i]);
    printf("\n\n");
}

int main()
{
    //int holder[large] = {1, 2, 3, 2, 3, 4, 5, 6, 7, 6};
    int holder[large] = {5, 6, 5, 4, 3, 2, 3, 4, 5, 6};
    PrintArray(holder, large);
    for(int i = 0; i < large; i++) {
        printf("%4d %4d\n", holder[i], QuickFindFirst(holder, large, holder[i]));
    }
    return 0;
}
//No. 64
