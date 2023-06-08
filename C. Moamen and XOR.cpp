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

int pre[N];

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
	int n,k;
	cin>>n>>k;
	if(k==0)
		{
			cout<<1<<endl;
			return;
		}
	vector<int>dp(k+1);
	//dp[0]=1;
	for(int i=1; i<=k; ++i)
		{
			if(n&1)dp[i]=(dp[i]+(dp[i-1]?dp[i-1]:1))%mod;
			else dp[i]=fastmi(pre[n],i-1);
			dp[i]=(dp[i]+(dp[i-1]?dp[i-1]:1)*(n&1?pre[n-1]:(pre[n-1]-1+mod)%mod)%mod)%mod;
		}
	cout<<dp[k]<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	pre[0]=1;
	for(int i=1; i<=N-5; ++i)pre[i]=(pre[i-1]<<1)%mod;
	cin >> t;
	//read(t);
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

