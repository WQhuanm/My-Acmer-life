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
const int N = 1110;
double dp[N][N];
double a[20][N];
void mysolve()
{
	int tt;
	cin>>tt;
	for(int t1=1; t1<=tt; ++t1)
		{
			int n,m;
			cin>>n>>m;
			for(int i = 0; i <= m; i++)
				for(int j = 0; j <= (1<<n); j++) dp[i][j] = -1;
			dp[0][0] = 0;
			for(int i=1; i<=n; ++i)for(int j=1; j<=m; ++j)cin>>a[i][j];
			for(int i=1; i<=m; ++i)for(int j=0; j<(1<<n); ++j)if(dp[i-1][j]>=0)//确保j为0时，只有满足n个人循环才能进入j=0
						for(int k=0; k<n; ++k)
							{
								if(((j>>k)&1)==0)//没有k这个位置的人
									{
										int tmp=j|(1<<k);
										if(tmp==(1<<n)-1)tmp=0;
										dp[i][tmp]=max(dp[i][tmp],dp[i-1][j]+a[k+1][i]);
									}
							}
			double ans=0.0;
			for(int j=0; j<(1<<n); ++j)ans=max(dp[m][j],ans);
			printf("Case #%lld: %.5lf\n",t1,ans);
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
