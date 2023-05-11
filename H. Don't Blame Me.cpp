#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 2e5 + 10;
const int mod=1e9+7;
int cnt[100];
int a[N];
void mysolve()
{
	int n,k;
	cin>>n>>k;
	for(int i=1; i<=n; ++i)cin>>a[i];
	vector<vector<int>>dp(n+1,vector<int>(100));
	dp[0][(1<<6)-1]=1;
	for(int i=1; i<=n; ++i)for(int j=0; j<64; ++j)if(dp[i-1][j]>0)
				{
					dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
					dp[i][j&a[i]]=(dp[i][j&a[i]]+dp[i-1][j])%mod;
				}
	int ans=0;
	for(int i=0; i<64; ++i)if(cnt[i]==k)
			ans=(ans+dp[n][i])%mod;
	if(k==6)ans=(ans-1+mod)%mod;
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	for(int i=0; i<(1<<6); ++i)for(int j=0; j<6; ++j)if(i&(1<<j))cnt[i]++;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
