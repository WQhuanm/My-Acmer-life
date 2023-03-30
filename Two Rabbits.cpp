#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
const int INF=0x3f3f3f3f;
const int N = 1010;
int dp[N][N],a[N];//dp记录区间最长
int32_t main()
{
	int n;
	while (cin>>n&&n)
	{
		memset(dp,0,sizeof(dp));
		for (int i=1; i<=n; ++i)cin>>a[i],dp[i][i]=1;
		for (int len=2; len<=n; ++len)for (int i=1; i+len-1<=n; ++i)
		{
			int j=i+len-1;
			dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
			if (a[i]==a[j])dp[i][j]=dp[i+1][j-1]+2;
		}
		ll ans=0;
		for (int i=1; i<=n; ++i)ans=max(dp[1][i]+dp[i+1][n],ans);
		cout<<ans<<endl;
	}
	return 0;
}
