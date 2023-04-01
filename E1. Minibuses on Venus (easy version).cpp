#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
const int N = 110;

int n,k,mod;
ll dp[N][40];
ll qpow(ll base,ll power)
{
	ll ans=1;
	while (power)
		{
			if (power&1)ans=ans*base%mod;
			power>>=1,base=base*base%mod;
		}
	return ans;
}

ll tosum(int sum)//求取n位和为sum的不合法数
{
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;//这是为了赋值每一位dp[1][j],显然一位数时，不合法情况有k-1种
	for (int i=1; i<=n; ++i)for (int x=0; x<k; ++x)if (x*2%k!=sum)//转移式是处理了i-1个数，当前第i为选x（它不合法），更新这i位一共和为h的情况
				{
					for (int h=0; h<k; ++h)dp[i][h]=(dp[i][h]+dp[i-1][(k+h-x)%k])%mod;
				}
	return dp[n][sum];
}

int32_t main()
{
	cin>>n>>k>>mod;
	ll ans=qpow(k,n);//情况总数
	for (int i=0; i<k; ++i)ans=(ans+mod-tosum(i))%mod;//枚举sum减去不合法总数
	cout<<ans<<endl;
	return 0;
}
