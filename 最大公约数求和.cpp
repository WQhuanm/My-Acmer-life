#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 2e7 + 10;
const int mod=1000000007;
int m[N],g[N],ou[N];
bool vis[N];
ll fastmi(ll base,ll power)
{
	ll ans=1;
	while (power)
		{
			if (power&1)ans=ans*base%mod;
			base=base*base%mod;
			power>>=1;
		}
	return ans;
}

void mysolve()
{
	int n,k;
	cin>>n>>k;
	ll ans=g[1]=m[1]=1;//i为1时
	for (int i=2; i<=n; ++i)
		{
			if (!vis[i])
				{
					ou[++ou[0]]=i;
					g[i]=__gcd(i,k);//求出所有质数的快速幂与gcd
					m[i]=fastmi(i,k);
				}
			for (int j=1; i*ou[j]<=n&&j<=ou[0]; ++j)
				{
					vis[i*ou[j]]=1;
					m[i*ou[j]]=m[i]*m[ou[j]]%mod;
					if (i%ou[j]==0)//ou[j]是i的最小因数时，特判gcd
						{
							g[i*ou[j]]=g[i];
							if ((k/g[i])%ou[j]==0)g[i*ou[j]]*=ou[j];
							break;
						}
					g[i*ou[j]]=g[i]*g[ou[j]];//ou[j]不是x因子时
				}
			ans=(ans+g[i]*m[i])%mod;
		}
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	mysolve();
	system("pause");
	return 0;
}
