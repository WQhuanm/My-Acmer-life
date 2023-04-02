#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
typedef pair<int, int> pii;
const int N = 110;

struct node
{
	int d,x,y,p,f;
	bool operator<(const node&k)const
	{
		return d>k.d;
	}
};
int dp[N][N][60][5];
bool vis[N][N][60][5];
int ways[5][3]= {{-1,0},{1,0},{0,-1},{0,1}};
pii mp[N][N];
char ch[N][N];
int32_t main()
{
	int n,m,p,k;
	cin>>n>>m>>k>>p;
	int x1,y1,x2,y2;
	for (int i=1; i<=k; ++i)
		{
			cin>>x1>>y1>>x2>>y2;
			mp[x1][y1]= {x2,y2};
			mp[x2][y2]= {x1,y1};
		}
	memset(dp,0x3f,sizeof(dp));
	for (int i=1; i<=n; ++i)for (int j=1; j<=m; ++j)
			{
				cin>>ch[i][j];
				if (ch[i][j]=='U')ch[i][j]='0';
				else if (ch[i][j]=='D')ch[i][j]='1';
				else if (ch[i][j]=='L')ch[i][j]='2';
				else if (ch[i][j]=='R')ch[i][j]='3';
			}
	priority_queue<node>q;
	dp[1][1][0][3]=0;
	q.push({0,1,1,0,3});
	while (!q.empty())
		{
			node u=q.top();
			q.pop();
			if (vis[u.x][u.y][u.p][u.f])continue;
			vis[u.x][u.y][u.p][u.f]=1;
			if (u.x==n&&u.y==m)
				{
					cout<<"YES"<<endl;
					cout<<dp[u.x][u.y][u.p][u.f]<<endl;
					return 0;
				}
			if (ch[u.x][u.y]=='.')
				{
					for (int i=0; i<4; ++i)
						{
							node v=u;
							v.x+=ways[i][0],v.y+=ways[i][1],v.p+=(i!=v.f);
							v.f=i;
							if (1<=v.x&&v.x<=n&&1<=v.y&&v.y<=m&&ch[v.x][v.y]!='#')
								{
									if (mp[v.x][v.y].first!=0)
										{
											pii tmp=mp[v.x][v.y];
											v.x=tmp.first,v.y=tmp.second;
										}
									if (v.p<=p&&dp[v.x][v.y][v.p][v.f]>dp[u.x][u.y][u.p][u.f]+1)
										{
											dp[v.x][v.y][v.p][v.f]=v.d=dp[u.x][u.y][u.p][u.f]+1;
											q.push(v);
										}
								}
						}
				}
			else if (('0'<=ch[u.x][u.y]&&ch[u.x][u.y]<='3')||ch[u.x][u.y]=='@')
				{
					node v=u;
					if (ch[u.x][u.y]!='@')v.f=ch[u.x][u.y]-'0';
					v.x+=ways[v.f][0],v.y+=ways[v.f][1];
					if (1<=v.x&&v.x<=n&&1<=v.y&&v.y<=m&&ch[v.x][v.y]!='#')
						{
							if (mp[v.x][v.y].first!=0)
								{
									pii tmp=mp[v.x][v.y];
									v.x=tmp.first,v.y=tmp.second;
								}
							if (v.p<=p&&dp[v.x][v.y][v.p][v.f]>dp[u.x][u.y][u.p][u.f]+1)
								{
									dp[v.x][v.y][v.p][v.f]=v.d=dp[u.x][u.y][u.p][u.f]+1;
									q.push(v);
								}
						}
				}
		}
	cout<<"NO"<<endl;
	return 0;
}
