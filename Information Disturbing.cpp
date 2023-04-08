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
const int N = 1110;

vector<pii>edge[N];
int dp[N];

void dfs(int u,int fa,int lim)
{
	bool flag=1;
	dp[u]=0;
	for(pii x:edge[u])
		{
			int v=x.first,w=x.second;
			if(v!=fa)
				{
					flag=0;
					dfs(v,u,lim);
					if(w<=lim)dp[u]+=min(w,dp[v]);
					else dp[u]+=dp[v];
				}
		}
	if(flag)dp[u]=INF;
}

void mysolve()
{
	int n,m;
	while(cin>>n>>m&&(n||m))
		{
			for(int i=1; i<=n; ++i)edge[i].clear();
			int x,y,w;
			for (int i=1; i<n; ++i)
				{
					cin>>x>>y>>w;
					edge[x].push_back({y,w}),edge[y].push_back({x,w});
				}
			int l=0,r=m;
			int ans=-1;
			while(l<=r)
				{
					int mid=l+((r-l)>>1);
					dfs(1,0,mid);
					if(dp[1]<=m)ans=mid,r=mid-1;
					else l=mid+1;
				}
			cout<<ans<<endl;
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
