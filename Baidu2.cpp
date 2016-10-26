#include <iostream>
#include <memory.h>
using namespace std;
const int _size = 10;
const int _sizeBit = 20;

int myPower(int n) {
    int res = 1;
    while(n--)
        res *= 2;
    return res;
}

int findTheOne(int holder[], int _size) {
    int k, i;
    int item;
    int res;
    int bitSt[_sizeBit];
    memset(bitSt, 0, sizeof(bitSt));
    for(k = 0; k < _size; k++) {
        item = holder[k];
        for(i = 0; item > 0; i++) {
            if((item & 1) == 1)
                bitSt[i]++;
            item >>= 1;
        }
    }
    for(k = 0, res = 0; k < _sizeBit; k++) {
        bitSt[k] %= 3;
        if(bitSt[k] == 1)
            res += myPower(k);
    }
    return res;
}

int main()
{
    int holder[_size] = {7, 2, 9, 7, 9, 2, 2, 9, 2048, 7};
    cout << findTheOne(holder, _size) << endl;
}
//No. 66
