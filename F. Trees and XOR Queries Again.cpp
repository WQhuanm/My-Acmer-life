#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
const int N = 3e5 + 10;

const int B = 19;
int s[N][B + 1], id[N][B + 1], s0[B + 1], id0[B + 1];
int zero;

int n;
int a[N];

void insert(int s[], int id[], int x, int pos)
{
	for (int i = B; ~i; --i)if (x & (1ll << i)) //从高位到低位尝试插入
			{
				if (!s[i]) //线性基该位置未被插入即可插入后退出
					{
						s[i] = x, id[i] = pos;
						return;
					}
				else
					{
						if (pos > id[i])
							{
								swap(pos, id[i]), swap(x, s[i]);
							}
						x ^= s[i];
					}
			}
	zero = 1; //如果能出来，说明没有插入成功，标记存在区间异或0
}

bool check( int x, int pos)
{
	if (!x)return 1;
	for (int i = B; ~i; --i)if (x & (1ll << i))
			{
				if (!s0[i] || id0[i] < pos)return 0; //存在二进制上线性基无法获得的位
				else x ^= s0[i];
			}
	return 1;
}

vector<int>edge[N];

int dep[N],  pre[N][32];
const int lg = 19; //5e5

void dfs1(int u, int f)
{
	dep[u] = dep[f] + 1;
	pre[u][0] = f;
	for (int i = 1; i <= lg; ++i)
		{
			pre[u][i] = pre[pre[u][i - 1]][i - 1];
		}
	insert(s[u], id[u], a[u], dep[u]);
	for (auto v : edge[u])if (v != f)
			{
				memcpy(s[v], s[u], sizeof(s[v]));
				memcpy(id[v], id[u], sizeof(id[v]));
				dfs1(v, u);
			}
}

inline int LCA(int u, int v)
{
	if (dep[v] != dep[u])//不相等时才求，否则出现log2(0)
		{
			if (dep[u] < dep[v])swap(u, v); //始终让u深度大
			for (int i = lg; ~i; --i)if (dep[pre[u][i]] >= dep[v])u = pre[u][i];
		}
	if (u == v)return u;
	for (int i = lg; ~i; --i)
		{
			if (pre[u][i] != pre[v][i])
				{
					u = pre[u][i];
					v = pre[v][i];
				}
		}
	return pre[v][0];//儿子的父亲才是LCA
}

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	int x, y, k, q;
	for (int i = 1; i < n; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	dfs1(1, 0);
	cin >> q;
	while (q--)
		{
			cin >> x >> y >> k;
			int pos = dep[LCA(x, y)];
			memcpy(s0, s[x], sizeof(s0));
			memcpy(id0, id[x], sizeof(id0));
			for (int i = B; ~i; --i)if (s[y][i])insert(s0, id0, s[y][i], id[y][i]);
			if (check( k, pos))cout << "YES" << endl;
			else cout << "NO" << endl;
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
