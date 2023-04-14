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
const int N = 2e5 + 10;

void mysolve()
{
	int n,w;
	while(cin>>n>>w)
		{
			vector<int>dp(w+1);
			int p,m,c,v;
			for(int i=1; i<=n; ++i)
				{
					vector<int>tmp=dp;
					cin>>p>>m;
					for(int j=1; j<=m; ++j)
						{
							cin>>c>>v;
							for(int k=w; k>=c; --k)
								{
									tmp[k]=max(tmp[k],tmp[k-c]+v);
									if(k+p<=w)dp[k+p]=max(dp[k+p],tmp[k]);
								}
						}
				}
			cout<<dp[w]<<endl;
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
