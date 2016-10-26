#include <iostream>
#include <memory.h>
using namespace std;
int colors = 0;
const int large = 500000;
int degree[large + 1] = {0};
int ancestor[large + 1];


class Trie_Tree {
    public:
        int id;
        bool flag;
        Trie_Tree *next[27];

        Trie_Tree() {
            id = 0;
            flag = false;
            memset(next, 0, sizeof(next));
        }
}root;

int find_p(int x) {
    if(ancestor[x] == x)
        return x;
    return ancestor[x] = find_p(ancestor[x]);
}

void union_set(int x, int y) {
    int px = find_p(x);
    int py = find_p(y);
    ancestor[px] = py;
}

int hash_tree(char s[]) {
    Trie_Tree *p = &root;
    int len = 0;
    while(s[len] != '\0') {
        int index = s[len] - 'a';
        len++;
        if(p->next[index] == 0) {
            p->next[index] = new Trie_Tree();
        }
        p = p->next[index];
    }
    if(p->flag == true) //The color word exists
        return p->id;
    else { //New color. Allocate an id and flag
        p->flag = true;
        p->id = ++colors;
        return p->id;
    }
}

void initSet() {
    for(int i = 1; i <= large + 1; i++)
        ancestor[i] = i;
}

int main()
{
    char a[20], b[20];
    int oddNum;
    int allAncestor;
    bool isPoss;

    initSet();
    while(true) {
        cin >> a >> b;
        if(strcmp(a, "0") == 0)
            break;
        int cA = hash_tree(a);
        int cB = hash_tree(b);
        degree[cA]++;
        degree[cB]++;
        union_set(cA, cB);
    }

    oddNum = 0;
    allAncestor = find_p(1);
    isPoss = true;
    for(int i = 1; i <= colors; i++) {
        if(degree[i] % 2 == 1) {
            if(++oddNum > 2) {
                isPoss = false;
                break;
            }
        }
        if(find_p(i) != allAncestor) {
            isPoss = false;
            break;
        }
    }

    if(oddNum == 1)
        isPoss = false;

    if(isPoss == true)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}
//No. 61


