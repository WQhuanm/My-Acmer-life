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
const int N = 510;

#define pow(x) ((x)*(x))//定义取平方
struct circle
{
	int x,y,r;
} a[N];

double cal(circle a,circle b)
{
	double d=sqrt(pow(a.x-b.x)+pow(a.y-b.y));//先计算圆心距离d
	if(d>=a.r+b.r)return 0;//相离或者相切就返回0
	if(abs(a.r-b.r)>=d)return acos(-1)*pow(min(a.r,b.r));//内含，acos就是arccos()
	double c1=acos((pow(a.r)+pow(d)-pow(b.r))/(2*a.r*d)),c2=acos((pow(b.r)+pow(d)-pow(a.r))/(2*b.r*d));//计算夹角
	return c1*pow(a.r)+c2*pow(b.r)-sin(c1)*a.r*d;
}

struct node
{
	int u,v;
	double dis;
	bool operator<(const node&k)const
	{
		return dis>k.dis;
	}
} b[N*N];
int fa[N];
vector<int>edge[N];

int find(int x)
{
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}

void mysolve()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)cin>>a[i].x>>a[i].y>>a[i].r,edge[i].clear();
	priority_queue<int,vector<int>,greater<int>>q;
	vector<bool>vis(n+1);
	vector<int>in(n+1);
	int cnt=0;
	for(int i=1; i<=n; ++i)for(int j=i+1; j<=n; ++j)b[++cnt]= {i,j,cal(a[i],a[j])};//存入每个点之间的重叠面积
	sort(b+1,b+1+cnt);
	for(int i=1; i<=n; ++i)fa[i]=i;
	for(int i=1; i<=cnt; ++i)//贪心每次取最大的建立生成树
		{
			int fx=find(b[i].u),fy=find(b[i].v);
			if(fx==fy)continue;
			++in[b[i].u],++in[b[i].v];
			edge[b[i].u].push_back(b[i].v),edge[b[i].v].push_back(b[i].u);
			fa[fy]=fx;
		}
	for(int i=1; i<=n; ++i)if(in[i]<=1)q.push(i),vis[i]=1;;
	while(!q.empty())
		{
			int u=q.top();
			q.pop();
			cout<<u<<" ";
			for(auto v:edge[u])if(!vis[v]&&--in[v]<=1)q.push(v),vis[v]=1;
		}
	cout<<endl;
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
