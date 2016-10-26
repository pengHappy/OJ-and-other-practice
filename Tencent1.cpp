#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#define random(x) rand()%x
using namespace std;
const int N = 8;
typedef long long ll;

int main()
{
    ll a[N];
    ll b[N];
    int i, j;

    srand((int)time(NULL));
    for(i = 0; i < N; i++) {
        a[i] = random(N) + 1;
        b[i] = 1;
    }

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            if(j == i)
                continue;
            b[i] *= a[j];
        }
    }

    cout << "A:" << endl;
    for(i = 0; i < N; i++) {
        cout << setw(6) << a[i];
        if(i > 0 && (i + 1) % 10 == 0)
            cout << endl;
    }
    cout << endl;

    cout << "B:" << endl;
    for(i = 0; i < N; i++) {
        cout << setw(6) << b[i];
        if(i > 0 && (i + 1) % 10 == 0)
            cout << endl;
    }
    return 0;
}
//No. 62


