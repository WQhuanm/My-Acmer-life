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

vector<pii>edge[N];//建边，first为连接的点v，second为边权，为1说明边还存在，为0说明被删了
vector<bool>vis(N+1);
int dfs(int u)//dfs确认当前连通的图有多少个点连着
{
	vis[u]=1;
	int cnt=1;
	for (auto [v,w]:edge[u])if (!vis[v]&&w)cnt+=dfs(v);
	return cnt;
}

void mysolve()
{
	int n,m,x,y;
	cin>>n>>m;
	vector<int>in(n+1);
	vector<int>b(5,0);
	for (int i=1; i<=n; ++i)edge[i].clear();
	for (int i=1; i<=m; ++i)
		{
			cin>>x>>y,in[x]++,in[y]++,edge[x].push_back({y,1}),edge[y].push_back({x,1});
		}
	int k=sqrt(n);
	bool flag=0;
	if (k*k==n&&k*(k+1)==m)
		{
			for (int i=1; i<=n; ++i)
				{
					if (in[i]==2)b[0]++;
					else if (in[i]==4)b[1]++;
					else break;
				}
			if (b[0]+b[1]==n&&b[1]==k)
				{
					vis=vector<bool>(n+1);
					int cnt=dfs(1);
					if (cnt==n)
						{
							for (int i=1; i<=n; ++i)if (in[i]==4)//删除中心的k边型的边
									{
										for (int j=0; j<(int)edge[i].size(); ++j)
											{
												if (in[edge[i][j].first]>2)	edge[i][j].second=0;
											}
									}
							vis=vector<bool>(n+1);
							flag=1;
							for (int i=1; i<=n; ++i)if (!vis[i]&&dfs(i)!=k){//检验是否每个图像都为k边型
								flag=0;break;
							}
						
						}
				}
		}
	if (flag)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
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
