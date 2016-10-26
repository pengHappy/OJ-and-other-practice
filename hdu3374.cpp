#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAXN 4000
using namespace std;
int len;
int next[MAXN/2];
char String[MAXN];
char minString[MAXN/2] , maxString[MAXN/2];
int minTimes , maxTimes;
int minRank , maxRank;

int myMin(int a, int b) {
    return a < b? a : b;
}

int getRankMin(char p[]) {
    int i = 0, j = 1;
    int k = 0;
    while(i + k < len && j + k < len) {
        if(p[i + k] == p[j + k])
            k++;
        else {
            if(p[i + k] > p[j + k])
                i = i + k +1;
            else
                j = j + k + 1;
        }
        if(i == j)
            j = i + 1;
    }
    return myMin(i, j);
}

int getRankMax(char p[]) {
    int i = 0, j = 1;
    int k = 0;
    while(i + k < len && j + k < len) {
        if(p[i + k] == p[j + k])
            k++;
        else {
            if(p[i + k] < p[j + k])
                i = i + k +1;
            else
                j = j + k + 1;
        }
        if(i == j)
            j = i + 1;
    }
    return myMin(i, j);
}

void getNext(char pattern[]) {
    int length = strlen(pattern);
    int i = 1;
    int j = 0;
    next[0] = 0;
    next[1] = 0;
    while(i < length) {
        j = next[i];
        while(j > 0 && pattern[j] != pattern[i])
            j = next[j];
        next[i + 1] = pattern[j] == pattern[i]? j + 1 : 0;
        i++;
    }
}

void getMinString() {
    int pos = 0;
    for(int i = minRank; i < minRank + len/2; i++)
        minString[pos++] = String[i];
    minString[pos] = '\0';
    printf("%s\n", minString);
    getNext(minString);
}

void getMaxString() {
    int pos = 0;
    for(int i = maxRank; i < maxRank + len/2; i++)
        maxString[pos++] = String[i];
    maxString[pos] = '\0';
    printf("%s\n", maxString);
    getNext(maxString);
}

int _find(char pattern[]) {
    int Num = 0;
    int i;
    int j;
    for(i = 0, j = 0; i < len - 1; i++) {
        while(j > 0 && pattern[j] != String[i])
            j = next[j];
        if(pattern[j] == String[i])
            j++;
        if(j == len/2) {
            Num++;
            //j = 0;
        }
    }
    return Num;
}

int main()
{
    while(true) {
        scanf("%s", String);
        if(strcmp(String, "0") == 0)
            break;
        char holder[MAXN];
        memcpy(holder, String, sizeof(String));
        strcat(String, holder);
        len = strlen(String);

        minRank = getRankMin(String);
        getMinString();
        minTimes = _find(minString);

        maxRank = getRankMax(String);
        getMaxString();
        maxTimes = _find(maxString);

        printf("%-4d%-4d%-4d%-4d\n", minRank+1, minTimes, maxTimes+1, maxTimes);

    }
}
//No.68
