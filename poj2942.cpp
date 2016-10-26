//Memory  Time
//632K	 2469MS
#include<memory.h>
#include<iostream>
#include<stack>
#include<stdio.h>
using namespace std;

/*结点存储结构*/
class Node
{
public:
	int id;
	class Node* next;
	Node():id(0),next(0){}
};

/*边存储结构*/
class Edge
{
public:
	Edge(int x=0,int y=0):s(x),t(y){}	//初始化
	Edge(const Edge& c):s(c.s),t(c.t){}	//复制

	int u(void) const{return s;}
	int v(void) const{return t;}

protected:
	int s,t;	//边s->t
};

bool operator==(Edge a,Edge b)	//协助函数:==运算符重载
{
	return a.u()==b.u() && a.v()==b.v();
}

/*********************************************************/
class solve
{
public:
	solve(int n=0,int m=0):N(n),M(m)
	{
		Initial();
		Input();
		Struct_G();

		for(int i=1;i<=N;i++)	//图G的补图可能不连通
			if(!DFN[i])
				Tarjan(i,-1);

		/*统计留席的骑士数*/
		int NotFireNum=0;
		for(int j=1;j<=N;j++)
			if(NotFire[j])
				NotFireNum++;
		printf("%d\n",N-NotFireNum); //总数减去留席骑士数，就是被剔除的骑士数
	}
	~solve()
	{
		for(int i=1;i<=N;i++)
			delete[] G[i];

		delete[] Dcc;
		delete[] DFN;
		delete[] Low;
		delete[] NotFire;
		delete[] flag;
		delete[] color;

		EmptyList();

		while(!stack_Edge.empty())
			stack_Edge.pop();
	}

	int min(int a,int b) const{return a<b?a:b;}

	void Initial(void);				//申请存储空间并初始化
	void Input(void);				//输入图G
	void Struct_G(void);			//构造图G的补图
	void Tarjan(int s,int father);	//Tarjan算法。s:当前搜索位置, father:s的父亲结点
	bool IsBinary(int s,int col);	//交叉染色判断s所在的双连通分量是否为二分图(s为搜索起点)

	void DelLink(Node* p);			//删除以结点p为表头的整条链
	void EmptyList(void);			//清空邻接链表

protected:

	int N;					//the number of Kinghts
	int M;					//the pairs of hate
	bool** G;				//邻接矩阵 记录图G
	Node** LinkHead;		//图G的补图的邻接链表表头

	int TimeStamp;			//（外部）时间戳
	int* DFN;				//DFN[u]: 结点u的搜索次序（时间戳）
	int* Low;				//Low[u]: 结点u或u的子树能够追溯到的最早的栈中结点的次序号

	stack<Edge>stack_Edge;	//边栈
	int* Dcc;				//存储点的双连通分量
	bool* flag;				//标记处于同一个双联通分量的所有顶点
	int dNum;				//双连通分量的顶点个数
	int* color;				//记录结点所染的颜色
	bool* NotFire;			//标记留席的骑士（即没有被剔除的骑士）
};

void solve::Initial(void)
{
	/*申请图G的存储空间并初始化*/

	G=new bool*[N+1];
	for(int i=1;i<=N;i++)
	{
		G[i]=new bool[N+1];
		memset(G[i],false,sizeof(bool)*(N+1));
		G[i][i]=true;
	}

	/*申请图G的补图~G的存储空间并初始化*/

	LinkHead=new Node*[N+1];
	for(int j=0;j<=N;j++)
		LinkHead[j]=0;

	/*申请执行Tarjan算法所需的存储空间并初始化*/

	TimeStamp=0;
	DFN=new int[N+1];
	Low=new int[N+1];
	memset(DFN,0,sizeof(int)*(N+1));
	memset(Low,0,sizeof(int)*(N+1));

	/*申请用于判定二分图所需的存储空间并初始化*/

	Dcc=new int[2*N+1];		//由于是按边压栈，则同一个点可能最多2次入栈
	flag=new bool[N+1];
	color=new int[N+1];
	NotFire=new bool[N+1];
	memset(NotFire,false,sizeof(bool)*(N+1));

	return;
}

void solve::Input(void)
{
	int x,y;		//temporary
	for(int j=1;j<=M;j++)
	{
		scanf("%d %d",&x,&y);
		G[x][y]=G[y][x]=true;
	}
	return;
}

void solve::Struct_G(void)
{
	for(int i=1;i<=N;i++)
	{
		LinkHead[i]=new Node;
		for(int j=1;j<=N;j++)
		{
			if(!G[i][j])
			{
				Node* tmp=LinkHead[i]->next;
				LinkHead[i]->next=new Node;
				LinkHead[i]->next->id=j;
				LinkHead[i]->next->next=tmp;
			}
		}
	}
	return;
}

void solve::Tarjan(int s,int father)
{
	DFN[s]=Low[s]=++TimeStamp;
	for(Node* p=LinkHead[s]->next;p;p=p->next)
	{
		int t=p->id;
		if(t!=father && DFN[t]<DFN[s])
		{
			if(!DFN[t])	//s->t为树枝边
			{
				Edge tagE(s,t);
				stack_Edge.push(tagE);	//树枝边压栈

				Tarjan(t,s);
				Low[s]=min(Low[s],Low[t]);

				if(DFN[s]<=Low[t])		//此时s为割点
				{
					/*寻找双连通分量，找到一组则马上处理一组*/
					dNum=0;
					memset(flag,false,sizeof(bool)*(N+1));
					memset(color,0,sizeof(int)*(N+1));
					for(Edge e=stack_Edge.top();;e=stack_Edge.top())
					{
						stack_Edge.pop();
						Dcc[dNum++]=e.u();
						Dcc[dNum++]=e.v();
						flag[e.u()]=true;		//标记处于同一个双连通分量的所有点
						flag[e.v()]=true;

						if(e==tagE || stack_Edge.empty())
							break;
					}
					if(!IsBinary(Dcc[0],1))		//当前的双连通分量不是二分图，则说明双连通分量内有奇圈
					{
						for(int i=0;i<dNum;i++)	//奇圈内的所有骑士均留席
							NotFire[Dcc[i]]=true;
					}
				}

			}
			else		//s->t为后向边
			{
				Low[s]=min(Low[s],DFN[t]);
			}
		}
	}
	return;
}

bool solve::IsBinary(int s,int col)
{
	color[s]=col;	//对s染色
	for(Node* p=LinkHead[s]->next;p;p=p->next)
	{
		int t=p->id;
		if(flag[t])			//检查t是否与s在同一个双连通分量
		{
			if(color[t]==0)	//t未染色
			{
				return IsBinary(t,3-col);	//3-col,目的是轮番用“1、2”交替染色
			}
			else			//t已染色
			{
				if(color[s]==color[t])		//若同一条边的两个端点同色
					return false;			//说明双连通分量不是二分图
			}								//即双连通分量内有奇圈
		}
	}
	return true;
}

void solve::DelLink(Node* p)
{
	if(p->next)
		DelLink(p->next);
	delete p;
	return;
}

void solve::EmptyList(void)
{
	for(int i=1;i<=N;i++)
		if(LinkHead[i])
			DelLink(LinkHead[i]);
	return;
}

int main(void)
{
	int n,m;
	while(scanf("%d %d",&n,&m) && (n+m))
		solve poj2942(n,m);

	return 0;
}
//No. 67
