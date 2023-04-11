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
struct node
{
	int u,v,w;
	bool operator<(const node&k)const
	{
		return w>k.w;
	}
} b[N<<1];
vector<int>edge[N<<1];
int fa[N],val[N<<1],dep[N],pre[N][32];

int find(int x)//并查集
{
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}

void dfs(int u,int f)//遍历重构树建立深度与预处理lca
{
	dep[u]=dep[f]+1;
	pre[u][0]=f;
	for(int i=1; i<=20; ++i)pre[u][i]=pre[pre[u][i-1]][i-1];
	for(auto v:edge[u])if(v!=f)dfs(v,u);
}

int LCA(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	if(dep[u]>dep[v])
		{
			int k=log2(dep[u]-dep[v]);
			for(int i=k; i>=0; --i)if(dep[pre[u][i]]>=dep[v])u=pre[u][i];
		}
	if(u==v)return u;
	int k=log2(dep[u]);
	for(int i=k; i>=0; --i)if(pre[u][i]!=pre[v][i])u=pre[u][i],v=pre[v][i];
	return pre[u][0];
}

void mysolve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=2*n; ++i)fa[i]=i;
	for(int i=1; i<=m; ++i)cin>>b[i].u>>b[i].v>>b[i].w;
	sort(b+1,b+1+m);
	int cnt=n;
	for(int i=1; i<=m; ++i)//重构
		{
			int fu=find(b[i].u),fv=find(b[i].v);
			if(fu!=fv)
				{
					val[++cnt]=b[i].w;
					fa[fu]=fa[fv]=cnt;
					edge[cnt].push_back(fu),edge[cnt].push_back(fv);
				}
		}
	for(int i=cnt; i>n; --i)if(fa[i]==i)dfs(i,i);//可能是森林
	int q,x,y;
	cin>>q;
	while(q--)
		{
			cin>>x>>y;
			if(find(x)!=find(y))cout<<-1<<endl;
			else cout<<val[LCA(x,y)]<<endl;
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
