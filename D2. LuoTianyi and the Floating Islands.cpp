#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 3e5 + 10;
const int mod=1e9+7;
int n,k;
vector<int>edge[N];
int pre[N],inv[N],sz[N];
ll ans;
ll fastmi(ll base,ll power)
{
	ll ans=1;
	while(power)
		{
			if(power&1)ans=ans*base%mod;
			base=base*base%mod;
			power>>=1;
		}
	return ans;
}

int C(int n,int m)
{
	if(n<0||m<0||n<m)return 0;
	return pre[n]*inv[m]%mod*inv[n-m]%mod;//取模运算不允许出现除法，所以除数都转化为逆元存下来
}

void dfs(int u,int f)
{
	sz[u]=1;
	for(auto v:edge[u])if(v!=f)
			{
				dfs(v,u);
				sz[u]+=sz[v];
				ans=(ans+C(sz[v],k/2)*C(n-sz[v],k/2)%mod)%mod;//计算子树v的贡献
			}
}

void mysolve()
{
	cin>>n>>k;
	int x,y;
	for(int i=1; i<n; ++i)cin>>x>>y,edge[x].push_back(y),edge[y].push_back(x);
	if(k&1)
		{
			cout<<1<<endl;
			return;
		}
	ans=C(n,k);//即+1
	dfs(1,0);
	ans=ans*fastmi(C(n,k),mod-2)%mod;
	cout<<ans<<endl;
	return;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	//cin >> t;
	pre[0]=1;
	for(int i=1; i<=2e5; ++i)pre[i]=pre[i-1]*i%mod;
	inv[200000]=fastmi(pre[200000],mod-2);
	for(int i=2e5-1; ~i; --i)inv[i]=inv[i+1]*(i+1)%mod;
	//for(int i=)
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
