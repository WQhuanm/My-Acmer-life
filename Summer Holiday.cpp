#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e3 + 10;

int sta[N], head[N], dfn[N], low[N], scc[N], minn[N], a[N];
bool insta[N], in[N];
int num, cnt, dfncnt, top;
struct node
{
	int next, to;
} edge[N];

void init()
{
	memset(head, 0, sizeof(head));
	memset(dfn, 0, sizeof(dfn));
	memset(minn, 0x3f, sizeof(minn));
	memset(in, 0, sizeof(in));
	num = cnt = dfncnt = top = 0;
}

void add(int u, int v)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	head[u] = num;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++dfncnt;//起初让dfn=low
	insta[u] = 1;//insta记录栈中存在这个数
	sta[++top] = u;//记录栈顶为u
	for (int i = head[u]; i; i = edge[i].next)//遍历子代
		{
			int v = edge[i].to;
			if (!dfn[v])//如果子代没有访问过，深入
				{
					tarjan(v);
					low[u] = min(low[u], low[v]);//回来时，如果有形成环，就会更新low[u],没有的话，low[u]深度一定小于子代的
				}
			else if (insta[v])low[u] = min(low[u], dfn[v]);//如果子代遍历过，询问是否在栈内，是，那就说明形成一个环，记录环上第一个点的深度，说明深度low[u]=dfn[v]存在一个环
		}
	if (dfn[u] == low[u])//回来时，如果low仍然等于dfn，说明u是环起点（自己跟自己也算一个环
		{
			++cnt;//记录强连通分量增加
			while (1)
				{
					int v = sta[top--];//不断退栈，top指针指向栈顶，减少就是退栈
					insta[v] = 0;//标记已经退栈
					scc[v] = cnt;//scc记录点v属于第几个强连通分量cnt
					minn[cnt] = min(minn[cnt], a[v]);
					if (u == v)break;//当退完u这个起点，退出退栈操作
				}
		}
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, x, y;
	while (cin >> n >> m)
		{
			init();
			for (int i = 1; i <= n; ++i)cin >> a[i];
			for (int i = 1; i <= m; ++i)cin >> x >> y, add(x, y);
			for (int i = 1; i <= n; ++i)if (!dfn[i])tarjan(i);

			for (int i = 1; i <= n; ++i)
				{
					int u = scc[i];
					for (int j = head[i]; j; j = edge[j].next)
						{
							int v = scc[edge[j].to];
							if (v != u)in[v] = 1;
						}
				}
			int ans = 0, sum = 0;
			for (int i = 1; i <= cnt; ++i)if (!in[i])ans += minn[i], ++sum;
			cout << sum << ' ' << ans << endl;
		}
	return 0;
}
