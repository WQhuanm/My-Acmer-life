#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
const int N = 200510;

struct node
{
	int next,to;
} edge[N];
int head[N],in[N],dp[N];
int num;
bool flag;
void add(int u,int v)
{
	edge[++num].next=head[u];
	edge[num].to=v;
	head[u]=num;
}

ll dfs(int u,int f)//f是目的地
{
	if (dp[u])return dp[u]; //搜过就不再重新搜索
	if (u==f)return dp[u]=1; //到达目标点可以返回了
	if (!in[u])//in表示入度，入度为0，说明他是最终点，且不是f（是的话，前面就返回了），所以不是逻辑自洽
		{
			flag=0;
			return dp[u]=0;
		}
	for (int i=head[u]; i; i=edge[i].next)
		{
			int v=edge[i].to;
			dp[u]+=dfs(v,f);
		}
	return dp[u];
}

int32_t main()
{
	int n,m,x,y;
	cin>>n>>m;
	for (int i=1; i<=m; ++i)cin>>x>>y,add(x,y),in[x]++;
	cin>>x>>y;
	flag=1;
	int ans=dfs(x,y);
	cout<<ans<<" ";
	cout<<(flag==1?"Yes":"No")<<endl;
	return 0;
}
