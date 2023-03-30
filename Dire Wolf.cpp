#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
const int INF=0x3f3f3f3f;
const int N = 210;
int a[N],b[N],dp[N][N];

int32_t main()
{
	int t, n, t1 = 0;
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (int i=1; i<=n; ++i)for (int j=i; j<=n; ++j)dp[i][j]=INF;
		for (int i=1; i<=n; ++i)cin>>a[i];
		for (int i=1; i<=n; ++i)cin>>b[i];
		b[0]=b[n+1]=0;
		for (int len=1; len<=n; ++len)for (int i=1; i+len-1<=n; ++i)//区间合并通常是枚举每一个长度len，求出每个长度的最优解，最后推出答案最优
		{//这里从长度1开始，注意，dp[i][i]不一定==a[i],因为i左右可能有狼
			int j=i+len-1;
			for (int k=i; k<=j; ++k)dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]+a[k]+b[i-1]+b[j+1]);
		}
		printf("Case #%lld: ", ++t1);
		cout<<dp[1][n]<<endl;
	}
}
