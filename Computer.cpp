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

vector<pii>edge[N];

void dfs(int u,int f,int w,vector<int>&dis)
{
	dis[u]=dis[f]+w;
	for( pii k:edge[u])if(k.first!=f)dfs(k.first,u,k.second,dis);
}

void mysolve()
{
	int n;
	while(cin>>n)
		{
			int x,y;
			for(int i=1; i<=n; ++i)edge[i].clear();
			for(int i=2; i<=n; ++i)cin>>x>>y,edge[i].push_back({x,y}),edge[x].push_back({i,y});
			vector<int>dis1(n+1),dis2(n+1);
			dfs(1,0,0,dis1);
			int a=max_element(dis1.begin()+1,dis1.end())-dis1.begin();
			dfs(a,0,0,dis1);
			int b=max_element(dis1.begin()+1,dis1.end())-dis1.begin();
			dfs(b,0,0,dis2);
			for(int i=1; i<=n; ++i)cout<<max(dis1[i],dis2[i])<<endl;
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
