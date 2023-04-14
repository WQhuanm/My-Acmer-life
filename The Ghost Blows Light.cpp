#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
#define endll            endl<<endl
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
//double 型memset最大127，最小128
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N =110;
int n,t;
vector<pii>edge[N];
int dp[N][5*N],a[N],d[N];
bool vis[N];
int ans;

void dfs(int u,int f)
{
	if(u==n)vis[u]=1;
	for(pii k:edge[u])if(k.first!=f)
			{
				int v=k.first,w=k.second;
				dfs(v,u);
				if(t<0)return;
				if(vis[v])
					{
						ans+=a[v];
						vis[u]=1;
						t-=w;
						for(int i=t; i>=0; --i)
							{
								for(int j=i; j>=0; --j)
									{
										dp[u][i]=max(dp[u][i],dp[u][i-j]+dp[v][j]);
									}
							}
						continue;
					}
				else
					for(int i=t; i>=0; --i)
						{
							for(int j=i-2*w; j>=0; --j)
								{
									dp[u][i]=max(dp[u][i],dp[u][i-2*w-j]+a[v]+dp[v][j]);
								}
						}

			}
}

void mysolve()
{
	while(cin>>n>>t)
		{
			memset(dp,0,sizeof(dp));
			for(int i=1; i<=n; ++i)vis[i]=0;
			for(int i=1; i<=n; ++i)edge[i].clear();
			int x,y,w;
			for(int i=1; i<n; ++i)cin>>x>>y>>w,edge[x].push_back({y,w}),edge[y].push_back({x,w});
			for(int i=1; i<=n; ++i)cin>>a[i];
			ans=a[1];
			dfs(1,-1);
			if(t<0)cout<<"Human beings die in pursuit of wealth, and birds die in pursuit of food!"<<endl;
			else cout<<ans+dp[1][t]<<endl;

		}
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
