#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
typedef pair<int, int> pii;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
//double 型memset最大127，最小128
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const double eps=1e-9;
const int N = 1e6 + 10;
int a[N],sz[N],mn[N],mx[N],b[N];
vector<int>edge[N];
void dfs(int u,int f)
{
	sz[u]=1,mn[u]=a[u];
	mx[u]=0;
	for(auto v:edge[u])if(v!=f)
			{
				dfs(v,u);
				mx[u]=max(mx[u],sz[v]);
				sz[u]+=sz[v];
				mn[u]=min(mn[u],mn[v]);
			}
}
void mysolve()
{
	int n;
	cin>>n;
	int rt;
	for(int i=1; i<=n; ++i)
		{
			cin>>a[i];
			b[a[i]]=i;
			if(a[i]==0)rt=i;
		}
	int x;
	for(int i=2; i<=n; ++i)cin>>x,edge[x].push_back(i),edge[i].push_back(x);
	dfs(rt,-1);
	cout<<mx[rt]<<" ";
	for(int i=1; i<n; ++i)
		{
			if(mn[b[i]]>=i)cout<<n-sz[b[i]]<<" ";
			else cout<<"0 ";
		}
	cout<<n<<endl;
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
