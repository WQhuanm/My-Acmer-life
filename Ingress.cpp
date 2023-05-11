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

int dp[1<<17][N],dis[N][N];
int a[N],b[N];
int tt=0;
void mysolve()
{
	memset(dis,0x3f,sizeof(dis));
	memset(dp,0x3f,sizeof(dp));
	int n,m,k,l,x,y,w;
	cin>>n>>m>>k>>l;
	for(int i=1; i<=n; ++i)cin>>a[i];
	for(int i=1; i<=n; ++i)cin>>b[i];
	while(m--)
		{
			cin>>x>>y>>w;
			dis[x][y]=dis[y][x]=min(dis[x][y],w);
		}
	for(int k=0; k<=n; ++k)for(int i=0; i<=n; ++i)for(int j=0; j<=n; ++j)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	dp[0][0]=0;
	int ans=0;
	for(int i=1; i<(1<<n); ++i)
		{
			bool flag=0;
			for(int j=0; j<n; ++j)if(i&(1<<j))
					{
						for(int h=0; h<=n; ++h)if(dp[i^(1<<j)][h]<INF)
								{
									dp[i][j+1]=min(dp[i][j+1],dp[i^(1<<j)][h]+dis[h][j+1]);
								}
						if(dp[i][j+1]+dis[j+1][0]<=l)flag=1;
					}
			if(flag)
				{
					priority_queue<pii>q;
					for(int j=0; j<n; ++j)if(i&(1<<j))q.push({a[j+1],j+1});
					int tmp=0,cnt=0;
					while(!q.empty()&&cnt<k)
						{
							pii x=q.top();
							q.pop();
							tmp+=x.first,cnt++;
							if(x.first-b[x.second]>0)q.push({x.first-b[x.second],x.second});
						}
					ans=max(ans,tmp);
				}
		}
	cout<<"Case "<<++tt<<": ";
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
