#include <iostream>
#include <stdio.h>
using namespace std;
const int _size = 500;

int goUnit(int n) {
    int res = 1;
    while(n > 1) {
        res *= n;
        while(res % 10 == 0)
            res /= 10;
        res %= 100000;
        n--;
    }
    return (res % 10);
}

int main()
{
    int item[_size];
    int ans[_size];
    int i = 0;
    while(true) {
        cin >> item[i];
        if(item[i] == 0)
            break;
        ans[i] = goUnit(item[i]);
        i++;
    }
    for(int j = 0; j < i; j++) {
        cout << item[j] << " -> " << ans[j] << endl;
    }
    return 0;
}
//No. 69
