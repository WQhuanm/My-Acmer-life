#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 210;
const int mod=1e4+7;

vector<int>edge[N];
int cnt[N],root[2];
int dp[N][N],fdp[N][N];
int n;
int pre(int b[])
{
	int ans=n;
	while(ans&&!b[ans])ans--;
	return ans;
}

void dfs1(int u,int f)//寻找重心
{
	cnt[u]=1;
	int maxn=0;
	for(auto v:edge[u])if(v!=f)//记录含u在内的以u为根的子树节点数
	{
		dfs1(v,u);
		cnt[u]+=cnt[v];
		maxn=max(cnt[v],maxn);//取最大子树节点数
	}
	maxn=max(maxn,n-cnt[u]);
	if(maxn<=n/2)root[root[0]!=-1]=u;//记录第一个重心（或者第二个重心）
}

void dfs(int u,int f)//求方案数
{
	dp[u][0]=dp[u][1]=1;
	for(auto v:edge[u])if(v!=f)
	{
		dfs(v,u);
		int p1=pre(dp[u]),p2=pre(dp[v]);//预处理减少+0*0的浪费时间的情况
		for(int i=p1; i>=1; --i)for(int j=p2; j>=1; --j)dp[u][i+j]=(dp[u][i+j]+dp[u][i]*dp[v][j])%mod;//注意，u点至少也有自己，所以i>=1，v也一样，如果你节点数为0，我还加你干什么，所以j>=1
	}
}

void solve1()//重心一个
{
	int ans=0,tmp=0;
	dfs(root[0],0);
	memset(fdp,0,sizeof(fdp));
	for(auto v:edge[root[0]])//求v外面的节点非法方案数
	{
		fdp[v][0]=1;
		for(auto fv:edge[root[0]])if(fv!=v)//注意，root的儿子不能是v，求的是v外面的节点
		{
			int p1=pre(fdp[v]),p2=pre(dp[fv]);
			for(int i=p1; i>=0; --i)for(int j=p2; j>=1; --j)fdp[v][i+j]=(fdp[v][i+j]+fdp[v][i]*dp[fv][j])%mod;//这里i可以从0开始，因为外面节点可以为0，j还是从1开始，不然加了没意义（还会错）
		}
		for(int i=1; i<=n; ++i)for(int j=0; j<i; ++j)tmp=(tmp+dp[v][i]*fdp[v][j])%mod;//v的节点数为i时，所有外面节点数和为j<i的都是不合法
	}
	for(int i=1; i<=n; ++i)ans=(ans+dp[root[0]][i])%mod;//计算所有情况
	ans=(ans-tmp+mod)%mod;//减去不合法情况
	cout<<ans<<endl;
}

void solve2()//重心两个
{
	int ans=0;
	dfs(root[0],root[1]),dfs(root[1],root[0]);
	for(int i=1; i<=n; ++i)ans=(ans+dp[root[0]][i]*dp[root[1]][i])%mod;//直接累加相同的各自节点数乘积
	cout<<ans<<endl;
}

int tt=0;
void mysolve()
{
	cin>>n;
	for(int i=1; i<=n; ++i)edge[i].clear();
	memset(dp,0,sizeof(dp));
	int x,y;
	for(int i=1; i<n; ++i)cin>>x>>y,edge[x].push_back(y),edge[y].push_back(x);
	root[0]=root[1]=-1;
	dfs1(1,0);
	cout<<"Case "<<++tt<<": ";
	if(root[1]==-1)solve1();
	else solve2();
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	cin >> t;
	while (t--)
	{
		mysolve();
	}
	system("pause");
	return 0;
}
