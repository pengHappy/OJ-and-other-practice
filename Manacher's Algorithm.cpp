#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
#define MAXN 240010

char tmpStr[MAXN];
char String[MAXN];
int rad[MAXN];

/*
    求最大回文字符串的长度
*/

int manacher() {
    int ans = 0;
    int mx = 0;
    int id = 1;
    int len = strlen(String);

    for(int i = 1; i < len; i++) {
        if(mx - i > 0)
            rad[i] = min(mx - i, rad[2 * id - i]);
        else
            rad[i] = 1;
        while(String[i + rad[i]] == String[i - rad[i]])
            rad[i]++;
        if(mx < i + rad[i]) {
            mx = i + rad[i];
            id = i;
        }
        ans = max(ans, rad[i]);
    }

    return ans;
}

int main()
{
    while(true) {
        scanf("%s", tmpStr);
        if(strcmp(tmpStr, "-1") == 0)
            break;

        int len = strlen(tmpStr);
        int pos = 0;
        for(int i = 0; i < len; i++) {
            String[++pos] = '#';
            String[++pos] = tmpStr[i];
        }
        String[++pos] = '#';
        String[++pos] = '\0';
        String[0] = '$';

        int res = manacher();
        printf("%-4d\n", --res);
    }

    return 0;
}
//No. 82
