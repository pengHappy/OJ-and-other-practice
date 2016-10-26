#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#define MAX_V 500
#define random(x) (rand()%x)
using namespace std;

void ShellSort(int len, int holder[]) {
    int gap;
    int i, j;
    for(gap = len/2; gap >= 1; gap /= 2) {
        for(i = 0; i < gap; i++) {
            for(j = i + gap; j < len; j += gap) {
                int k = j - gap;
                if(holder[k] > holder[j]) {
                    int item = holder[j];
                    while(k >= 0 && item < holder[k]) {
                        holder[k + gap] = holder[k];
                        k -= gap;
                    }
                    holder[k + gap] = item;
                }
            }
        }
    }
}

int main()
{
    srand((int)time(NULL));
    int holder[MAX_V];
    for(int i = 0; i < MAX_V; i++)
        holder[i] = random(MAX_V);
    ShellSort(MAX_V, holder);
    for(int i = 0; i < MAX_V; i++) {
        cout << setw(4) << holder[i];
        if(i > 0 && (i + 1) % 15 == 0)
            cout << endl;
    }
    return 0;
}
