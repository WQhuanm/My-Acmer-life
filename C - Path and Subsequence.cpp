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
bool flag=1;
int n,m,k;
bool vis[N];
struct node
{
	int next,to;
} edge[N<<1];
int num,head[N];
int a[N],b[N];
void add(int u,int v)
{
	edge[++num].next=head[u];
	edge[num].to=v;
	head[u]=num;
}
void dfs(int u,int p)
{
	if(!flag)return;
	vis[u]=1;
	if(p<k&&a[u]==b[p+1])p++;
	if(u==n)
		{
			if(p<k)flag=0;
			return;
		}
	for(int i=head[u]; i; i=edge[i].next)
		{
			int v=edge[i].to;
			if(!vis[v])
				{
					dfs(v,p);
				}
		}
	//vis[u]=0;
}
void mysolve()
{
	int x,y;
	cin>>n>>m>>k;
	while(m--)
		{
			cin>>x>>y;
			add(x,y),add(y,x);
		}
	for(int i=1; i<=n; ++i)cin>>a[i];
	for(int i=1; i<=k; ++i)cin>>b[i];
	dfs(1,0);
	if(flag)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
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
