#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define lson(x) (x<<1)
#define rson(x) (lson(x)|1)
#define mid(x,y) ((x+y)>>1)
const int INF = 0x3f3f3f3f;
const int MAXN = 100010;

struct Node{
    int left;
	int right;
	int mark;//延时标记
	int num;
};
Node node[4*MAXN];
int n , num[MAXN];
int l[MAXN] , r[MAXN];

// 向下更新
void push_down(int pos){
	if(node[pos].mark != INF){//如果可以继续往下更新
		node[lson(pos)].mark = min(node[lson(pos)].mark , node[pos].mark);
		node[rson(pos)].mark = min(node[rson(pos)].mark , node[pos].mark);

		node[lson(pos)].num = min(node[pos].mark , node[lson(pos)].num);
		node[rson(pos)].num = min(node[pos].mark , node[rson(pos)].num);
		node[pos].mark = INF;
	}
}

void build(int left , int right , int pos){
	node[pos].left = left;
	node[pos].right = right;
	node[pos].mark = INF;
	node[pos].num = INF;
	if(left == right){
		scanf("%d" , &num[left]);
		return;
	}
	int mid = mid(left , right);
	build(left , mid , lson(pos));
	build(mid+1 , right , rson(pos));
}

void update(int left , int right , int val , int pos){
	if(left <= node[pos].left && right >= node[pos].right){
		node[pos].mark = min(node[pos].mark , val);
		node[pos].num = min(node[pos].num , node[pos].mark);
		return;
	}
	push_down(pos);// 向下更新

	int mid = mid(node[pos].left , node[pos].right);
	if(right <= mid)
		update(left , right , val , lson(pos));
	else if(left > mid)
		update(left , right , val , rson(pos));
	else{
		update(left , mid , val , lson(pos));
		update(mid+1 , right , val , rson(pos));
	}
}

int query(int index , int pos){
    if(node[pos].left == node[pos].right)
		return node[pos].num;
	int mid = mid(node[pos].left , node[pos].right);
	push_down(pos);// 向下更新

	if(index <= mid)
		return query(index , lson(pos));
	else
		return query(index , rson(pos));
}

void solve(){
	// get left and right
	for(int i = 1 ; i <= n ; i++){
		int j;
		// get left
		for(j = i-1 ; j >= 1 ; j--)
			if(num[j] > num[i])
				break;
		l[i] = j+1;
		// get right
		for(j = i+1 ; j <= n ; j++)
			if(num[j] > num[i])
				break;
		r[i] = j-1;
	}
	// update
	for(int i = 1 ; i <= n ; i++)
		update(1 , r[i]-l[i]+1 , num[i] , 1);
	for(int i = 1 ; i <= n ; i++)
		printf("%d\n" , query(i , 1));
}


int main(){
    int cas;
	scanf("%d" , &cas);
	while(cas--){
		scanf("%d" , &n);
		build(1 , n , 1);
		solve();
	}
	return 0;
}
//No.71
