#include <iostream>
#include <memory.h>
using namespace std;
const int _size = 1001;
struct Node {
    int id;
    struct Node *next;
};

class solve {
    protected:
        int cases; // According to Input
        Node *ListTable_Head[_size];
        int Root;
        int deep[_size];
        int AnceDeep[_size];
        int color[_size];
        bool cut[_size];
        bool SPF;
        int Subnet_Num; // SPF Nodes Number
        bool visit[_size];
    public:
        solve():cases(0) {
            for(int i = 0; i < _size; i++)
                ListTable_Head[i] = 0;
            DFS();
        }
        ~solve() {
            delete[] *ListTable_Head;
        }
        int _min(int a, int b) const {return a < b? a : b;}
        bool Input(void);
        void Insert(int x, int y);
        void DFS(void);
        void DFS_SPF(int k, int father, int depth);
        void DFS_Subnet(int i);
        void Empty(void);
        void Del(Node *p);
};

bool solve::Input() {
    int x, y;
    int i = 0;
    while(true) {
        cin >> x;
        if(x == 0 && i ==0)
            break;
        if(x == 0 && i > 0)
            return true;
        cin >> y;
        Insert(x, y);
        i++;
    }
    return false;
}

void solve::Insert(int x, int y) {
    if(ListTable_Head[x] == 0) {
        ListTable_Head[x] = new Node;
        ListTable_Head[x]->next = 0;
    }
    if(ListTable_Head[y] == 0) {
        ListTable_Head[y] = new Node;
        ListTable_Head[y]->next = 0;
    }
    Node *px = ListTable_Head[x]->next;
    Node *py = ListTable_Head[y]->next;
    Node *newPt = 0;

    newPt = new Node;
    newPt->id = y;
    newPt->next = px;
    ListTable_Head[x]->next = newPt;

    newPt = new Node;
    newPt->id = x;
    newPt->next = py;
    ListTable_Head[y]->next = newPt;
}

void solve::DFS(void) {
    while(Input() == true) {
        SPF = false;
        memset(deep, 0, sizeof(deep));
        memset(AnceDeep, 0, sizeof(AnceDeep));
        memset(color, 0, sizeof(color));
        for(int i = 0; i < _size; i++)
            cut[i] = false;

        for(int k = 1; k < _size; k++) {
            if(ListTable_Head[k]) {
                Root = k;
                break;
            }
        }

        DFS_SPF(Root, Root, 1);

        cout << "Network #" << ++cases << endl;
        if(SPF == false)
            cout << "No SPF nodes" << endl;
        else {
            for(int i = Root; i < _size; i++) {
                if(cut[i] == true) {
                    Subnet_Num = 0;
                    for(int j = 0; j < _size; j++)
                        visit[j] = false;
                    visit[i] = true;

                    for(Node *p = ListTable_Head[i]->next; p; p = p->next) {
                        if(visit[p->id] == false) {
                            Subnet_Num++;
                            DFS_Subnet(p->id);
                        }
                    }
                    cout<<"  SPF node "<< i <<" leaves "<< Subnet_Num <<" subnets" << endl;
                }
            }
        }
        cout << endl;
        Empty();
    }
    return;
}

void solve::DFS_SPF(int k, int father, int depth) {
    color[k] = 1;
    deep[k] = depth;
    AnceDeep[k] = depth;
    int sons = 0;

    for(Node *p = ListTable_Head[k]->next; p; p = p->next) {
        int i = p->id;
        if(color[i] == 0) { // Never visited before
            sons++;
            DFS_SPF(i, k, depth + 1);
            AnceDeep[k] = _min(AnceDeep[k], AnceDeep[i]);
        }
        if(i != father && color[i] == 1) {
            AnceDeep[k] = _min(AnceDeep[k], AnceDeep[i]);
        }
        if((k == Root && sons >= 2) ||
              (k != Root && AnceDeep[i] >= deep[k])) {
           cut[k] = true;
           SPF = true;
        }
    }
    color[k] = 2;
    return;
}

void solve::DFS_Subnet(int id) {
    for(Node *p = ListTable_Head[id]->next; p; p = p->next) {
        int i = p->id;
        if(visit[i] == false) {
            visit[i] = true;
            DFS_Subnet(i);
        }
    }
    return;
}

void solve::Empty(void) {
    for(int i = 0; i < _size; i++) {
       Del(ListTable_Head[i]) ;
       ListTable_Head[i] = 0;
    }
}

void solve::Del(Node *p) {
    Node *head = p;
    Node *nextPt = 0;
    if(head) {
        while(head) {
            nextPt = head->next;
            delete head;
            head = nextPt;
        }
    }
}

int main()
{
    solve POJ1523 = solve();
    return 0;
}
//No. 65
