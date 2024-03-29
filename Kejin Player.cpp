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
const int N = 5e5 + 10;
const int mod=1e9+7;
int dp[N];
int r[N],s[N],x[N],a[N];

ll fastmi(ll base,ll power)
{
	ll ans=1;
	while(power)
		{
			if(power&1)ans=ans*base%mod;
			power>>=1,base=base*base%mod;
		}
	return ans;
}
void mysolve()
{
	int n,q;
	cin>>n>>q;
	for(int i=1; i<=n; ++i)cin>>r[i]>>s[i]>>x[i]>>a[i];
	dp[1]=0;
	for(int i=1; i<=n; ++i)
		{
			int p1=s[i]*fastmi(r[i],mod-2)%mod;//p1是1/pi
			dp[i+1]=((a[i]+dp[i])*p1%mod+(1-p1+mod)%mod*dp[x[i]]%mod)%mod;
		}
	int x,y;
	while(q--)
		{
			cin>>x>>y;
			cout<<(dp[y]-dp[x]+mod)%mod<<endl;
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
