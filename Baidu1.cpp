#include <stdio.h>
const int large = 10;

void FindTwoNoRepeat(int a[], int N, int *Num1, int *Num2) {
    int pivot = 0;
    int i;
    int j;
    for(i = 0; i < N; i++)
        pivot ^= a[i];

    j = 0;
    while(((pivot >> j) & 1) == 0) { //find the bit that 1 first appears
        j++;
    }

    *Num1 = 0;
    *Num2 = 0;
    for(i = 0; i < N; i++) {
        if(((a[i] >> j) & 1) == 0)
            *Num1 ^= a[i];
        else
            *Num2 ^= a[i];
    }

    printf("%4d %4d", *Num1, *Num2);
}

void PrintArray(int a[], int N) {
    for(int i = 0; i < N; i++)
        printf("%4d ", a[i]);
    printf("\n");
}

int main()
{
    //int holder[large] = {1, 6, 9, 15, 8, 6, 9, 2, 1, 15};
    int holder[large] = {1, 6, 9, 2, 8, 6, 9, 2, 8, 15};
    int Num1, Num2;
    PrintArray(holder, large);
    FindTwoNoRepeat(holder, large, &Num1, &Num2);
    return 0;
}
//No. 63
