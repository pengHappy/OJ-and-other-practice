#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#define MAX_V 800
#define LINE_NUM 15
#define random(x) (rand()%x)
using namespace std;
int L[MAX_V + 1];

int Partition(int _low, int _high) {
    int pivot = L[_low];
    int low = _low;
    int high = _high;
    while(low < high) {
        while(low < high && L[high] >= pivot)
            high--;
        L[low] = L[high];
        while(low < high && L[low] <= pivot)
            low++;
        L[high] = L[low];
    }
    L[low] = pivot;
    return low;
}

void QSort(int low, int high) {
    int pivotLoc;
    if(low < high) {
        pivotLoc = Partition(low, high);
        QSort(low, pivotLoc - 1);
        QSort(pivotLoc + 1, high);
    }
}

int main()
{
    srand((int)time(NULL));
    for(int i = 0; i <= MAX_V; i++)
        L[i] = random(MAX_V);
    QSort(0, MAX_V);
    for(int i = 0; i <= MAX_V; i++) {
        cout << setw(4) << L[i] << " ";
        if(i > 0 && (i + 1) % LINE_NUM == 0)
            cout << endl;
    }
    return 0;
}
