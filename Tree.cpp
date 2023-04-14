#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
typedef pair<int, int> pii;
const int N = 2e5 + 10;
vector<pii>edge[N];
		
int len[N],num[N],ans,sum;
		
void dfs(int u,int f)
{
	len[u]=0,num[u]=1;
	for(pii k:edge[u])if(k.first!=f)
			{
				int v=k.first;
				dfs(v,u);
				int tmp=k.second+len[v];
				if(tmp+len[u]>ans)ans=tmp+len[u],sum=num[u]*num[v];//如果更新最长（待定）直径或者最长（待定）路径，顺便更新其数量
				else if(tmp+len[u]==ans)sum+=num[u]*num[v];
				if(tmp>len[u])len[u]=tmp,num[u]=num[v];
				else if(tmp==len[u])num[u]+=num[v];
			}
}
		
void mysolve()
{
	int n;
	while(cin>>n)
		{
			for(int i=1; i<=n; ++i)edge[i].clear();
			int x,y,w;
			for(int i=1; i<n; ++i)cin>>x>>y>>w,edge[x].push_back({y,w}),edge[y].push_back({x,w});
			ans=sum=0;
			dfs(1,0);
			cout<<ans<<" "<<sum<<endl;
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
