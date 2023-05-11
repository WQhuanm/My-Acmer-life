#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
void mysolve()
{
	int n,m;
	cin>>n>>m;
	vector<int>a(n),e(n),cnt(n),dp(1<<n,-1),cost(1<<n);
	dp[0]=0;
	int k;
	for(int i=0; i<n; ++i)cin>>a[i];
	for(int i=0; i<n; ++i)cin>>e[i];
	for(int i=0; i<n; ++i)
		{
			cin>>k;
			int x;
			for(int j=1; j<=k; ++j)cin>>x,cnt[i]|=(1<<(x-1));
		}
	for(int i=1; i<(1<<n); ++i)for(int j=0; j<n; ++j)if(i&(1<<j))cost[i]+=e[j];
	int ans=0;
	for(int i=0; i<(1<<n); ++i)
		{
			if(dp[i]==-1)continue;
			for(int j=0; j<n; ++j)if((i|cnt[j])==i&&(i&(1<<j))==0&&cost[i]+e[j]<=m)
					{
						dp[i|(1<<j)]=dp[i]+a[j];
						ans=max(ans,dp[i|(1<<j)]);
					}
		}
	cout<<ans<<endl;
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
