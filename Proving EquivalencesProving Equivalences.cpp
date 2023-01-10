#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e4 + 10;

int sta[N], dfn[N], low[N], scc[N], head[N];
bool insta[N], vis1[N], vis2[N];
int num, cnt, dfncnt, top;
struct node
{
	int to, next;
} edge[N * 3];

void init()
{
	num = cnt = dfncnt = top = 0;
	memset(head, 0, sizeof(head));
	memset(dfn, 0, sizeof(dfn));
}

void add(int u, int v)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	head[u] = num;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++dfncnt;
	insta[u] = 1;
	sta[++top] = u;
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (!dfn[v])
				{
					tarjan(v);
					low[u] = min(low[u], low[v]);
				}
			else if (insta[v])low[u] = min(dfn[v], low[u]);
		}
	if (low[u] == dfn[u])
		{
			++cnt;
			vis1[cnt] = vis2[cnt] = 0;
			while (1)
				{
					int v = sta[top--];
					scc[v] = cnt;
					insta[v] = 0;
					if (u == v)break;
				}
		}
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, x, y, n, m;
	cin >> t;
	while (t--)
		{
			init();
			cin >> n >> m;
			for (int i = 1; i <= m; ++i)cin >> x >> y, add(x, y);
			for (int i = 1; i <= n; ++i)if (!dfn[i])tarjan(i);
			if (cnt == 1)cout << 0 << endl;
			else
				{
					for (int i = 1; i <= n; ++i)
						{
							int u = scc[i];
							for (int j = head[i]; j; j = edge[j].next)
								{
									int v = scc[edge[j].to];
									if (u != v)vis1[v] = 1, vis2[u] = 1;
								}
						}
					int ans1 = 0, ans2 = 0;
					for (int i = 1; i <= cnt; ++i)
						{
							if (!vis1[i])++ans1;
							if (!vis2[i])++ans2;
						}
					cout << max(ans1, ans2) << endl;
				}
		}
}
