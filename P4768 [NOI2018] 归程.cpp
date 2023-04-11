#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 1e6 + 10;

struct node//kruskal的海拔
{
	int u,v,w;
	bool operator<(const node&k)const
	{
		return w>k.w;
	}
} b[N];

struct node1//最短路
{
	int next,to,w;
} edge[N];
int fa[N],pre[N][32],val[N],dis[N],head[N],num,cnt;
int dep[N];
vector<int>eg[N];//重构树的边

void add(int u,int v,int w)
{
	edge[++num].next=head[u];
	edge[num].to=v;
	edge[num].w=w;
	head[u]=num;
}

void init(int n)
{
	for(int i=1; i<=2*n; ++i)fa[i]=i,fa[n+i]=n+i,eg[i].clear(),head[i]=0;//注意，重构树建立后点变成两遍，所以开空间要开两倍，初始化也要
	num=0,cnt=n;
}

int find(int x)
{
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}

void dijkstra(int n)
{
	for(int i=1; i<=2*n; ++i)dis[i]=INF;//2n个点，包含虚点，跑dij不会碰到虚点（都没出生呢），一开始虚点显然离终点无限远
	dis[1]=0;
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({dis[1],1});
	while(!q.empty())
		{
			int u=q.top().second;
			q.pop();
			for(int i=head[u]; i; i=edge[i].next)
				{
					int v=edge[i].to,w=edge[i].w;
					if(dis[v]>dis[u]+w)
						{
							dis[v]=dis[u]+w;
							q.push({dis[v],v});
						}
				}
		}
}

void kruskal(int n,int m)
{
	sort(b+1,b+1+m);
	cnt=n;
	for(int i=1; i<=m; ++i)
		{
			int fu=find(b[i].u),fv=find(b[i].v);
			if(fu!=fv)
				{
					val[++cnt]=b[i].w;
					fa[fu]=fa[fv]=cnt;
					eg[cnt].push_back(fu),eg[cnt].push_back(fv);
				}
		}
}

void dfs(int u,int f)
{
	dep[u]=dep[f]+1;
	pre[u][0]=f;
	for(int i=1; i<=20; ++i)pre[u][i]=pre[pre[u][i-1]][i-1];
	for(auto v:eg[u])if(v!=f)
			{
				dfs(v,u);
				dis[u]=min(dis[v],dis[u]);//存储虚点的子树的最小距离
			}
}

void mysolve()
{
	int n,m;
	cin>>n>>m;
	init(n);
	int x,y,d,w;
	for(int i=1; i<=m; ++i)
		{
			cin>>x>>y>>d>>w;
			add(x,y,d),add(y,x,d);
			b[i].u=x,b[i].v=y,b[i].w=w;
		}
	dijkstra(n);
	kruskal(n,m);
	dfs(cnt,0);
	int q,k,s;
	cin>>q>>k>>s;
	int v,p,lantans=0;
	while(q--)
		{
			cin>>v>>p;
			v=(v+k*lantans-1)%n+1;
			p=(p+k*lantans)%(s+1);
			int h=log2(dep[v]);
			for(int i=h; i>=0; --i)
				if(dep[pre[v][i]]&&val[pre[v][i]]>p)v=pre[v][i];
			cout<<(lantans=dis[v])<<endl;
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
