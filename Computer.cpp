#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
typedef pair<int, int> pii;
const int N = 2e5 + 10;

vector<pii>edge[N];

void dfs(int u,int f,int w,vector<int>&dis)
{
	dis[u]=dis[f]+w;
	for( pii k:edge[u])if(k.first!=f)dfs(k.first,u,k.second,dis);
}

void mysolve()
{
	int n;
	while(cin>>n)
		{
			int x,y;
			for(int i=1; i<=n; ++i)edge[i].clear();
			for(int i=2; i<=n; ++i)cin>>x>>y,edge[i].push_back({x,y}),edge[x].push_back({i,y});
			vector<int>dis1(n+1),dis2(n+1);
			dfs(1,0,0,dis1);//第一遍dfs确定第一个直径端点
			int a=max_element(dis1.begin()+1,dis1.end())-dis1.begin();
			dfs(a,0,0,dis1);//第二遍dfs确定直径另一个端点
			int b=max_element(dis1.begin()+1,dis1.end())-dis1.begin();
			dfs(b,0,0,dis2);//从另一个端点出发，每个点的最远距离就是到两个端点的最大值
			for(int i=1; i<=n; ++i)cout<<max(dis1[i],dis2[i])<<endl;
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
