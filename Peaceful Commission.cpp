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

int n, m, dfn[N], low[N], sta[N], scc[N], head[N];
bool insta[N], vis[N];
int num, top, dfncnt, cnt;

struct node
{
	int next, to;
} edge[N];

void init()
{
	memset(head, 0, sizeof(head));
	memset(dfn, 0, sizeof(dfn));
	memset(vis, 0, sizeof(vis));
	num = top = cnt = dfncnt = 0;
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

bool dfs(int u)//询问u点是否可以使用
{
	if (vis[u ^ 1])return 0;//如果同一个委员会另一人已经参加，他不能参加
	if (vis[u])return 1;//如果已经让他参加，直接返回1
	vis[u] = 1;//标记参加
	sta[++top] = u;//存入栈里面，方便后悔的时候取消访问的标记
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (!dfs(v))return 0;//u连向的所有v点（必须访问）只要有一个点不能访问，那么u点无法访问
		}
	return 1;//最终可以返回1
}

bool jud()
{
	for (int i = 0; i < 2 * n; ++i)if (!dfn[i])tarjan(i);
	for (int i = 0; i < 2 * n; i += 2)if (scc[i] == scc[i ^ 1])return 0;//判断是否同一个委员会两人一起参加

	for (int i = 0; i < 2 * n; i += 2)
		{
			if (!vis[i] && !vis[i ^ 1])//只有两人都没有参加过，才需要，有一人有参加已经符合情况
				{
					top = 0;//先把栈的指针指向0
					if (!dfs(i))//如果i不可以参加
						{
							while (top)vis[sta[top--]] = 0;//把存入栈的元素全部标记回去0
							if (!dfs(i ^ 1))return 0;//如果同一个委员会i^1还是不能参加，无解，返回0
						}
				}
		}

	return 1;
}

int  main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int x, y;
	while (cin >> n >> m)
		{
			init();
			for (int i = 1; i <= m; ++i)
				{
					cin >> x >> y;
					--x, --y;
					add(x, y ^ 1);
					add(y, x ^ 1);
				}

			if (jud())
				{
					for (int i = 0; i < 2 * n; ++i)if (vis[i])cout << i + 1 << endl;//记得i一开始-1，要加回去
				}
			else cout << "NIE" << endl;
		}
	return 0;
}
