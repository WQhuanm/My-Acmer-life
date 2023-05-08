#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 2e5 + 10;
int n,l,r;
vector<int>edge[N];
bool vis[N];
int dp[N],cnt;
int sg(int x)
{
	if(x<=0)return 0;
	if(~dp[x])return dp[x];
	set<int>s;
	for(int i=l; i<=r; ++i)for(int j=0; j<=x-i; ++j)s.insert(sg(j)^sg(x-i-j));//链x的sg值对于他切掉i长度后剩余的两部分j与x-i-j的sg异或和
	int ans=0;
	while(s.count(ans))ans++;
	return dp[x]=ans;
}

void dfs(int u)//dfs搜索一个环的节点数，即长度
{
	cnt++;
	vis[u]=1;
	for(auto v:edge[u])if(!vis[v])dfs(v);
}
void mysolve()
{
	//sg打表
	//	cin>>l>>r;
	//	memset(dp,-1,sizeof(dp));
	//	for(int i=1; i<=50; ++i)//求长度为i的环的sg值
	//		{
	//			set<int>s;
	//			for(int j=l; j<=min(r,i); ++j)s.insert(sg(i-j));//即环切掉i长度的所有sg值的mex函数
	//			int ans=0;
	//			while(s.count(ans))ans++;
	//			cout<<ans<<endl;
	//		}
	cin>>n>>l>>r;
	for(int i=1; i<=n; ++i)
	{
		if(i<l||i>(l+r-1))dp[i]=0;//打表出来的sg值规律
		else dp[i]=i/l;
	}
	int x,y;
	for(int i=1; i<=n; ++i)cin>>x>>y,edge[x].push_back(y),edge[y].push_back(x);
	int ans=0;
	for(int i=1; i<=n; ++i)
		if(!vis[i])cnt=0,dfs(i),ans^=dp[cnt];//答案就是所有环的异或和
	if(ans!=0)cout<<"Alice"<<endl;
	else cout<<"Bob"<<endl;
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
