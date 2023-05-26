#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int INF = 0x3f3f3f3f;         //int型的INF
const double eps=1e-9;
const int N = 3e3 + 10;

vector<int>edge[N];
int mxans[N],mnans[N],mxdp[N][N],mndp[N][N],sz[N];
bool a[N];
int n;
void dfs(int u,int f)
{
	sz[u]=1;
	for(auto v:edge[u])if(v!=f)
			{
				dfs(v,u);
				for(int i=sz[u]; ~i; --i)for(int j=sz[v]; j; --j)
						{
							mxdp[u][i+j]=max(mxdp[u][i+j],mxdp[u][i]+mxdp[v][j]+2);
							mndp[u][i+j]=min(mndp[u][i+j],mndp[u][i]+mndp[v][j]+2);
							if(i)
								{
									mxans[i+j]=max(mxans[i+j],mxdp[u][i]+mxdp[v][j]+2);//这里不写mxdp[u][i+j],因为u的i+j是可以由i=0，j>0更新得到，但是子树合并必须ij均大于0合并，才算是最短路径的最大值，否者不符合最短路径的定义
									mnans[i+j]=min(mnans[i+j],mndp[u][i]+mndp[v][j]+2);
								}
						}
				sz[u]+=sz[v];
			}
}
void mysolve()
{

	cin>>n;
	for(int i=1; i<=n; ++i)
		{
			mxans[i]=-INF;
			mnans[i]=INF;
			for(int j=1; j<=n; ++j)mxdp[i][j]=-INF,mndp[i][j]=INF;
		}
	for(int i=1; i<=n; ++i)
		{
			cin>>a[i];
			if(a[i])mxdp[i][1]=mndp[i][1]=0,mxans[1]=mnans[1]=0;
		}
	int x,y;
	for(int i=1; i<n; ++i)cin>>x>>y,edge[x].push_back(y),edge[y].push_back(x);
	dfs(1,0);
	for(int i=1; i<=n; ++i)
		{
			if(mxans[i]>=0)cout<<mxans[i]<<" "<<mnans[i]<<endl;
			else
				cout<<-1<<" "<<-1<<endl;
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
