#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-8
#define int              long long
typedef pair<int, int> pii;
const int N = 2e6 + 10;

struct node
{
	ll  id, x, y, p, q, t, vis;
	bool operator<(const node&k)const
	{
		if (t != k.t)
			return t < k.t;
		else return vis > k.vis;
	}
} a[N];

int head[N], tail[N];
pii dp[N];
vector<pii>Q[N];
bool vis[N];
ll res[N];
ll n, m, A, B, C;

void mysolve()
{
	cin >> n >> m >> A >> B >> C;
	for (int i = 1; i <= n; ++i)head[i] = 0, tail[i] = -1, res[i] = INF;
	head[1] = tail[1] = 0, Q[1].push_back({0, 0});
	ll x, y, p, q;
	for (int i = 1; i <= m; ++i)
		{
			cin >> x >> y >> p >> q;
			a[i] = {i, x, y, p, q, p, 0}, a[i + m] = {i, x, y, p, q, q, 1};
		}
	sort(a + 1, a + 1 + 2 * m);
	ll ans = INF;
	for (int i = 1; i <= 2 * m; ++i)
		{
			x = a[i].x, y = a[i].y, p = a[i].p, q = a[i].q;
			if (!vis[a[i].id])
				{
					vis[a[i].id] = 1;
					if (!Q[x].empty())
						{
							ll k = 2 * A * p;
							while (head[x] + 1 <= tail[x] && (1.0 * Q[x][head[x]].second - Q[x][head[x] + 1].second) / (1.0 * Q[x][head[x]].first - Q[x][head[x] + 1].first) - k < eps)head[x]++;
							ll b = Q[x][head[x]].second - k * Q[x][head[x]].first;
							ll dpi = b + A * p * p + B * p + C;
							ll tx = q, ty = dpi + A * q * q - B * q;
							dp[a[i].id] = {tx, ty};
							if (y == n)
								{
									ans = min(ans, dpi + q);
								}
						}
					else dp[a[i].id] = {0, INF};
				}
			else
				{
					if (dp[a[i].id].second != INF)
						{
							ll	tx = dp[a[i].id].first, ty = dp[a[i].id].second;
							while (head[y] + 1 <= tail[y] && (1.0 * Q[y][tail[y] - 1].second - ty) / (1.0 * Q[y][tail[y] - 1 ].first - tx) - (1.0 * Q[y][tail[y]].second - Q[y][tail[y] - 1].second) / (1.0 * Q[y][tail[y]].first - Q[y][tail[y] - 1].first) < eps)Q[y].pop_back(), tail[y]--;
							while (head[y] <= tail[y] && tx == Q[y].back().first && ty <= Q[y].back().second)Q[y].pop_back(), tail[y]--;
							if (head[y] <= tail[y] && tx == Q[y].back().first && ty >= Q[y].back().second)continue;//重合点不如上一个，不放入
							Q[y].push_back(dp[a[i].id]);
							tail[y]++;//x不能重合的修改
						}
				}
		}
	cout << ans << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
