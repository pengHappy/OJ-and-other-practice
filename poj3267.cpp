#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAX_L = 303;
const int MAX_W = 603;
const int MAX_LEN = 26;

int W, L, dp[MAX_L];
char msg[MAX_L], dic[MAX_W][MAX_LEN];


int main() {
    
    scanf("%d %d", &W, &L);
    
    scanf("%s", msg);
    
    for(int i = 0; i < W; i++) {
        scanf("%s", dic[i]);
    }
    
    
    for(int i = 1; i <= L; i++) {
        
        dp[i] = dp[i - 1] + 1;
        
        for(int j = 0; j < W; j++) {
            
            int h;
            int len = (int) strlen(dic[j]);
            int p = len - 1;
            
            for(h = i - 1; h >= 0; h--) {
                
                if(msg[h] == dic[j][p]) {
                    
                    p--;
                    
                    if(p < 0) { // get a matching sequence
                        break;
                    }
                    
                }
                
            }
            
            if(p < 0) {
                dp[i] = min(dp[i], dp[h] + i - h - len);
            }
            
        }
        
    }
    
    printf("%d\n", dp[L]);
    
    return 0;
}