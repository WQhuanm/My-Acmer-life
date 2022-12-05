#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e6 + 100;
const int M = 1e4 + 100;
int head[M];
int now[M];
int gap[M];
ll ans;
ll num;
ll e = 2e5;
int dep[M];
struct node
{
	ll next, to, w;
} edge[N];

void add(ll u, ll v, ll w)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	edge[num].w = w;
	head[u] = num;

	edge[++num].next = head[v];
	edge[num].to = u;
	edge[num].w = 0;
	head[v] = num;
}

void bfs()
{
	memset(dep, -1, sizeof(dep));
	dep[e] = 0;
	queue<int>q;
	gap[0]++;
	q.push(e);
	while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = head[x]; i; i = edge[i].next)
				{
					int v = edge[i].to;
					if (dep[v] == -1)
						{
							q.push(v);
							dep[v] = dep[x] + 1;
							gap[dep[v]]++;
						}
				}
		}

}

ll dfs(int x, ll sum)
{
	if (x == e)
		{
			ans += sum;
			return sum;
		}
	ll k, res = 0;
	for (int i = now[x]; i && sum; i = edge[i].next)
		{
			now[x] = i;
			int v = edge[i].to;
			ll w = edge[i].w;
			if (dep[v] == dep[x] - 1 && w)
				{
					k = dfs(v, min(w, sum));
					if (!k)continue;
					edge[i].w -= k;
					edge[i ^ 1].w += k;
					res += k;
					sum -= k;
					if (!sum)return res;
				}
		}
	gap[dep[x]]--;
	if (!gap[dep[x]])dep[0] = e + 1;
	dep[x]++;
	gap[dep[x]]++;
	return res;
}
int main()
{
	int t;
	cin >> t;
	int k = 0;
	while (t--)
		{
			//	memset(edge, 0, sizeof(edge));
			memset(head, 0, sizeof(head));
			memset(gap, 0, sizeof(gap));
			num = 1;
			int n, m;
			cin >> n >> m;
			ll u, v, w;
			ll sum = 0;
			ll minn = INF, maxn = -INF;
			for (int i = 1; i <= n; ++i)
				{
					cin >> w >> u >> v;
					sum += w;
					add(0, i, w);
					for (int j = u; j <= v; ++j)add(i, j + n, 1);
					minn = min(minn, n + u), maxn = max(maxn, n + v);
				}
			e = maxn + n + 1;
			for (int i = minn; i <= maxn; ++i)add(i, e, m);
			ans = 0;
			bfs();
			while (dep[0] < e)
				{
					memcpy(now, head, sizeof(head));
					dfs(0, INF);
				}
			//	cout << ans << ' ' << sum << endl;
			if (sum == ans)cout << "Case " << ++k << ": Yes" << endl << endl;
			else cout << "Case " << ++k << ": No" << endl << endl;
		}

	return 0;
}
