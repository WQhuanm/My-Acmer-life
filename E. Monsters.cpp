#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define endl             "\n"
typedef pair<long long, long long> pll;
const int N = 2e5 + 10;

int a[N],fa[N],cnt[N];
int vis[N];
struct node
{
	int next,to;
} edge[N<<1];
int head[N],num;
int t,n,m;

inline void init()
{
	for (int i=0; i<=n; ++i)head[i]=0,fa[i]=i,cnt[i]=1,vis[i]=0;
	num=0;
}

inline void add(int u,int v)
{
	edge[++num].next=head[u];
	edge[num].to=v;
	head[u]=num;
}

inline int find(int u)//并查集找祖先
{
	if (u!=fa[u])fa[u]=find(fa[u]);
	return fa[u];
}

bool check(int x)//检查从x出发是否可以经过所有点
{
	set<pll>s;//用set存储，每次取a[i]最小的点出来
	s.insert({a[x],x});
	while (!s.empty())
		{
			int u=(*s.begin()).second;
			s.erase(s.begin());
			if (a[u]>cnt[x])return (cnt[x]==n);//如果这个点到不了，后面都到不了，直接返回
			int tmp=find(u);
			if (tmp!=x)fa[tmp]=x,cnt[x]+=cnt[tmp],cnt[tmp]=0;//如果这个点的祖先不是x，吸收这个祖先的集合
			for (int i=head[u]; i; i=edge[i].next)
				{
					int v=edge[i].to;
					if (vis[v]<x)//vis两个功能，1个是判断a[i]=0的点有没有被访问过，有则main函数不用来了，而是一个check(x)回合避免多次访问一个点v
						vis[v]=x,s.insert({a[v],v});
				}
		}
	return (cnt[x]==n);
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while (t--)
		{
			cin>>n>>m;
			init();
			for (int i=1; i<=n; ++i)cin>>a[i];
			int x,y;
			for (int i=1; i<=m; ++i)
				{
					cin>>x>>y;
					add(x,y),add(y,x);
				}
			bool flag=0;
			for (int i=1; i<=n; ++i)if (a[i]==0&&!vis[i])if (check(i))
						{
							cout<<"YES"<<endl;
							flag=1;
							break;
						}
			if (!flag)
				cout<<"NO"<<endl;
		}
	system("pause");
	return 0;
}
