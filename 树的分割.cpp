#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 1e5 + 10;

vector<int>edge[N];
int idx[N],a[N],b[N];
int lmx[N],rmx[N],lmn[N],rmn[N],maxn[N],mx[N],mn[N];
ll ans,cnt;

void dfs1(int u,int f)
{
	idx[u]=++cnt,maxn[u]=cnt;
	mx[u]=mn[u]=b[cnt]=a[u];
	for(auto v:edge[u])if(v!=f)
			{
				dfs1(v,u);
				maxn[u]=max(maxn[u],maxn[v]);
				mx[u]=max(mx[u],mx[v]);
				mn[u]=min(mn[u],mn[v]);
			}
}

void dfs(int u,int f)
{
	for(auto v:edge[u])if(v!=f)
			{
				dfs(v,u);
				ll tmp=1ll*mn[v]*mx[v];
				int mx1=max(lmx[idx[v]-1],rmx[maxn[v]+1]),mn1=min(lmn[idx[v]-1],rmn[maxn[v]+1]);
				tmp+=1ll*mx1*mn1;
				ans=max(ans,tmp);
			}
}

void mysolve()
{
	int n,x,y;
	cin>>n;
	for(int i=1; i<=n; ++i)cin>>a[i];
	for(int i=0; i<=n+1; ++i)lmx[i]=rmx[i]=-inf,lmn[i]=rmn[i]=inf,edge[i].clear();
	for(int i=1; i<n; ++i)cin>>x>>y,edge[x].push_back(y),edge[y].push_back(x);
	cnt=0;
	ans=-INF;
	dfs1(1,0);
	for(int i=1; i<=n; ++i)lmx[i]=max(lmx[i-1],b[i]),lmn[i]=min(b[i],lmn[i-1]);
	for(int i=n; i; --i)rmx[i]=max(rmx[i+1],b[i]),rmn[i]=min(b[i],rmn[i+1]);
	dfs(1,0);
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

