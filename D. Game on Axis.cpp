#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e5 + 10;

int cnt[N], fa[N], head[N], num, n;//cnt[u]记录u正向边的父节点个数（从1到u路径上的点），fa[u]记录反向边的父节点是谁
bool vis[N], vis2[N];
struct node
{
	int next, to;
} edge[N];

void init()
{
	for (int i = 0; i <= n + 2; ++i)head[i] = 0, vis[i] = vis2[i] = 0;
	num = 0;
}

void add(int u, int v)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	head[u] = num;
}

void dfs(int u)//建立终点树
{
	vis[u] = 1;//在终点树上的点标记一下，表示可以到达终点
	cnt[u] = 1;
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (!vis[v])
				{
					dfs(v);
					cnt[u] += cnt[v];
				}
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, x;
	cin >> t;
	while (t--)
		{
			cin >> n;
			init();
			for (int i = 1; i <= n; ++i)
				{
					cin >> x;
					if (i + x > n || i + x < 1)fa[i] = 0;
					else fa[i] = i + x;
					add(fa[i], i);
				}
			dfs(0);
			cnt[0]--;
			int ans = 0;
			if (vis[1])//如果1可以到达终点
				{
					ans = (2 * n + 1) * n;
					int u = 1;//从1开始，往终点靠近
					while (u)//u不为0（终点）就不断靠近终点
						{
							ans -= (n - cnt[0] + cnt[u]);//n-cnt[0]表示无法到达终点的点，cnt[0]表示u的前驱，不可以去，否则成环
							u = fa[u];//每个点伸出的正向边只有一条
						}
				}
			else
				{
					int u = 1;//遍历1所在的这个环
					while (!vis2[u])
						{
							ans += cnt[0] + n + 1;//cnt[0]表示可以到达终点的点的数量（终点树节点的数量）
							vis2[u] = 1;//标记已经来过这个环上的点，不可以再来
							u = fa[u];
						}
				}
			cout << ans << endl;
		}

	return 0;
}
