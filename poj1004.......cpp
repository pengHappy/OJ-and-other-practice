#include <stdio.h>
int main()
{
    int cnt = 12;
    double sum = 0.00;
    while(cnt--) {
        double holder;
        scanf("%lf", &holder);
        sum += holder;
    }
    printf("$%.2f\n", sum / 12.00);
    return 0;
}
//No. 100
