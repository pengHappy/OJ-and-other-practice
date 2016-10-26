#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#define MAX_V 3000
#define random(x) rand()%x
using namespace std;

void MinHeapFixdown(int a[], int k, int n) {
    int i = k;
    int j = k * 2 + 1;
    int item = a[k];
    while(j < n) {
        if(j + 1 < n && a[j + 1] < a[j])
            j++;
        if(item <= a[j])
            break;
        a[i] = a[j];
        i = j;
        j = i * 2 + 1;
    }
    a[i] = item;
}

void MakeMinHeap(int a[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--)
        MinHeapFixdown(a, i, n);
}

void HeapSortToDescendarry(int a[], int n) {
    for(int i = n - 1; i >= 0; i--) {
        swap(a[i], a[0]);
        MinHeapFixdown(a, 0, i);
    }
}

void Print(int a[]) {
    for(int i = 0; i < MAX_V; i++) {
        cout << setw(5) << a[i];
        if(i > 0 && (i + 1) % 15 == 0)
            cout << endl;
    }
}

int main()
{
    srand((int)time(NULL));
    int holder[MAX_V];
    for(int i = 0; i < MAX_V; i++)
        holder[i] = random(MAX_V);
    MakeMinHeap(holder, MAX_V);
    HeapSortToDescendarry(holder, MAX_V);
    Print(holder);
    return 0;
}

//No.58
