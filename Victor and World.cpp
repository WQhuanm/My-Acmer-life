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
const int N = 20;
int dis[N][N],dp[1<<17][N],cnt[1<<17];
void mysolve()
{
	memset(dis,0x3f,sizeof(dis));
	memset(dp,0x3f,sizeof(dp));
	int n,m,x,y,w;
	cin>>n>>m;
	while(m--)cin>>x>>y>>w,x--,y--,dis[x][y]=dis[y][x]=min(dis[x][y],w);
	if(n==1)
		{
			cout<<0<<endl;
			return;
		}
	for(int k=0; k<n; ++k)for(int i=0; i<n; ++i)for(int j=0; j<n; ++j)dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
	dp[0][0]=0;
	for(int i=2; i<(1<<n); ++i)for(int j=0; j<n; ++j)if(i&(1<<j))
				{
					for(int k=0; k<n; ++k)dp[i][j]=min(dp[i][j],dp[i^(1<<j)][k]+dis[j][k]);
				}
	cout<<dp[(1<<n)-1][0]<<endl;
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
