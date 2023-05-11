#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 110;
const int mod=1e9+7;

int dp[2][25][1<<11];
char ch[N][15];

void update(int &x,int y)
{
	x=(x+y)%mod;
}
void mysolve()
{
	int n,m,c,d;
	while(cin>>n>>m>>c>>d)
		{
			memset(dp,0,sizeof(dp));
			for(int i=1; i<=n; ++i)cin>>ch[i];
			dp[0][0][(1<<m)-1]=1;
			int p=0;
			for(int i=1; i<=n; ++i)for(int j=0; j<m; ++j)
					{
						p^=1;
						memset(dp[p],0,sizeof(dp[p]));
						if(ch[i][j]=='1')
							{
								for(int t=0; t<=d; ++t)
									for(int k=0; k<(1<<m); ++k)
										{
											if(!(k&(1<<j)))update(dp[p][t][k|(1<<j)],dp[p^1][t][k]);
											else
												{
													if(j&&!(k&(1<<(j-1))))update(dp[p][t][k|(1<<j)|(1<<(j-1))],dp[p^1][t][k]);
													update(dp[p][t][k&(~(1<<j))],dp[p^1][t][k]);
													update(dp[p][t+1][k|(1<<j)],dp[p^1][t][k]);
												}
										}
							}
						else for(int t=0; t<=d; ++t)for(int k=0; k<(1<<m); ++k)if(k&(1<<j))update(dp[p][t][k|(1<<j)],dp[p^1][t][k]);
					}
			int ans=0;
			for(int i=c; i<=d; ++i)ans=(ans+dp[p][i][(1<<m)-1])%mod;
			cout<<ans<<endl;
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
