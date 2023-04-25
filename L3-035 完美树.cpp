#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 2e5 + 10;
int cnt[N],dp[N][3],p[N],in[N];
vector<int>edge[N];
bool c[N];
void dfs(int u)
{
	vector<int>q;
	int sum=0;
	for(auto v:edge[u])
	{
		dfs(v);
		if(cnt[v]&1)
		{
			cnt[u]++;
			q.push_back(dp[v][2]-dp[v][1]),sum+=dp[v][1];//先全部加dp[v][1],后面需要dp[v][2],取q数组即可
		}
		else sum+=dp[v][0];//为0直接累加
	}
	sort(q.begin(),q.end());
	int mid=(int)q.size()/2;
	for(int i=0; i<mid; ++i)sum+=q[i];
	if(!cnt[u])
	{
		dp[u][1]=sum+(c[u]==0?0:p[u]);
		dp[u][2]=sum+(c[u]==1?0:p[u]);
	}
	else if(cnt[u]&1)dp[u][0]=min(sum+(c[u]==1?0:p[u]),sum+q[mid]+(c[u]==0?0:p[u]));
	else
	{
		dp[u][1]=min(sum+(c[u]==0?0:p[u]),sum-q[mid-1]+(c[u]==1?0:p[u]));
		dp[u][2]=min(sum+(c[u]==1?0:p[u]),sum+q[mid]+(c[u]==0?0:p[u]));
	}
	cnt[u]++;//自己是一个点
}
void mysolve()
{
	int n;
	cin>>n;
	int k,x;
	for(int i=1; i<=n; ++i)
	{
		cin>>c[i]>>p[i]>>k;
		for(int j=1; j<=k; ++j)cin>>x,edge[i].push_back(x),in[x]++;
	}
	for(int i=1; i<=n; ++i)if(!in[i])
	{
		memset(dp,0x3f,sizeof(dp));
		dfs(i);
		int ans=min({dp[i][0],dp[i][1],dp[i][2]});
		cout<<ans<<endl;
	}
}

int32_t main()
{
	mysolve();
	return 0;
}
