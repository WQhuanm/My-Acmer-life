#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
inline int read(int &x);
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e3 + 10;
const int mod = 998244353;

int dp[N][N],sum[N][N];
ll pre[N<<2],inv[N<<2];

ll fastmi(ll base, ll power)
{
	ll ans = 1;
	while (power)
		{
			if (power & 1)ans=ans*base%mod;
			base=base*base%mod;
			power >>=1;
		}
	return ans;
}

void mysolve()
{
	int n,k;
	cin>>n>>k;
	if(k==1)
		{
			cout<<pre[2*n]*inv[n]%mod*inv[n]%mod*fastmi(n+1,mod-2)%mod<<endl;
		}
	else
		{
			dp[1][0]=dp[1][1]=1;
			sum[1][0]=1,sum[1][1]=2;
			for(int i=2; i<=n; ++i)
				{
					for(int j=0; j<=i; ++j)
						{
							int l=max(0ll,j-1),r=min(i-1,j+k-2);//dp[i][j]可以由i-1更新的范围
							dp[i][j]=(sum[i-1][r]-(l?sum[i-1][l-1]:0)+mod)%mod;
							sum[i][j]=(dp[i][j]+(j?sum[i][j-1]:0))%mod;
						}
				}
			ll ans=(pre[2*n]*inv[n]%mod*inv[n]%mod*fastmi(n+1,mod-2)%mod-dp[n][0]+mod)%mod;
			cout<<ans<<endl;
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	//cin >> t;
	//read(t);
	pre[0]=1;
	for(int i=1; i<=N<<1; ++i)pre[i]=pre[i-1]*i%mod;
	inv[N<<1]=fastmi(pre[N<<1],mod-2);
	for(int i=(N<<1)-1; ~i; --i)inv[i]=inv[i+1]*(i+1)%mod;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

