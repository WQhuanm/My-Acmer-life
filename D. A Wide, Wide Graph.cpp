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
const int N = 1e5 + 10;

vector<int>edge[N];

void dfs(int u,int fa,vector<int>&dep)
{
	dep[u]=dep[fa]+1;
	for (auto v:edge[u])if (v!=fa)dfs(v,u,dep);
}

void mysolve()
{
	int n;
	int u,v;
	cin>>n;
	for (int i=1; i<n; ++i)cin>>u>>v,edge[u].push_back(v),edge[v].push_back(u);
	vector<int>dep1(n+1),dep2(n+1);
	dep1[0]=dep2[0]=-1;
	dfs(1,0,dep1);
	int a=max_element(dep1.begin()+1,dep1.end())-dep1.begin();
	dfs(a,0,dep1);
	int b=max_element(dep1.begin()+1,dep1.end())-dep1.begin();
	dfs(b,0,dep2);//三遍dfs
	vector<int>d(n+1);
	for (int i=1; i<=n; ++i)d[i]=max(dep1[i],dep2[i]);//每个点后两次的最深深度就是他们能处于的最长树径
	sort(d.begin()+1,d.end());
	int ans=1,p=1;
	for (int i=1; i<=n; ++i)
		{
			while (ans<n&&p<=n&&d[p]<i)ans++,p++;
			cout<<ans<<" \n"[i==n];
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
