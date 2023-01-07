#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e5 + 10;

int sta[N], dfn[N], low[N], head[N], scc[N], sz[N];
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
void init()
{
	memset(head, 0, sizeof(head));
	memset(edge, 0, sizeof(edge));
	memset(dfn, 0, sizeof(dfn));
	num = top = dfncnt = cnt = 0;

}
void tarjan(int u)
{
	dfn[u] = low[u] = ++dfncnt;
	sta[++top] = u;
	insta[u] = 1;
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (!dfn[v])
				{

					tarjan(v);
					low[u] = min(low[u], low[v]);
				}
			else if (insta[v])low[u] = min(low[u], dfn[v]);
		}
	if (low[u] == dfn[u])
		{
			++cnt;
			while (sta[top + 1] != u)
				{
					int v = sta[top--];
					insta[v] = 0;
					scc[v] = cnt;
					++sz[cnt];
				}
		}
}

int main()
{
	int n, m, a, b;
	while (cin >> n >> m && (n || m))
		{
			init();

			for (int i = 1; i <= m; ++i)
				{
					cin >> a >> b;
					add(a, b);
				}
			for (int i = 1; i <= n; ++i)if (!dfn[i])tarjan(i);
			if (cnt == 1)cout << "Yes" << endl;
			else cout << "No" << endl;
		}

	return 0;
}
