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
const int N = 1e6 + 10;
double dp[N],sum[N];
ll fastmi(ll base,ll power)
{
	ll ans=1;
	while(power)
		{
			if(power&1)ans=ans*base;
			power>>=1,base=base*base;
		}
	return ans;
}
void mysolve()
{
	int t;
	while(cin>>t)
		{
			int op,m,n;
			for(int i=1; i<=t; ++i)
				{
					cin>>op>>m>>n;
					if(!op)
						{
							double ans=1.0;
							if(m>1)ans=(1-fastmi(m,n))*1.0/(1.0-m);
							printf("%.9lf\n",ans);
						}
					else
						{
							dp[1]=1.0;
							for(int i=1; i<n; ++i)
								{
									sum[i]=sum[i-1]+dp[i];
									dp[i+1]=(m*(dp[i]+1)-sum[i])*1.0/(m*1.0-i);
								}

							printf("%.9lf\n",dp[n]);
						}
				}
		}
}

int32_t main()
{
	//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
