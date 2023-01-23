#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 4e4 + 10;

int sta[N], dfn[N], low[N], scc[N], head[N];
bool insta[N], vis[N];
int num, dfncnt, cnt, top;
int n, m;

struct node
{
	int to, next;
} edge[N];

void init()
{
	memset(dfn, 0, sizeof(dfn));
	memset(head, 0, sizeof(head));
	memset(vis, 0, sizeof(vis));
	num = dfncnt = cnt = top = 0;
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
			else if (insta[v])
				{
					low[u] = min(dfn[v], low[u]);
				}
		}
	if (low[u] == dfn[u])
		{
			++cnt;
			while (1)
				{
					int v = sta[top--];
					insta[v] = 0;
					scc[v] = cnt;
					if (u == v)break;
				}
		}

}

bool dfs(int u)
{
	if (vis[u ^ 1])return 0;
	if (vis[u])return 1;
	vis[u] = 1;
	sta[++top] = u;
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (!dfs(v))return 0;
		}
	return 1;
}

bool jud()
{
	for (int i = 0; i < 2 * n; i += 2)
		{
			if (scc[i] == scc[i ^ 1])return 0;
		}

	for (int i = 0; i < 2 * n; i += 2)
		{
			if (!vis[i] && !vis[i ^ 1])
				{
					top = 0;
					if (!dfs(i))
						{
							while (top)vis[sta[top--]] = 0;
							if (!dfs(i ^ 1))return 0;
						}
				}
		}
	return 1;
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b;
	while (cin >> n >> m)
		{
			init();
			for (int i = 1; i <= m; ++i)
				{
					cin >> a >> b;
					--a, --b;
					add(a, b ^ 1);
					add(b, a ^ 1);
				}

			for (int i = 0; i < 2 * n; ++i)if (!dfn[i])tarjan(i);
			if (jud())
				{
					for (int i = 0; i < 2 * n; ++i)
						{
							if (vis[i])cout << i + 1 << endl;
						}
				}
			else cout << "NIE" << endl;
		}

	return 0;
}
