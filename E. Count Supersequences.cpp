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
const int N = 2e5 + 10;
const int mod = 1e9+7;

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

int pre[N],p[N];

void mysolve()
{
	int n,m,k,x;
	cin>>n>>m>>k;
	p[0]=1;
	for(int i=1; i<=n; ++i)cin>>x;
	for(int i=1; i<=n; ++i)p[i]=p[i-1]*(m-i+1)%mod;
	ll ans=0;
	for(int i=0; i<n; ++i)
		{
			ans=(ans+p[i]*fastmi(pre[i],mod-2)%mod*fastmi(k-1,m-i))%mod;
		}
	ans=(fastmi(k,m)-ans+mod)%mod;
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	cin >> t;
	//read(t);
	pre[0]=1;
	for(int i=1; i<=N-2; ++i)pre[i]=pre[i-1]*i%mod;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

inline int read(int &x)
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
