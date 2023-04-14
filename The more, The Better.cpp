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
const int N =210;
int dp[N][N];
int a[N],cnt[N];
vector<int>edge[N];
int n,m;
void dfs(int u,int f)
{
	cnt[u]=1;
	dp[u][1]=a[u];
	for(auto v:edge[u])if(v!=f)
			{
				dfs(v,u);
				cnt[u]+=cnt[v];
				for(int i=m+1; i>=2; --i)for(int j=min(cnt[v],i-1); j>=1; --j)
						dp[u][i]=max(dp[u][i],dp[u][i-j]+dp[v][j]);
			}
}

void mysolve()
{

	while(cin>>n>>m&&(n||m))
		{
			memset(dp,0,sizeof(dp));
			for(int i=0; i<=n; ++i)edge[i].clear();
			int x;
			for(int i=1; i<=n; ++i)
				{
					cin>>x>>a[i];
					edge[x].push_back(i);
				}
			dfs(0,-1);
			cout<<dp[0][m+1]<<endl;

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
