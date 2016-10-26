#include <stdio.h>
#include <memory.h>
#define MAX_L 30
char a[MAX_L], b[MAX_L];
int c[MAX_L * 2];
int len;
int len_a, len_b;

int myMax(int a, int b) {
    return (a > b? a : b);
}

void init() {
    char a_holder[MAX_L], b_holder[MAX_L];
    memset(a, '\0', sizeof(a));
    memset(b, '\0', sizeof(b));
    for(int i = 0; i < MAX_L + 1; i++)
        c[i] = 0;
    scanf("%s", a_holder);
    scanf("%s", b_holder);

    //Get max length
    len = 0;
    len_a = 0;
    len_b = 0;
    while(a_holder[len_a] != '\0')
        len_a++;
    while(b_holder[len_b] != '\0')
        len_b++;
    len = myMax(len_a, len_b);

    //Reverse
    for(int i = len_a - 1, k = 0; i >= 0; i--, k++) {
        a[k] = a_holder[i];
    }
    for(int i = len_b - 1, k = 0; i >= 0; i--, k++) {
        b[k] = b_holder[i];
    }

    //Convert '\0' to '0'
    if(len_a > len_b) {
        for(int j = len_b; j < len_a; j++)
            b[j] = '0';
    }
    else {
        for(int j = len_a; j < len_b; j++)
            a[j] = '0';
    }
}

void calculate() {
    int i;
    for(i = 0; i < len; i++) {
        int item1 = a[i] - '0';
        int item2 = b[i] - '0';
        c[i] += item1 + item2;
        if(c[i] >= 10) {
            c[i + 1]++;
            c[i] %= 10;
        }
    }
}

int main()
{
    init();
    calculate();
    if(c[len] > 0)
        printf("%d", c[len]);
    for(int i = len - 1; i >= 0; i--)
        printf("%d", c[i]);
    return 0;
}
