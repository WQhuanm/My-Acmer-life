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

vector<int>edge[N << 2];

int dfn[N << 2], low[N << 2], sta[N << 2], scc[N << 2], sz[N << 2];
bool insta[N << 2];
int top, dfncnt, cnt, tot;
int n, m;

void tarjan(int u)
{
	dfn[u] = low[u] = ++dfncnt;
	insta[u] = 1;
	sta[++top] = u;
	for (auto v : edge[u])
		{
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
			sz[++cnt] = 0;
			while (1)
				{
					int v = sta[top--];
					insta[v] = 0;
					scc[v] = cnt;
					++sz[cnt];
					if (u == v)break;
				}
		}
}

bool solve()
{
	for (int i = 1; i <= 2 * n; ++i)if (!dfn[i])tarjan(i); //2n个元素，辅组点没必要
	for (int i = 1; i <= n; ++i)if (scc[i] == scc[i + n])return 0;//每个集合不能同时出现0与1
	return 1;
}

int k;
vector<int>kind[N];

void pre_dis(int u)//对集合u优化建图
{
	if ((int)kind[u].size() < 2)return;
	for (int i = 0; i < (int)kind[u].size(); ++i)
		{
			int now = kind[u][i], p_now = now <= n ? now + n : now - n;
			edge[++tot].push_back(p_now);
			if (i)edge[now].push_back(tot - 1), edge[tot].push_back(tot - 1);
		}
	for (int i = 0; i < (int)kind[u].size(); ++i) //处理后缀点
		{
			int now = kind[u][i], p_now = now <= n ? now + n : now - n;
			edge[now].push_back(++tot);
			if (i)edge[tot - 1].push_back(tot), edge[tot - 1].push_back(p_now);
		}
}

void mysolve()
{
	cin >> n >> m >> k;
	int x, y;
	while (m--)
		{
			cin >> x >> y;
			edge[x + n].push_back(y), edge[y + n].push_back(x);
		}
	tot = 2 * n;
	for (int i = 1; i <= k; ++i)
		{
			cin >> y;
			while (y--)cin >> x, kind[i].push_back(x);
			pre_dis(i);
		}
	if (solve())cout << "TAK" << endl;
	else cout << "NIE" << endl;
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
