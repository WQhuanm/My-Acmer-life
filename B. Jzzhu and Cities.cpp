#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
inline int read(int &x);
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;

struct node
{
	int to;
	ll val;
};

vector<node>edge[N];
ll dis[N];
bool vis[N];
int cnt[N];

void dijkstra()
{
	priority_queue< pii,vector<pii>,greater<pii>>q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1]=0;
	q.push({dis[1],1});
	while(!q.empty())
		{
			int u=q.top().second;
			q.pop();
			if(vis[u])continue;//,可以被push到推无数次，但是只进来一次，那一次就是最小的
			vis[u]=1;
			for(node v:edge[u])
				{
					if(dis[v.to]>dis[u]+v.val)
						{
							dis[v.to]=dis[u]+v.val;
							cnt[v.to]=1;
							q.push({dis[v.to],v.to});//只要能更小，就可以被push
						}
					else if(dis[v.to]==dis[u]+v.val)
						{
							cnt[v.to]++;
						}
				}
		}
}

void mysolve()
{
	int n,m,k;
	cin>>n>>m>>k;
	int x,y,w;
	while(m--)
		{
			cin>>x>>y>>w;
			edge[x].push_back({y,w});
			edge[y].push_back({x,w});
		}

	int ans=0;
	vector<pii>b;
	while(k--)
		{
			cin>>x>>w,b.push_back({w,x});
			edge[x].push_back({1,w});
			edge[1].push_back({x,w});
		}
	dijkstra();
	for(pii v:b)
		{
			if(v.first>dis[v.second])ans++;
			else if(v.first==dis[v.second]&&cnt[v.second]>1)cnt[v.second]--,ans++;
		}

	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	//cin >> t;
	//read(t);
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

inline int read(int &x)
{
	x = 0;
	char ch = 0;
	while (ch < '0' || ch > '9')ch = getchar();
	while (ch >= '0' && ch <= '9')
		{
			x = x * 10 + ch - '0';
			ch = getchar();
		}
	return x;
}
