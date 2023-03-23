#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 1e5 + 10;

int dep[N],head[N],f[N];
int num;
bool vis[N];//每条边，只走一次
struct node
{
	int next,to;
} edge[N];

void add(int u,int v)
{
	edge[++num].next=head[u];
	edge[num].to=v;
	head[u]=num;
}

void dfs(int u,int fa)//建立深度
{
	dep[u]=dep[fa]+1;
	for (int i=head[u]; i; i=edge[i].next)
	{
		int v=edge[i].to;
		if (v!=fa)dfs(v,u);
	}
}

int main()
{
	int n,m,st,x;
	cin>>n>>m;
	for (int i=1; i<=n; ++i)
	{
		cin>>x;
		f[i]=x;
		if (x==-1)st=i;
		add(x,i);
	}
	dep[0]=-1;
	dfs(st,0);
	int maxn=0;//记录走过点的最深层
	ll ans=0;//ans记录至少需要走的边数*2
	vis[st]=1;//从起点出发肯定是访问过
	while (m--)
	{
		cin>>x;
		maxn=max(maxn,dep[x]);
		while (!vis[x])
		{
			ans+=2;
			vis[x]=1;
			x=f[x];
		}
		cout<<ans-maxn<<endl;
	}
}

