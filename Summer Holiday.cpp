#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e3 + 10;

void read(int &x)
{
	x = 0;
	char c;
	while ((c = getchar()) < '0');
	do x = x * 10 + c - '0';
	while ((c = getchar()) >= '0');
}

int a[N], head[N], sta[N], dfn[N], low[N], scc[N], in[N], minn[N];
bool insta[N];
int num, dfncnt, cnt, top;
int n, m, x, y;
struct nodfe
{
	int next, to;
} edge[N];

void init()
{
	memset(dfn, 0, sizeof(dfn));
	memset(head, 0, sizeof(head));
	memset(edge, 0, sizeof(edge));
	memset(in, 0, sizeof(in));
	memset(minn, 0x3f, sizeof(minn));
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
			while (1)
				{
					int v = sta[top--];
					insta[v] = 0;
					scc[v] = cnt;
					minn[cnt] = min(minn[cnt], a[v]);
					if (u == v)break;
				}
		}
}

int main()
{
	while (cin >> n >> m)
		{
			init();
			for (int i = 1; i <= n; ++i)cin >> a[i];
			for (int i = 1; i <= m; ++i)
				{
					cin >> x >> y;
					add(x, y);
				}
			for (int i = 1; i <= n; ++i)if (!dfn[i])tarjan(i);
			for (int i = 1; i <= n; ++i)
				{
					int u = scc[i];
					for (int j = head[i]; j; j = edge[j].next)
						{
							int v = scc[edge[j].to];
							if (v != u)++in[v];
						}
				}
			int ans = 0, count = 0;
			for (int i = 1; i <= cnt; ++i)
				{
					if (!in[i])
						{
							++count;
							ans += minn[i];
						}
				}
			printf("%d %d\n", count, ans);
		}
	return 0;
}

