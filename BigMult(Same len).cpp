#include <stdio.h>
#include <memory.h>
#define MAX_L 30
char a[MAX_L], b[MAX_L];
int c[MAX_L * 2];
int len;

void init() {
    char a_holder[MAX_L], b_holder[MAX_L];
    memset(a, '\0', sizeof(a));
    memset(b, '\0', sizeof(b));
    for(int i = 0; i < MAX_L * 2; i++)
        c[i] = 0;
    scanf("%s", a_holder);
    scanf("%s", b_holder);
    len = 0;
    while(a_holder[len] != '\0')
        len++;
    for(int i = len - 1, k = 0; i >= 0; i--, k++) {
        a[k] = a_holder[i];
        b[k] = b_holder[i];
    }
}

void calculate() {
    int i, k, j;
    for(k = 0; k < len; k++) {
        for(i = 0; i < len; i++) {
            int item1 = b[k] - '0';
            int item2 = a[i] - '0';
            c[i + k] += item1 * item2;
        }
    }
    int fromPrev = c[0] / 10;
    for(j = 1; j <= 2*len - 1; j++) {
        int thisRes = c[j] % 10;
        int toNext = c[j] / 10;
        thisRes += fromPrev;
        if(thisRes >= 10) {
            thisRes %= 10;
            toNext += 1;
        }
        c[j] = thisRes;
        fromPrev = toNext;
    }
    c[0] = c[0] % 10;
}

int main()
{
    init();
    calculate();
    for(int i = 2*len - 1; i >= 0; i--) {
        if((c[i] == 0) && (i == 2*len - 1))
            continue;
        printf("%d", c[i]);
    }
    return 0;
}
