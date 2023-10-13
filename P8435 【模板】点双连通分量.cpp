#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const long long mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 1e6 + 10;

int n, m;
int dfncnt, top, cnt;
int dfn[N], low[N], sta[N];
vector<int>bcc[N], edge[N];

void init()
{
	top = cnt = dfncnt = 0;
	for (int i = 0; i <= n; ++i)dfn[i] = 0;
}

void tarjan(int u, int f)
{
	dfn[u] = low[u] = ++dfncnt;
	sta[++top] = u;
	bool fl = 1, son = 0;
	for (int v : edge[u])
		{
			if (v == f && fl)
				{
					fl = 0;
					continue;
				}
			if (!dfn[v])
				{
					son = 1;//判断有无儿子
					tarjan(v, u);
					low[u] = min(low[u], low[v]);
					if (low[v] >= dfn[u])
						{
							bcc[++cnt].clear();
							while (sta[top + 1] != v)bcc[cnt].push_back(sta[top--]);//v部分被u割断
							bcc[cnt].push_back(u);//放入割点u
						}
				}
			else low[u] = min(low[u], dfn[v]);
		}
	if (!son && !f)bcc[++cnt].clear(), bcc[cnt].push_back(u);//特判孤立点
}

void mysolve()
{
	cin >> n >> m;
	int x, y;
	while (m--)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	for (int i = 1; i <= n; ++i)if (!dfn[i])tarjan(i, 0);
	cout << cnt << endl;
	for (int i = 1; i <= cnt; ++i)
		{
			cout << bcc[i].size();
			for (int v : bcc[i])cout << " " << v;
			cout << endl;
		}
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
