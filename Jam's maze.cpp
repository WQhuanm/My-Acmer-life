#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
const int INF=0x3f3f3f3f;
const int N = 510;
const int mod=5201314;
int dp[3][N][N];//第一维用于滚动转换
char a[N][N];
int32_t main()
{
	int t,n;
	cin>>t;
	while (t--)
	{
		cin>>n;
		memset(dp,0,sizeof(dp));
		for (int i=1; i<=n; ++i)for (int j=1; j<=n; ++j)cin>>a[i][j];
		if (a[1][1]==a[n][n])dp[0][1][n]=1;
		int p=1;//通过p为0，1进行转移
		for (int i=1; i<n; ++i)//走n-1步到副对角线
		{
			memset(dp[p],0,sizeof(dp[p]));//每次清空之前转移后留下的数据再更新它,这样就代替了i
			for (int j=1; j<=n&&i+1-j>=0; ++j)for (int k=n; k+i>=n&&k>=1; --k)
			{
				
				if (a[j][i+2-j]==a[k][2*n-i-k])dp[p][j][k]=(dp[p][j][k]+dp[p^1][j-1][k]+dp[p^1][j][k]+dp[p^1][j][k+1]+dp[p^1][j-1][k+1])%mod;//如果当前两点相等
			}
			p^=1;
		}
		p^=1;
		ll ans=0;
		for (int i=1; i<=n; ++i)
			ans=(ans+dp[p][i][i])%mod;
		cout<<ans<<endl;
	}
	return 0;
}
