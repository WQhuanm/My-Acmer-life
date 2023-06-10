#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;

void mysolve()
{
	int n,m,r;
	cin>>n>>m>>r;
	vector dp(n+1,vector< vector<bool> >(m+1,vector<bool>(r+1,1)));
	int t,d,c;
	for(int i=1; i<=r; ++i)
		{
			cin>>t>>d>>c;
			if(d==1)
				{
					for(int i=0; i<=m; ++i)if(0<=t-i-c&&t-i-c<=r)dp[c][i][t-i-c]=0;
				}
			else for(int i=0; i<=n; ++i)if(0<=t-c-i&&t-i-c<=r)dp[i][c][t-i-c]=0;
		}
//	for(int i=0; i<=n; ++i)for(int j=0; j<=m; ++j)for(int k=0; k<=r; ++k)cout<<i<<" "<<j<<" "<<k<< " "<<dp[i][j][k]<<endl;
//	cout<<endl<<endl;
	vector f(n+1,vector (m+1,vector<bool>(r+1,0)));
	f[0][0][0]=1;
	for(int i=0; i<=n; ++i)for(int j=0; j<=m; ++j)for(int k=0; k<=r; ++k)
				{
					if(dp[i][j][k])
						{
							if(i&&f[i-1][j][k])f[i][j][k]=1;
							if(j&&f[i][j-1][k])f[i][j][k]=1;
							if(k&&f[i][j][k-1])f[i][j][k]=1;
						}
				}
	int ans=-1;
//	for(int i=0; i<=n; ++i)for(int j=0; j<=m; ++j)for(int k=0; k<=r; ++k)cout<<i<<" "<<j<<" "<<k<< " "<<f[i][j][k]<<endl;
	for(int i=r; ~i; --i)if(f[n][m][i])ans=n+m+i;
	cout<<ans<<endl;

}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
