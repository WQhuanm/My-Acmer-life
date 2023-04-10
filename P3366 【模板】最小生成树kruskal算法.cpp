#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 2e5 + 10;

struct node
{
	int u,v,w;
	bool operator<(const node&k)
	{
		return w<k.w;
	}
} edge[N<<1];
int fa[N];
int find(int x)
{
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}

int kruskal(int n,int m)
{
	int cnt=n,ans=0;//cnt记录图中集合个数
	sort(edge+1,edge+1+m);//排序边
	for(int i=1; i<=m; ++i)
		{
			int u=edge[i].u,v=edge[i].v,w=edge[i].w;
			int fu=find(u),fv=find(v);
			if(fu==fv)continue;//如果属于一个集合，该边舍去
			ans+=w;
			fa[fv]=fu;//合并集合
			cnt--;
		}
	return (cnt==1?ans:-1);//集合为一说明图连通
}

void mysolve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; ++i)fa[i]=i;
	for(int i=1; i<=m; ++i)cin>>edge[i].u>>edge[i].v>>edge[i].w;
	int ans=kruskal(n,m);
	if(ans==-1)cout<<"orz"<<endl;
	else cout<<ans<<endl;
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
