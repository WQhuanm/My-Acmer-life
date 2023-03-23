#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll//全部开成ll
const int N = 3e5 + 10;
const int mod=1e9+7;
int n,num;
int t[N],head[N],dp[N],pre[N];
int cnt1,cnt2;//分别记录一直有贡献的逆序对数量与一直没贡献的逆序对数量
struct node
{
	int next,to;
} edge[N<<1];

void add(int u,int v)
{
	edge[++num].next=head[u];
	edge[num].to=v;
	head[u]=num;
}

void updateadd(int x,int k)
{
	for (int i=x; i<=n; i+=i&-i)t[i]=(t[i]+k)%mod;
}

ll ask(int x)
{
	ll ans=0;
	for (int i=x; i; i-=i&-i)ans=(ans+t[i])%mod;
	return ans;
}

ll fastpower(ll base,ll power)
{
	ll ans=1;
	while (power)
	{
		if (power&1)ans=ans*base%mod;
		power>>=1;
		base=base*base%mod;
	}
	return ans;
}

void dfs(int u,int fa)
{
	dp[u]=1;
	int cnt=0;//记录亲儿子数量
	for (int i=head[u]; i; i=edge[i].next)
	{
		int v=edge[i].to;
		if (v!=fa)
		{
			cnt++;
			cnt1=(cnt1+ask(n)-ask(v)+mod)%mod;//有减法的取模记得加mod保证正数
			cnt2=(cnt2+ask(v-1))%mod;
			updateadd(v,1);//把当前点加入树状数组后继续深入
			dfs(v,u);
			updateadd(v,-1);//出来后从树状树状删除
			dp[u]=dp[u]*dp[v]%mod;
		}
	}
	dp[u]=dp[u]*pre[cnt]%mod;//dp为组合数
}

int32_t main()
{
	int r,x,y;
	cin>>n>>r;
	pre[0]=1;
	for (int i=1; i<=n; ++i)pre[i]=pre[i-1]*i%mod; //预处理排列数
	for (int i=1; i<n; ++i)
	{
		cin>>x>>y;
		add(x,y),add(y,x);
	}
	updateadd(r,1);//显然根节点一直在树状数组
	dfs(r,0);
	int num=(n*(n-1)%mod*fastpower(2,mod-2)%mod-cnt2+mod)%mod;//贡献为1/2的点,即n*(n-1)/2-cnt2,当然是包括cnt1的，但是只算了cnt1一半的贡献，后面cnt1还有自己算另一半
	ll ans=(num*dp[r]%mod*fastpower(2,mod-2)%mod+cnt1*dp[r]%mod*fastpower(2,mod-2)%mod)%mod;
	cout<<ans<<endl;
	return 0;
}
