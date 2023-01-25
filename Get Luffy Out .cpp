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
const int N = 4445;

int mp[N], sta[N], low[N], dfn[N], scc[N], head[N], door[N][3], c[N], d[N];
bool insta[N];
int num, top, cnt, dfncnt;
struct node
{
	int next, to;
} edge[N * N];

int n, m, n1;
void add(int u, int v)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	head[u] = num;
}

void init()
{
	memset(head, 0, sizeof(head));
	memset(dfn, 0, sizeof(dfn));
	num = top = cnt = dfncnt = 0;
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
					if (u == v)break;
				}
		}
}

void build(int mid)
{
	init();
	for (int i = 1; i <= n; ++i)add(c[i], d[i] + n1), add(d[i], c[i] + n1);
	for (int i = 1; i <= mid; ++i)
		{
			add(door[i][0] + n1, door[i][1]);
			add(door[i][1] + n1, door[i][0]);
		}
}

bool jud()
{
	for (int i = 1; i <= 2 * n1; ++i)
		{
			if (!dfn[i])tarjan(i);
		}
	for (int i = 1; i <= n1; ++i)
		{
			if (scc[i] == scc[i + n1])return 0;
		}

	return 1;
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b;
	while (cin >> n >> m && (n || m))
		{
			n1 = n * 2 ;
			for (int i = 1; i <= n; ++i)
				{
					cin >> a >> b;
					c[i] = ++a, d[i] = ++b;
				}
			for (int i = 1; i <= m; ++i)
				{
					cin >> a >> b ;
					door[i][0] = ++a, door[i][1] = ++b;
				}
			int l = 1, r = m, ans = 0;
			while (l <= r)
				{

					int mid = (l + r) >> 1;
					build(mid);
					if (jud())
						{
							ans = mid;
							l = mid + 1;
						}
					else r = mid - 1;
				}
			cout << ans << endl;

		}
	return 0;
}

