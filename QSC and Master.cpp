#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
const int N = 310;
int dp[N][N];
int a[N],g[N],sum[N];

int32_t main()
{
	int t,n;
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (int i=1; i<=n; ++i)cin>>g[i];
		for (int i=1; i<=n; ++i)cin>>a[i],sum[i]=sum[i-1]+a[i];
		memset(dp,0,sizeof(dp));
		for (int len=2; len<=n; ++len)for (int i=1; i+len-1<=n; ++i)
		{
			int j=i+len-1;
			for (int k=i; k<j; ++k)
			{
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
			if (__gcd(g[i],g[j])!=1)//如果最外端不互质
			{
				if (len==2)dp[i][j]=a[i]+a[j];//特判长度为2
				else if (dp[i+1][j-1]==sum[j-1]-sum[i])dp[i][j]=dp[i+1][j-1]+a[i]+a[j];
			}
		}
		cout<<dp[1][n]<<endl;
	}
	return 0;
}
