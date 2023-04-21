#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
//double 型memset最大127，最小128
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 35;

ll ans;
int n,m,a[N][N];
int dp[N][N][2000];
int tt=0;
void mysolve()
{
	cin>>n>>m;
	for(int i=1; i<=n; ++i)for(int j=1; j<=m; ++j)cin>>a[i][j];
	memset(dp,0x3f,sizeof(dp));
	dp[1][1][a[1][1]]=a[1][1]*a[1][1];
	for(int i=1; i<=n; ++i)for(int j=1; j<=m; ++j)for(int k=0; k<=1800; ++k)
				{
					if(dp[i][j][k]<INF)
						{
							if(i<n)dp[i+1][j][k+a[i+1][j]]=min(dp[i+1][j][k+a[i+1][j]],dp[i][j][k]+a[i+1][j]*a[i+1][j]);
							if(j<m)dp[i][j+1][k+a[i][j+1]]=min(dp[i][j+1][k+a[i][j+1]],dp[i][j][k]+a[i][j+1]*a[i][j+1]);
						}
				}
	int ans=INF;
	for(int i=0; i<=1800; ++i)if(dp[n][m][i]<INF)ans=min(ans,(n+m-1)*dp[n][m][i]-i*i);
	cout<<"Case #"<<++tt<<": ";
	cout<<ans<<endl;

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
