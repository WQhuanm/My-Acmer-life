#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
const int N = 3e6 + 10;

int n, m;
int dfncnt, top, cnt, sum;
int dfn[N], low[N], sta[N], val[N], sz[N];//空间是n+m（一般是n<<1),否则re
vector<int> edge[N], eg[N];

void tarjan(int u, int f)
{
	sum++;
	val[u] = -1;
	dfn[u] = low[u] = ++dfncnt;
	sta[++top] = u;
	bool fl = 1;
	for (int v : edge[u])
		{
			if (v == f && fl)
				{
					fl = 0;
					continue;
				}
			if (!dfn[v])
				{
					tarjan(v, u);
					low[u] = min(low[u], low[v]);
					if (low[v] >= dfn[u])
						{
							val[++cnt] = 1;
							eg[u].push_back(cnt), eg[cnt].push_back(u);
							while (1)
								{
									int now = sta[top--];
									eg[now].push_back(cnt), eg[cnt].push_back(now);
									++val[cnt];
									if (now == v)break;
								}
						}

				}
			else low[u] = min(low[u], dfn[v]);
		}
}

ll ans = 0;
void dfs(int u, int f)
{
	sz[u] = u <= n;
	ll tmp = 0;
	for (auto v : eg[u])if (v != f)
			{
				dfs(v, u);
				tmp += 2ll * sz[u] * sz[v];
				sz[u] += sz[v];
			}
	tmp += 2ll * sz[u] * (sum - sz[u]);
	ans += tmp * val[u];
}

void mysolve()
{
	cin >> n >> m;
	int x, y;
	while (m--)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	cnt = n;
	ans = 0;
	for (int i = 1; i <= n; ++i)
		if (!dfn[i])
			{
				top = sum = 0, tarjan(i, 0);
				dfs(i, 0);
			}
	cout << ans << endl;
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
