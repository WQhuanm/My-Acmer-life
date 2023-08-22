#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f

const int N = 3e5 + 10;

int n, m;
int val[N];
vector<pii> edge[N];
stack<pii>st;
int dfn[N], low[N];
int dfncnt, cnt, top;
ll ans;
void tarjan(int u, int fa)
{
	dfn[u] = low[u] = ++dfncnt;
	for (auto [v, id] : edge[u])
		{
			if (!dfn[v])
				{
					st.push({val[id], id});
					tarjan(v, id);
					low[u] = min(low[u], low[v]);
					if (low[v] >= dfn[u])
						{
							vector<int>tmp;
							while (1)
								{
									pii p = st.top();
									st.pop();
									tmp.push_back(p.first);
									if (p.second == id)break;
								}
							sort(tmp.begin(), tmp.end());
							if (tmp.size() == 1)ans = min(ans, tmp[0]);
							else if (tmp.size() == 2)ans = min(ans, tmp[0] + tmp[1]);
							else ans = min({ans, tmp[0] + tmp[1], tmp[2]});
						}
				}

			else
				{
					if (dfn[u] > dfn[v] && id != fa)st.push({val[id], id});
					low[u] = min(low[u], dfn[v]);
				}

		}
}
void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)edge[i].clear(), dfn[i] = 0;
	int x, y, w;
	for (int i = 1; i <= m; ++i)
		{
			cin >> x >> y >> w;
			edge[x].push_back({y, i}), edge[y].push_back({x, i});
			val[i] = w;
		}
	top = dfncnt = cnt = 0;
	ans = INF;
	for (int i = 1; i <= n; ++i)if (!dfn[i])tarjan(i, 0); //跑整个图的强连通，点为1~n
	cout << ans << endl;
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
