#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 10000 + 3;

int N, milk[MAX_N];

int same, lIndex;


void partition(int left, int right) {
    
    int pivot = milk[left];
    int l = left, h = right;
    same = 0;
    
    while(l < h) {
        
        while(l < h && milk[h] > pivot) {
            h--;
        }
        
        milk[l] = milk[h];
        
        while(l < h && milk[l] <= pivot) {
            if(milk[l] == pivot) {
                same++;
            }
            l++;
        }
        
        milk[h] = milk[l];
        
    }
    
    milk[l] = pivot;
    
    same++;
    
    lIndex = l;
    
}

int main() {
    
    scanf("%d", &N);
    
    for(int i = 1; i <= N; i++) {
        scanf("%d", milk + i);
    }
    
    
    int left = 1, right = N;
    int cmp = (N + 1) / 2;
    
    while(left <= right) {
        
        partition(left, right);
        
        int lHalf = lIndex, rHalf = same + N - lIndex;
        
        if(lHalf >= cmp && rHalf >= cmp) {
            break;
        }
        else if(lHalf < cmp) {
            left = lHalf + 1;
        }
        else {
            right = lHalf - 1;
        }
        
    }
    
    printf("%d", milk[lIndex]);
    
    return 0;
    
}