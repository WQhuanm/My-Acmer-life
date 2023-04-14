#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
typedef pair<int, int> pii;
const int N = 2e4 + 10;

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
			dp[u][i]+=dp[v][0]+2*w;//最坏代价就是一个机器进去还出来，来回各走一次u-v路径w
			for(int j=i; j>=1; --j)dp[u][i]=min(dp[u][i],dp[u][i-j]+dp[v][j]+w*j);//枚举多个机器留着子树，进行更新，要加上j个机器进去时经过u-v路径w
		}
		dp[u][0]+=dp[v][0]+2*w;//存储只有一个机器的情况
	}
}
void mysolve()
{
	while(cin>>n>>s>>k)
	{
		memset(dp,0,sizeof(dp));
		for(int i=1; i<=n; ++i)edge[i].clear();
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
