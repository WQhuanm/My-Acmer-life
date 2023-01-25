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
const int N = 1e3 + 10;

int sta[N], dfn[N], scc[N], low[N], head[N], dis[N][3];
bool insta[N];
int num, top, dfncnt, cnt;

int n, a, b, s[5][3], s12, like[N][3], hate[N][3];
struct node
{
	int next, to;
} edge[N * N];

void init()
{
	memset(dfn, 0, sizeof(dfn));
	memset(head, 0, sizeof(head));
	num = top = dfncnt = cnt = 0;
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

bool mjudge(int mid)
{
	init();
	for (int i = 1; i <= n; ++i)for (int j = i + 1; j <= n; ++j)//建立任意两点之间在最大距离mid情况下可以确定的边
			{
				if (dis[i][0] + dis[j][0] > mid)add(i, j + n), add(j, i + n);
				if (dis[i][1] + dis[j][1] > mid)add(i + n, j), add(j + n, i);
				if (dis[i][0] + dis[j][1] + s12 > mid)add(i, j), add(j + n, i + n);
				if (dis[i][1] + dis[j][0] + s12 > mid)add(i + n, j + n), add(j, i);
			}
	//建立讨厌与喜欢的边
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
	//判断
	for (int i = 1; i <= n * 2; ++i)if (!dfn[i])tarjan(i);
	for (int i = 1; i <= n; ++i)if (scc[i] == scc[i + n])return 0;
	return 1;
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int x, y;
	while (cin >> n >> a >> b)
		{
			cin >> s[0][0] >> s[0][1] >> s[1][0] >> s[1][1];
			s12 = abs(s[0][0] - s[1][0]) + abs(s[0][1] - s[1][1]);
			for (int i = 1; i <= n; ++i)
				{
					cin >> x >> y;
					dis[i][0] = abs(s[0][0] - x) + abs(s[0][1] - y);//dis0表示到0点距离，dis1表示到1点距离
					dis[i][1] = abs(s[1][0] - x) + abs(s[1][1] - y);
				}
			for (int i = 1; i <= a; ++i)cin >> hate[i][0] >> hate[i][1];
			for (int i = 1; i <= b; ++i)cin >> like[i][0] >> like[i][1];
			int l = 0, r = 120000010, ans = -1;
			while (l <= r)//二分
				{
					int mid = (l + r) >> 1;
					//	cout << mid << endl;
					if (mjudge(mid))
						{
							r = mid - 1;
							ans = mid;
						}
					else 	l = mid + 1;
				}
			cout << ans << endl;
		}
	return 0;
}
