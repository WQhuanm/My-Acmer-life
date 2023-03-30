#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
const int INF=0x3f3f3f3f;
const int N = 110;
const int mod=1e9+7;
int C[N][N],A[N],dp[N][N];

int32_t main()
{
	int n;
	C[0][0]=1,A[0]=1;
	for (int i=1; i<=100; ++i)//数据小，杨辉三角求组合数即可
	{
		C[i][0]=1;
		for (int j=1; j<=i; ++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	for (int i=1; i<=100; ++i)A[i]=A[i-1]*i%mod;
	while (cin>>n)
	{
		memset(dp,0,sizeof(dp));
		string s;
		for (int i=1; i<=n; ++i)cin>>dp[i][i];
		cin>>s;
		s=' '+s;
		for (int len=2; len<=n; ++len)for (int i=1; i<=n; ++i)
		{
			int j=i+len-1;
			for (int k=i; k<j; ++k)
			{
				if (s[k]=='+')
				{
					dp[i][j]=(dp[i][j]+(dp[i][k]*A[j-k-1]+dp[k+1][j]*A[k-i])%mod*C[j-i-1][k-i]%mod)%mod;
				}
				else if (s[k]=='-')
				{
					dp[i][j]=(dp[i][j]+(dp[i][k]*A[j-k-1]-dp[k+1][j]*A[k-i])%mod*C[j-i-1][k-i]%mod)%mod;
				}
				else
				{
					dp[i][j]=(dp[i][j]+dp[i][k]*dp[k+1][j]%mod*C[j-i-1][k-i]%mod)%mod;
				}
			}
		}
		dp[1][n]=(dp[1][n]+mod)%mod;//保证答案正数
		cout<<dp[1][n]<<endl;
	}
	return 0;
}
