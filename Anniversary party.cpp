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

int a[N];
vector<int>edge[N];
int dp[N][2];
int in[N];

void dfs(int u)
{
	dp[u][0]=0,dp[u][1]=a[u];
	for (auto v:edge[u])
		{
			dfs(v);
			dp[u][0]=max({dp[u][0]+dp[v][1],dp[u][0]+dp[v][0]});
			//dp[u][1]=max(dp[u][1],dp[u][1]+dp[v][0]);
			dp[u][1]+=dp[v][0];
		}
}

void mysolve()
{
	int n;
	while (cin>>n)
		{
			for (int i=1; i<=n; ++i)cin>>a[i],edge[i].clear();
			int x,y;
			while (cin>>x>>y&&(x||y))
				{
					//	swap(x,y);
					edge[y].push_back(x);
					in[x]++;
				}
			int ans=0;
			for (int i=1; i<=n; ++i)if (!in[i])
					{
						dfs(i);
						ans=max({dp[i][0],dp[i][1]});
						//cout<<dp[i][1]<<endl;
						break;
					}
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
