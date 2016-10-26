#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_V 500

void mySwap(char *s, char *t) {
    char temp = *s;
    *s = *t;
    *t = temp;
}

bool IsSwap(char *holder, int Start, int End) {
    for(int j = Start; j < End; j++) {
        if(holder[j] == holder[End])
            return false;
    }
    return true;
}

void AllRange(char *holder, int k, int m) {
    if(k == m) {
        static int type = 1;
        printf("%3d: %s\n", type++, holder);
    }
    else {
        int i;
        for(i = k; i <= m; i++) {
            if(IsSwap(holder, k, i) == true) {
                mySwap(holder + k,holder + i);
                AllRange(holder, k + 1, m);
                mySwap(holder + k,holder + i);
            }
        }
    }
}

void Foo(char *holder) {
    AllRange(holder, 0, strlen(holder) - 1);
}

int main()
{
    char holder[MAX_V];
    scanf("%s", holder);
    Foo(holder);
    return 0;
}
