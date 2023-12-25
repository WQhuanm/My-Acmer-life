#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略

const int M = 55, N = M * M;

int n, m, s, t, num;
int head[N<<1], cost[N], pre[N];
ll dis[N];
bool vis[N];
ll ans, sum;
struct node
{
	int to, next;
	ll w, c;
} edge[N<<1];

void add(int u, int v, ll w, ll c)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	edge[num].w = w;
	edge[num].c = c;
	head[u] = num;

	edge[++num].next = head[v];
	edge[num].w = 0; //反向边还是边权0
	edge[num].c = -c; //注意，反向边费用为负值（因为后悔嘛）
	edge[num].to = u;
	head[v] = num;
}

bool bfs()
{
	memset(vis, 0, sizeof(vis));
	memset(cost, 0x3f, sizeof(cost)); //初始费用无穷
	cost[s] = 0; //起点费用为0
	vis[s] = 1;
	dis[s] = INF;
	queue<int>q;
	q.push(s);
	while (!q.empty())
		{
			int x = q.front();
			q.pop();
			vis[x] = 0; //spfa进来就标记为没有访问过
			for (int i = head[x]; i; i = edge[i].next)
				{
					if (!edge[i].w)continue; //边权0，过
					int v = edge[i].to;
					if (cost[v] > cost[x] + edge[i].c)
						{
							pre[v] = i; //记录前驱
							cost[v] = cost[x] + edge[i].c; //注意，比的是费用，不是边权
							dis[v] = min(dis[x], edge[i].w); //储存该增广路上最小容量
							if (!vis[v])vis[v] = 1, q.push(v); //spfa,既然我来了，没存过我就要进
						}
				}
		}
	return cost[t] != INF; //t的费用被改过，就是找到一条增广路
}

void update()
{
	int v = t;
	while (v != s)
		{
			int tmp = pre[v];
			edge[tmp].w -= dis[t];
			edge[tmp ^ 1].w += dis[t];
			v = edge[tmp ^ 1].to;
		}
	ans += dis[t];
	sum += dis[t] * cost[t];
}

int a[M][M];
int b[M], c[M];

void mysolve()
{
	cin >> n >> m  ;
	s = 0, t = n + m + 1;
	num = 1, ans = sum = 0;
	int cnt = 0;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
			{
				cin >> a[i][j];
				if (a[i][j])add(i, n + j, 1, -1), sum++;
				else add(i, n + j, 1, 1);
			}
	for (int i = 1; i <= n; ++i)cin >> b[i], add(s, i, b[i], 0), cnt += b[i];
	for (int j = 1; j <= m; ++j)cin >> c[j], add(n + j, t, c[j], 0);
	while (bfs())
		update();
	if (ans != cnt)cout << -1 << endl;
	else cout << sum << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
