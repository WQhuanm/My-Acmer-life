#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 3e5 + 10;
const ll mod=998244353;
int dp[N],pre[N],sum[N],lei[N];
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

void mysolve()
{
	int n;
	cin>>n;
	cout<<dp[n]<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	dp[0]=1,dp[1]=0;
	pre[0]=1;
	for(int i=1; i<=2e5+10; ++i)pre[i]=pre[i-1]*i%mod;//预处理排列数
	sum[1]=1,lei[1]=3;
	for(int i=2; i<=2e5; ++i)
		{
			dp[i]=2ll*pre[i]%mod*lei[i-1]%mod*fastmi((pre[i+2]-2ll*pre[i]%mod+mod)%mod,mod-2ll)%mod;
			sum[i]=(sum[i-1]+dp[i])%mod;//记录每个dp的和
			lei[i]=((lei[i-1]+sum[i])%mod+dp[i])%mod;//记录累积结果
		}
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

