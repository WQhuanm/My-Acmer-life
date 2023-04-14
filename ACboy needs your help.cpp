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
const int N = 1100;

int a[N][N];
void mysolve()
{
	int n,m;
	while(cin>>n>>m&&(n||m))
		{
			for(int i=1; i<=n; ++i)for(int j=1; j<=m; ++j)cin>>a[i][j];
			vector<int>dp(m+1);
			for(int i=1; i<=n; ++i)for(int j=m; j>=0; --j)for(int k=j; k>=1; --k)dp[j]=max(dp[j],dp[j-k]+a[i][k]);
			cout<<dp[m]<<endl;
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
