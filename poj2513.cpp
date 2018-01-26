#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 250000;

typedef struct TrieNode {
    
    int id;
    TrieNode *next[26];
    
    TrieNode() {
        id = 0;
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
    
} TrieNode;


int degree[MAX_N * 2 + 3], u[MAX_N * 2 + 3], lastId;

TrieNode *root;


int insert(char *word) {
    
    int len = (int) strlen(word);
    TrieNode *p = root;
    
    for(int i = 0; i < len; i++) {
        
        char ch = word[i];
        
        if(p->next[ch - 'a'] == NULL) {
            p->next[ch - 'a'] = new TrieNode();
        }
        
        p = p->next[ch - 'a'];
        
    }
    
    if(p->id == 0) {
        p->id = ++lastId;
    }
    
    return p->id;
    
}

int find(int x) {
    
    while(u[x] != x) {
        u[x] = u[u[x]];
        x = u[x];
    }
    
    return x;
    
}

void unionRoots(int x, int y) {
    
    int rx = find(x);
    int ry = find(y);
    
    u[rx] = ry;
    
}

void init() {
    
    root = new TrieNode();
    
    lastId = 0;
    
    for(int i = 1; i <= MAX_N * 2; i++) {
        u[i] = i;
    }
    
    memset(degree, 0, sizeof(degree));
    
}

int main() {
    
    char w1[12], w2[12];
    
    int id1, id2;
    
    int uNum = 0, oddDegree = 0;
    
    
    init();
    
    while(scanf("%s %s", w1, w2) != EOF) {
        
        id1 = insert(w1);
        id2 = insert(w2);
        
        degree[id1]++;
        degree[id2]++;
        
        unionRoots(id1, id2);
        
    }
    
    for(int i = 1; i <= lastId; i++) {
        
        if(degree[i] % 2 == 1) {
            oddDegree++;
        }
        
        if(find(i) == i) {
            uNum++;
        }
        
    }
    
    if(uNum <= 1 && (oddDegree == 0 || oddDegree == 2)) {
        printf("Possible");
    }
    else {
        printf("Impossible");
    }
    
    return 0;
    
}
