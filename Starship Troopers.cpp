#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 110;
vector<int>edge[N];
int a[N],b[N],dp[N][N];

void dfs(int u,int f,int w)
{
	if(!w||a[u]>w)return;
	for(int i=a[u]; i<=w; ++i)dp[u][i]=b[u];//先初始化一开始经过这个点获得这个点的val值
	for(auto v:edge[u])if(v!=f)
	{
		dfs(v,u,w-a[u]);//更新子树，记得j从1开始，至少有一个士兵去子树
		for(int i=w; i>=a[u]; --i)for(int j=i-a[u]; j>=1; --j)dp[u][i]=max(dp[u][i],dp[u][i-j]+dp[v][j]);
	}
}

void mysolve()
{
	int n,m;
	while(cin>>n>>m&&(n!=-1||m!=-1))
	{
		memset(dp,0,sizeof(dp));
		for(int i=1; i<=n; ++i)edge[i].clear(),cin>>a[i]>>b[i],a[i]=(a[i]+19)/20;
		int x,y;
		for(int i=1; i<n; ++i)cin>>x>>y,edge[x].push_back(y),edge[y].push_back(x);
		dfs(1,0,m);
		cout<<dp[1][m]<<endl;
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
