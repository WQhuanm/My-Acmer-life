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
const int N = 5e5+ 10;
const int mod=1e9+7;
inline ll read(ll &x)
{
	x = 0;
	char ch = 0;
	while (ch < '0' || ch > '9')ch = getchar();
	while (ch >= '0' && ch <= '9')
		{
			x = x * 10 + ch - '0';
			ch = getchar();
		}
	return x;
}
int r[N],s[N],x[N],a[N];
int dp[N];

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
	int n,q;
	read(n),read(q);
	for(int i=1; i<=n; ++i)read(r[i]),read(s[i]),read(x[i]),read(a[i]);
	dp[1]=0;
	for(int i=1; i<=n; ++i)
		{
			//int p=r[i]*fastmi(s[i],mod-2)%mod;
			//dp[i+1]=(a[i]+dp[i]-(1-p)*dp[x[i]]%mod+mod)%mod*fastmi(p,mod-2)%mod;
			int pn=s[i]*fastmi(r[i],mod-2)%mod;
			dp[i+1]=((a[i]+dp[i])*pn%mod-(pn-1)*dp[x[i]]%mod+mod)%mod;
		}
	int l,r;
	while(q--)
		{
			read(l),read(r);
			cout<<(dp[r]-dp[l]+mod)%mod<<endl;
		}
}

int32_t main()
{
//	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
