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
const int N = 3e5 + 10;

int b[N];
vector<int>edge[N];
int sta[N], scc[N], dfn[N], low[N], sz[N];
bool insta[N];
int cnt, dfncnt, top;
int n, k;

inline void init()
{
	for (int i = 0; i <= n; ++i) dfn[i] = 0, edge[i].clear();
	top = dfncnt = cnt = 0;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++dfncnt;
	insta[u] = 1;
	sta[++top] = u;
	for (auto v : edge[u])
		{
			if (!dfn[v])//如果子代没有访问过，深入
				{
					tarjan(v);
					low[u] = min(low[u], low[v]);
				}
			else if (insta[v])low[u] = min(low[u], dfn[v]);//子代在里面说明成一个环
		}
	if (dfn[u] == low[u])
		{
			sz[++cnt] = 0; //强连通分量增加
			while (1)
				{
					int v = sta[top--];
					insta[v] = 0;
					scc[v] = cnt;//记录每个点属于的连通分量
					++sz[cnt];
					if (u == v)break;
				}
		}
}

void mysolve()
{
	cin >> n >> k;
	init();
	for (int i = 1; i <= n; ++i)cin >> b[i], edge[i].push_back(b[i]);
	if (k == 1)
		{
			for (int i = 1; i <= n; ++i)if (b[i] != i)return cout << "NO" << endl, void();
			return cout << "YES" << endl, void();
		}
	for (int i = 1; i <= n; ++i)if (b[i] == i)return cout << "NO" << endl, void();
	for (int i = 1; i <= n; ++i)if (!dfn[i])
			{
				int pre = cnt;
				tarjan(i);//跑整个图的强连通，点为1~n
				for (int i = pre + 1; i <= cnt; ++i)if (sz[i] > 1 && sz[i] != k)return cout << "NO" << endl, void();
			}
	cout << "YES" << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
