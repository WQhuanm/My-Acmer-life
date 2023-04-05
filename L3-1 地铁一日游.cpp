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
const int N = 210;

int dp[N][N],tend[N];
vector<int>edge[N];
bool vis[N];
void dfs(int u)//dfs求可以经过的点
{
	vis[u]=1;
	for (auto v:edge[u])
		{
			if (!vis[v])dfs(v);
		}
}

void mysolve()
{
	int n,m,k;
	cin>>n>>m>>k;
	memset(dp,0x3f,sizeof(dp));
	int x,w,y;
	while (m--)
		{
			cin>>x;
			tend[x]=1;//tend存储首尾终点站
			while (1)
				{
					cin>>w>>y;
					dp[x][y]=dp[y][x]=min(dp[x][y],w);
					x=y;
					char c=getchar();
					if (c=='\n')break;
				}
			tend[x]=1;
		}
	for (int kk=1; kk<=n; ++kk)for (int i=1; i<=n; ++i)for (int j=1; j<=n; ++j)if (i!=j)dp[i][j]=min(dp[i][j],dp[i][kk]+dp[kk][j]);//floyd
	for (int i=1; i<=n; ++i)
		{
			unordered_map<int,int>cost;//cost[p]记录花费p时最远距离
			for (int j=1; j<=n; ++j)
				{
					if (dp[i][j]<INF)
						{
							int p=(dp[i][j])/k;
							if (dp[i][j]>cost[p])cost[p]=dp[i][j];
						}
				}
			for (int j=1; j<=n; ++j)if (dp[i][j]<INF&&(dp[i][j]==cost[dp[i][j]/k]||tend[j]))edge[i].push_back(j);//对于每个点，它如果符合是对于花费的最远点的距离或者他是终点站，那么可以建立单向边
		}
	int q;
	cin>>q;
	while (q--)
		{
			cin>>x;
			memset(vis,0,sizeof(vis));//询问每次dfs即可，记得初始化
			dfs(x);
			bool flag=1;
			for (int i=1; i<=n; ++i)if (vis[i])
					{
						if (flag)flag=0,cout<<i;
						else cout<<" "<<i;
					}
			cout<<endl;
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
