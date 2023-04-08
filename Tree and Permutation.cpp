#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
#define endll            endl<<endl
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
//double 型memset最大127，最小128
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 1e5 + 10;
const int mod=1e9+7;
vector<pii>edge[N];
int sum[N],cnt[N],A[N];

void dfs1(int u,int fa)
{
	sum[u]=0;
	cnt[u]=1;
	for(pii k:edge[u])
		{
			int v=k.first,w=k.second;
			if(v!=fa)
				{
					dfs1(v,u);
					sum[u]+=sum[v]+cnt[v]*w;
					cnt[u]+=cnt[v];
				}
		}
}

void dfs(int u,int fa,int n)
{
	for(pii k:edge[u])
		{
			int v=k.first,w=k.second;
			if(v!=fa)
				{
					sum[v]=sum[u]-w*(cnt[v])+(n-cnt[v])*w;
					dfs(v,u,n);
				}
		}
}

void mysolve()
{
	A[0]=1;
	for(int i=1; i<=1e5; ++i)A[i]=A[i-1]*i%mod;
	int n;
	while(cin>>n)
		{
			for(int i=1; i<=n; ++i)edge[i].clear();
			int x,y,w;
			for(int i=1; i<n; ++i)
				{
					cin>>x>>y>>w;
					edge[x].push_back({y,w}),edge[y].push_back({x,w});
				}
			ll ans=A[n-2]%mod*(n-1)%mod;
			dfs1(1,0);

			dfs(1,0,n);
			int tmp=0;
			for(int i=1; i<=n; ++i)tmp=(tmp+sum[i])%mod;
			ans=ans*tmp%mod;
			cout<<ans<<endl;
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
