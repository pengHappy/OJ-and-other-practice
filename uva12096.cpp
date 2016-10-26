#include <iostream>
#include <map>
#include <stack>
#include <set>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
set<int> s1, s2;
stack<set<int> > stk;
int cnt;

void Pop() {
    s1 = stk.top();
    stk.pop();
    s2 = stk.top();
    stk.pop();
}

void Push() {
    set<int> holder;
    stk.push(holder);
    puts("0");
}

void Dup() {
    set<int> holder = stk.top();
    stk.push(holder);
    printf("%d\n", holder.size());
}

void Union() {
    Pop();
    set<int>::iterator it;
    for(it = s1.begin(); it != s1.end(); it++)
        s2.insert(*it);
    stk.push(s2);
    printf("%d\n", s2.size());
}

void Intersect() {
    Pop();
    set<int> res;
    set<int>::iterator it;
    for(it = s1.begin(); it != s1.end(); it++)
        if(s2.find(*it) != s2.end())
            res.insert(*it);
    stk.push(res);
    printf("%d\n", res.size());
}

void Add() {
    Pop();
    int _size;
    if(s1.size() == 0 && s2.size() == 0) {
        s2.insert(cnt++);
        stk.push(s2);
        _size = s2.size();
    }
    else if(s1.size() == 0) {
        stk.push(s2);
        _size = s2.size();
    }
    else if(s2.size() == 0) {
        stk.push(s1);
        _size = s1.size();
    }
    else {
        s2.insert(cnt++);
        stk.push(s2);
        _size = s2.size();
    }
    printf("%d\n", _size);
}

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        int cardinality;
        char input[20];
        scanf("%d", &cardinality);
        while(cardinality--) {
            scanf("%s", input);
            switch(input[0]) {
                case 'P':
                    Push();
                    break;
                case 'D':
                    Dup();
                    break;
                case 'A':
                    Add();
                    break;
                case 'I':
                    Intersect();
                    break;
                case 'U':
                    Union();
                    break;
                default: break;
            }
        }
    }
    return 0;
}
//No.72
