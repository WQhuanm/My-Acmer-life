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
set<int>st1,st2;
unordered_map<int,int>cnt1,cnt2;
vector<pii>edge[N];
pii b[N];
int a[N];
int ans1,ans2;
bool vis[N];
vector<int>path,inpath;

bool dfs1(int u,int tar)//dfs求路径点与边
{
	path.push_back(u);
	vis[u]=1;
	if (u==tar)return 1;
	for (auto [v,in]:edge[u])
		{
			if (vis[v])continue;
			inpath.push_back(in);
			if (dfs1(v,tar))return 1;
			inpath.pop_back();
		}
	path.pop_back();
	return 0;
}

void todis(int u,int l,int r)//更新蓝色侵蚀部分
{
	cnt1[a[u]]--,cnt2[a[u]]++;
	if (cnt1[a[u]]<2)st1.erase(a[u]);
	if (cnt2[a[u]]>1)st2.insert(a[u]);
	for (auto [v,in]:edge[u])
		{
			if (v!=l&&v!=r)
				{
					todis(v,u,0);
				}
		}
}

int dis()//获取当前两个子树的最大M
{
	int ans=0;
	if (!st1.empty())ans=max(ans,*st1.rbegin());
	if (!st2.empty())ans=max(ans,*st2.rbegin());
	return ans;
}

void mysolve()
{
	int n;
	cin>>n;
	int x,y;
	for (int i=1; i<n; ++i)
		{
			cin>>x>>y;
			edge[x].push_back({y,i}),edge[y].push_back({x,i});//存储信息是对应的点及边的编号
		}
	for (int i=1; i<=n; ++i)
		{
			cin>>a[i];
			cnt1[a[i]]++;
			if (cnt1[a[i]]>1)st1.insert(a[i]);
		}
	if (st1.empty())for (int i=1; i<n; ++i)cout<<0<<endl;
	else if (cnt1[*st1.rbegin()]>2)for (int i=1; i<n; ++i)cout<<(*st1.rbegin())<<endl;
	else
		{
			vector<int>ans(n+1);
			for (int i=1; i<n; ++i)ans[i]=(*st1.rbegin());
			set<int>point;//记录x,y点
			for (int i=1; i<=n; ++i)if (a[i]==*st1.rbegin())point.insert(i);
			dfs1(*point.begin(),*point.rbegin());//找xy路径
			todis(path[0],path[1],0);
			ans[inpath[0]]=dis();
			for (int i=1; i+1<(int)path.size(); ++i)
				{
					todis(path[i],path[i-1],path[i+1]);
					ans[inpath[i]]=dis();
				}
			for (int i=1; i<n; ++i)cout<<ans[i]<<endl;
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
