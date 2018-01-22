#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAX_N = 22;

int N, c[MAX_N][MAX_N], group[MAX_N];
int res;


void dfs(int index, int sum) {
    
    res = max(res, sum);
    
    int orgSum = sum;
    
    for(int i = index; i <= N; i++) {
        
        sum = orgSum;
        
        // pick one in group 0, make it into group 1
        for(int j = 1; j <= N; j++) {
            
            if(group[j] == 1) {
                
                sum -= c[i][j];
                
            }
            
        }
        
        group[i] = 1;
        
        for(int j = 1; j <= N; j++) {
            
            if(group[j] == 0) {
                
                sum += c[i][j];
                
            }
            
        }
        
        // recur into the next index
        dfs(i + 1, sum);
        
        // recover
        group[i] = 0;
        
    }
    
}

int main() {
    
    scanf("%d", &N);
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    
    //initialization
    memset(group, 0, sizeof(group));
    
    
    // dfs
    dfs(1, 0);
    
    
    printf("%d\n", res);
    
    return 0;
}