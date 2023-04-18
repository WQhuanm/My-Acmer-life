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
const int N = 3e3 + 10;
const int mod=998244353;
int dp[N],sum[N],C[N][N],pre[N];

void getC()
{
	C[0][0]=1;
	for(int i=1; i<=3000; ++i)
		{
			C[i][0]=C[i][i]=1;
			for(int j=1; j<i; ++j)
				{
					C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
				}
		}
	pre[0]=1;
	for(int i=1; i<=3000; ++i)pre[i]=pre[i-1]*2%mod;
}

ll qpow(ll base,ll power)
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
	dp[0]=0,dp[1]=0;
	for(int i=2; i<=3000; ++i)
		{
			int tmp=0;
			for(int j=0; j<i; ++j)tmp=(tmp+C[i][j]*dp[j])%mod;
			dp[i]=(pre[i-2]*i%mod*(i-1)%mod+tmp)%mod*qpow(pre[i]-1,mod-2)%mod;
			sum[i]=(sum[i-1]+dp[i])%mod;
		}
	int n;
	while(cin>>n)cout<<sum[n]*qpow(n,mod-2)%mod<<endl;

}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	//cin >> t;
	while (t--)
		{
			getC();
			mysolve();
		}
	system("pause");
	return 0;
}
