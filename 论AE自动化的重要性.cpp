#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
const int N = 2e5 + 10;
const int mod=1e9+7;

ll a[N],in[N];
struct node
{
	int next,to,w;
} edge[N<<1];
int head[N],num;

void add(int u,int v,ll w)
{
	edge[++num].next=head[u];
	edge[num].to=v,edge[num].w=w;
	head[u]=num;
}

int32_t main()
{
	int n,m,k;
	cin>>n>>m>>k;
	int x,y,c;
	for (int i=1; i<=k; ++i)
		{
			cin>>x>>y;
			a[x]+=y;
		}
	for (int i=1; i<=m; ++i)cin>>x>>y>>c,add(y,x,c),in[x]++;
	queue<int>q;
	ll ans=0;
	for (int i=1; i<=n; ++i)if (!in[i])q.push(i);
	while (!q.empty())
		{
			int u=q.front();
			q.pop();
			ans=(ans+a[u])%mod;
			for (int i=head[u]; i; i=edge[i].next)
				{
					int v=edge[i].to,w=edge[i].w;
					a[v]=(a[v]+a[u]*w)%mod;
					if (--in[v]==0)q.push(v);
				}
		}
	cout<<ans<<endl;
	return 0;
}
