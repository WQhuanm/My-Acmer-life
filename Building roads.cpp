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
const int N = 1010;

int sta[N], dfn[N], low[N], head[N], scc[N];
bool insta[N];
int num, dfncnt, cnt, top;

int s[4][4], hate[N][3], like[N][3], dis[N][3];
int n, a, b, dis12;

struct node
{
	int next, to;
} edge[N * N];

void init1()
{
	num = dfncnt = cnt = top = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(head, 0, sizeof(head));
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
	for (int i = 1; i <= n; ++i)for (int j = i + 1; j <= n; ++j)
			{
				if (dis[i][0] + dis[j][0] > mid)
					{
						add(i, j + n);
						add(j, i + n);
					}
				if (dis[i][1] + dis[j][1] > mid)
					{
						add(i + n, j);
						add(j + n, i);
					}
				if (dis[i][0] + dis[j][1] + dis12 > mid)add(i, j), add(j + n, i + n);
				if (dis[i][1] + dis[j][0] + dis12 > mid)add(i + n, j + n), add(j, i);
			}
	for (int i = 1; i <= a; ++i)
		{
			add(hate[i][0], hate[i][1] + n);
			add(hate[i][0] + n, hate[i][1]);
			add(hate[i][1], hate[i][0] + n);
			add(hate[i][1] + n, hate[i][0]);
		}
	for (int i = 1; i <= b; ++i)
		{
			add(like[i][0], like[i][1]);
			add(like[i][0] + n, like[i][1] + n);
			add(like[i][1], like[i][0]);
			add(like[i][1] + n, like[i][0] + n);
		}
}

bool jud()
{
	for (int i = 1; i <= 2 * n; ++i)if (!dfn[i])tarjan(i);
	for (int i = 1; i <= n; ++i)if (scc[i] == scc[i + n])return 0;
	return 1;
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (cin >> n >> a >> b)
		{
			cin >> s[0][0] >> s[0][1] >> s[1][0] >> s[1][1];
			dis12 = abs(s[0][0] - s[1][0]) + abs(s[0][1] - s[1][1]);
			int x, y;
			for (int i = 1; i <= n; ++i)
				{
					cin >> x >> y;
					dis[i][0] = abs(s[0][0] - x) + abs(s[0][1] - y);
					dis[i][1] = abs(s[1][0] - x) + abs(s[1][1] - y);
				}
			for (int i = 1; i <= a; ++i)
				{
					cin >> x >> y;
					hate[i][0] = x, hate[i][1] = y;
				}
			for (int i = 1; i <= b; ++i)
				{
					cin >> x >> y;
					like[i][0] = x, like[i][1] = y;
				}
			int ans = -1, l = 0, r = 12000010;
			while (l <= r)
				{
					init1();
					int mid = (l + r) >> 1;
					build(mid);
					if (jud())
						{
							ans = mid;
							r = mid - 1;
						}
					else l = mid + 1;
				}
			cout << ans << endl;
		}
	return 0;
}
