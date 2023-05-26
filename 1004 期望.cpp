#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 3e5 + 10;
const int mod=1e9+7;

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
	int n;
	cin>>n;
	int ans=0;
	for(int i=3; i<=2*n-1; ++i)
		ans=(ans+((min(i-1,n)+i/2+1)*(min(i-1,n)-i/2)/2)%mod*fastmi(i,mod-2)%mod)%mod;
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
