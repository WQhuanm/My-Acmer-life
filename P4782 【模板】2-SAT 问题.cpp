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
const int N = 2e6 + 10;

int dfn[N], sta[N], low[N], scc[N], head[N];
bool insta[N];

int num, top, dfncnt, cnt;

struct node
{
	int next, to;
} edge[N];

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

	if (dfn[u] == low[u])
		{
			++cnt;
			while (1)
				{
					int v = sta[top--];
					insta[v] = 0;
					scc[v] = cnt;
					if (v == u)break;
				}
		}
}

int main()
{
	int n, m, x, y, a, b;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		{
			cin >> x >> a >> y >> b;
			add(x + n * (!a), y + n * (b));
			add(y + n * (!b), x + n * a);
		}
	for (int i = 1; i <= 2 * n; ++i)if (!dfn[i])tarjan(i);
	for (int i = 1; i <= n; ++i)if (scc[i] == scc[i + n])
			{
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}
	cout << "POSSIBLE" << endl;
	for (int i = 1; i <= n; ++i)
		{
			cout << (scc[i] > scc[i + n]);
			if (i == n)cout << endl;
			else cout << " ";
		}
	return 0;
}

