#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;         //int型的INF
const int N = 2e5 + 10;
struct node
{
	int next,to;
	int w;
} edge[N<<1];
int head[N],num;
int dis[N];
bool vis[N];

void add(int u,int v,int w)
{
	edge[++num].next=head[u];
	edge[num].to=v;
	edge[num].w=w;
	head[u]=num;
}

int prim(int n)
{
	int ans=0;
	int cnt=0;
	fill(dis,dis+n+1,INF);//初始赋值所有点到起点集合距离无穷大
	dis[1]=0;
	priority_queue<pii,vector<pii>,greater<pii>>q;//堆优化
	q.push({dis[1],1});
	while(!q.empty())
		{
			int u=q.top().second;
			q.pop();
			if(vis[u])continue;//对于u，取他离集合最短时的边
			vis[u]=1;
			cnt++;//记录存入集合的点+1
			ans+=dis[u];//一旦取了，加入这个边
			for(int i=head[u]; i; i=edge[i].next)
				{
					int v=edge[i].to,w=edge[i].w;//更新u连接的其他点v，更新v点们到集合的最短距离
					if(dis[v]>w)//区别dij，这里更新其到集合（不是到起点）最短边即可
						{
							dis[v]=w;
							q.push({dis[v],v});
						}
				}
		}
	return (cnt==n?ans:-1);//如果存入了图的所有点，说明连通
}

void mysolve()
{
	int n,m;
	cin>>n>>m;
	int x,y,w;
	while(m--)cin>>x>>y>>w,add(x,y,w),add(y,x,w);
	int ans=prim(n);
	if(ans==-1)cout<<"orz"<<endl;
	else cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
