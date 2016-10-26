#include "BSet.h"
#include <iostream>
using namespace std;

BSet::BSet()
{
    //ctor
}

void BSet::init(int N) {
    for(int i = 0; i < N; i++) {
        par[i] = i;
        rank[i] = 0;
    }
}

int BSet::find(int i) {
    if(par[i] == i)
        return i;
    else
        return par[i] = find(par[i]);
}

void BSet::unit(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y)
        return;

    if(rank[x] < rank[y])
        par[x] = y;
    else {
        if(rank[x] == rank[y])
            rank[x]++;
        par[y] = x;
    }
}

bool BSet::same(int x, int y) {
    return find(x) == find(y);
}

BSet::~BSet()
{
    //dtor
}
