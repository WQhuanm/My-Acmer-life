#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
typedef pair<long long, long long> pll;

int way[5][3]= {{1,0},{0,1},{-1,0},{0,-1}};

void mysolve()
{
	int n,m,r,c,d;
	cin>>n>>m>>r>>c>>d;
	vector<vector<int>>a(n+1,vector<int>(m+1,0)),b(n+1,vector<int>(m+1,n+m)),vis(n+1,vector<int>(m+1,0));//a是占地面积的前缀和，b是每个点离建筑物的最小距离
	vector<string>s(n+1);
	queue<pll>q;
	for (int i=1; i<=n; ++i)
	{
		s[i].resize(m+1);
		for (int j=1; j<=m; ++j)
		{
			cin>>s[i][j];
			if (s[i][j]=='x')b[i][j]=0,q.push({i,j});
		}
	}
	while (!q.empty())//bfs处理最短距离
	{
		pll u=q.front();
		q.pop();
		for (int i=0; i<4; ++i)
		{
			int x=way[i][0]+u.first,y=way[i][1]+u.second;
			if (x>0&&x<=n&&y>0&&y<=m)
			{
				if (b[x][y]>b[u.first][u.second]+1)
				{
					b[x][y]=b[u.first][u.second]+1;
					q.push({x,y});
				}
			}
		}
	}
	for (int i=1; i<=n; ++i )for (int j=1; j<=m; ++j)//处理两个前缀和
	{
		a[i][j]=(s[i][j]=='.')+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		vis[i][j]=(b[i][j]<=d)+vis[i-1][j]+vis[i][j-1]-vis[i-1][j-1];
	}
	int ans=0;
	for (int i=1; i<=n&&i+r-1<=n; ++i)for (int j=1; j<=m&&j+c-1<=m; ++j)
	{
		ans+=((a[i+r-1][j+c-1]-a[i+r-1][j-1]-a[i-1][j+c-1]+a[i-1][j-1]==r*c)&&(vis[i+r-1][j+c-1]-vis[i+r-1][j-1]-vis[i-1][j+c-1]+vis[i-1][j-1]>0));//占地面积与最小距离条件同时满足时+1
	}
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		mysolve();
	}
	system("pause");
	return 0;
}
