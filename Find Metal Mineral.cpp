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
const int N = 2e5 + 10;

vector<pii>edge[N];
int dp[N][15];
int n,s,k;
void dfs(int u,int f)
{
	for(pii h:edge[u])if(h.first!=f)
			{
				int v=h.first,w=h.second;
				dfs(v,u);
				for(int i=k; i>=1; --i)
					{
						dp[u][i]+=dp[v][0]+2*w;
						for(int j=i; j>=1; --j)dp[u][i]=min(dp[u][i],dp[u][i-j]+dp[v][j]+j*w);
					}
				dp[u][0]+=dp[v][0]+2*w;
			}
}
void mysolve()
{

	while(cin>>n>>s>>k)
		{
			for(int i=1; i<=n; ++i)edge[i].clear();
			memset(dp,0,sizeof(dp));
			int x,y,w;
			for(int i=1; i<n; ++i)cin>>x>>y>>w,edge[x].push_back({y,w}),edge[y].push_back({x,w});
			dfs(s,0);
			cout<<dp[s][k]<<endl;
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
