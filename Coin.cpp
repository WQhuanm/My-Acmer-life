#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define int              long long
const int N = 3e5 + 10;
int tot;
struct node
{
	int next, to;
	ll w;
} edge[N << 1];

int head[N], now[N], gap[N], dep[N], a[N], b[N], last[N];
int num = 1, n, m, s, t;
ll ans;

void init(int n)
{
	for (int i = 0; i <= tot; ++i)head[i] = 0;
	head[t] = 0;
	for (int i = 0; i <= n; ++i) last[i] = i;
	num = 1;
	ans = 0;
}

void add(int u, int v, ll w)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	edge[num].w = w;
	head[u] = num;

	edge[++num].next = head[v];
	edge[num].to = u;
	edge[num].w = 0;
	head[v] = num;
}

void bfs()
{
	for (int i = 0; i <= tot; ++i)dep[i] = -1, gap[i] = 0;
	dep[t] = 0;
	gap[0]++;
	queue<int>q;
	q.push(t);
	while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (int i = head[u]; i; i = edge[i].next)
				{
					int v = edge[i].to;
					ll w = edge[i ^ 1].w;
					if (dep[v] == -1 && w)
						{
							dep[v] = dep[u] + 1;
							gap[dep[v]]++;
							q.push(v);
						}
				}
		}
}

ll dfs(int x, ll sum)
{
	if (sum <= 0)return 0;///////////////
	if (x == t)
		{
			ans = (ans + sum);
			return sum;
		}
	ll k, res = 0;
	for (int i = now[x]; i && sum; i = edge[i].next)
		{
			now[x] = i;
			int v = edge[i].to;
			ll w = edge[i].w;
			if (dep[v] == dep[x] - 1 && w)
				{
					k = dfs(v, min({w, sum}));
					if (!k)continue;
					edge[i].w -= k;
					edge[i ^ 1].w += k;
					res = (res + k);
					sum = (sum - k);
					if (!sum)return res;
				}
		}
	gap[dep[x]]--;
	if (!gap[dep[x]])dep[s] = tot + 1;
	dep[x]++;
	gap[dep[x]]++;
	return res;
}

void mysolve()
{
	int k, x, y;
	cin >> n >> m >> k;
	s = 0, t = 3e5;
	init(n);
	tot = n + 2;

	a[0] = INF;
	for (int i = 1; i <= n; ++i)cin >> a[i], add(s, i, 1);
	for (int i = 1; i <= m; ++i)
		{
			cin >> x >> y;
			int lx = last[x], ly = last[y];
			add(lx, ly, 1), add(ly, lx, 1);
			last[x] = ++tot;
			last[y] = ++tot;
			add(lx, last[x], a[x]);
			add(ly, last[y], a[y]);
		}
	for (int i = 1; i <= k; ++i)cin >> b[i], add(last[b[i]], t, a[b[i]]);
	bfs();
	while (dep[s] < tot && dep[s] != -1)
		{
			for (int i = 0; i <= tot; ++i)now[i] = head[i];
			now[t] = head[t];
			dfs(s, INF);
		}
	cout << ans << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	return 0;
}
