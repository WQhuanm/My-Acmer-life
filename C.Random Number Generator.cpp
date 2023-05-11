#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
int a,b,mod,x0,x1;

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
	cin>>a>>b>>mod>>x0>>x1;
	if(x0==x1)cout<<"YES"<<endl;
	else if(!a)cout<<(b==x1?"YES":"NO")<<endl;
	else if(a==1)cout<<(b?"YES":"NO")<<endl;
	else
		{
			int now=1,tmp=b*fastmi(a-1,mod-2)%mod;
			b=(x1+tmp)*fastmi(x0+tmp,mod-2)%mod;
			int m=ceil(sqrt(mod));
			unordered_map<int,int>mp;
			for(int i=1; i<=m; ++i)
				{
					now=now*a%mod;
					mp[b*now%mod]=i;
				}
			int ans=1;
			for(int i=1; i<=m; ++i)
				{
					ans=ans*now%mod;
					if(mp.count(ans))
						{
							cout<<"YES"<<endl;
							return;
						}
				}
			cout<<"NO"<<endl;
		}

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
